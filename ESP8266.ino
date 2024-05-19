#define BLYNK_TEMPLATE_ID "TMPL399H_pgNW"
#define BLYNK_TEMPLATE_NAME "Health monitoring for paralyzed patient"
#define BLYNK_AUTH_TOKEN "LcgNH0aa1pLzloMwDDn-PD0oF3aIN49_"
#include<BlynkSimpleEsp8266.h>
#include <Wire.h>
char ssid[]="Kshiti G";
char password[]="kshiti3002";
char auth[]="LcgNH0aa1pLzloMwDDn-PD0oF3aIN49_";
#include<SoftwareSerial.h>
#include <DHT.h>
#define PIN 2
#define TYPE DHT11
#include <LiquidCrystal_I2C.h>
LiquidCrystal_I2C lcd(0x27,16,2); 
DHT dht(PIN,TYPE);
int _timeout;
int threshold = 550;
const int touchSensorPin2 = 14;
const int touchSensorPin3 = 12;
const int touchSensorPin4 = 13;
//const int touchSensorPin5 = 15;
const int buzzer=16;
const int pulsePin = A0;  // Pulse sensor analog pin
int pulseValue;
int bpm;

void  setup()
{
  Serial.begin(9600);

  WiFi.begin(ssid,password);
  while(WiFi.status()!=WL_CONNECTED){
    delay(1000);
    Serial.println("connecting to wifi");
  }
  Serial.println("connected to wifi");
  Blynk.begin(auth,ssid,password);
  

  pinMode(touchSensorPin2, INPUT);
  pinMode(touchSensorPin3, INPUT);
  pinMode(touchSensorPin4, INPUT);
//  pinMode(touchSensorPin5, INPUT);
  pinMode(buzzer, OUTPUT);

  pinMode(pulsePin, INPUT);

  dht.begin();
  lcd.begin(16,2);
  lcd.init();                       
 lcd.backlight();
 lcd.clear();
 
}

void loop()
{
  touch();
  temp();
  BPM();
  accelerometer();
}

  void touch(){
  int touchState2 = digitalRead(touchSensorPin2);
  int touchState3 = digitalRead(touchSensorPin3);
  int touchState4 = digitalRead(touchSensorPin4);
  //int touchState5 = digitalRead(touchSensorPin5);


 if (touchState2 == HIGH)
 {
  Blynk.logEvent("food_and_water");
  lcd.println ("I need food");
  delay(500);
  lcd.clear();
 
 }

 if (touchState3 == HIGH)
 {
  //lcd.println("I need Water");
  delay(500);
  lcd.clear();
 }

 if (touchState4 == HIGH)
 {
  lcd.println("washroom");
  delay(500);
  lcd.clear();
  Blynk.logEvent("washroom");
 }

 if (touchState5 == HIGH)
 {
  digitalWrite(buzzer, HIGH);
  delay(5000);
  digitalWrite(buzzer, LOW);
  delay(1000);
  lcd.println("Emergency");
  delay(500);
  lcd.clear();
  Blynk.logEvent("emergency");
 }
}

  void temp(){
  float t= dht.readTemperature();
  long temp= t*(9/5)+71.5;
  Serial.print("Temperature: ");
  Serial.print(temp);
  Serial.print("\n");
  lcd.print("Temperature:");
  lcd.print(temp);
  delay(2000);
  lcd.clear();
  Blynk.virtualWrite(V0,temp);
}
 void BPM(){
  pulseValue=analogRead(pulsePin);

  if(pulseValue>600){
     bpm=60000/pulseValue;
     Serial.print("HEART RATE:");
     Serial.print(bpm);
     Serial.println("BPM");
     lcd.print("BPM: ");
     lcd.println(bpm);
     delay(1000);
     lcd.clear();
    Blynk.virtualWrite(V1,bpm);
    String message="Heart rate:"+String(bpm)+"BPM";
  }
 }


void accelerometer(){
 if(Serial.available()>0){
  String data=Serial.readStringUntil('\n');
  String val=Serial.readStringUntil('\n');
  Serial.println(data);
  //lcd.println(data);
  delay(1000);
  lcd.clear();
 }
}