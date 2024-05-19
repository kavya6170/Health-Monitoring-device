 #include<Wire.h>

int ADXL345=0x53;
int c;
int X_out,Y_out,Z_out;
const int buzzer=7;

//const int tempPin = A3;


void setup(){
  Serial.begin(9600);
  Wire.begin();

  Wire.beginTransmission(ADXL345);
  Wire.write(0x2D);

  Wire.write(8);
  Wire.endTransmission();
  delay(10);

  pinMode(buzzer, OUTPUT);
}

void loop(){
  Wire.beginTransmission(ADXL345);
  Wire.write(0x32);
  Wire.endTransmission(false);
  Wire.requestFrom(ADXL345,6,true);

  X_out=(Wire.read() | Wire.read()<<8);
  Y_out=(Wire.read() | Wire.read()<<8);
  Z_out=(Wire.read() | Wire.read()<<8);

//  int tempReading = analogRead(tempPin);
//  float voltage = tempReading * (5.0 / 1023.0);
//  float temperature = voltage * 100;
//  Serial.println(temperature);
//  delay(2000);

  Serial.print("X=");
  Serial.print(X_out);
  Serial.print(" Y=");
  Serial.print(Y_out);
  Serial.print(" Z=");
  Serial.println(Z_out);
  delay(1000);

  if(X_out<-80 || X_out>80 , Y_out< -80 || Y_out>120){
    Serial.println("Patient is falling");
    digitalWrite(buzzer, HIGH);
  delay(5000);
  digitalWrite(buzzer, LOW);
  delay(1000);
  }
}