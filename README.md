# Health Monitoring Device for Paralysis Patients

An IoT-based real-time health monitoring system designed specifically for paralysis patients to track vital health parameters and ensure timely medical intervention.

## 🎯 Project Overview

This system provides continuous monitoring of health parameters for paralysis patients, enabling caregivers and medical professionals to track patient conditions remotely. The device collects real-time data from various sensors and can be integrated with cloud platforms for data storage and analysis [web:2][web:12].

## ✨ Features

- **Real-time Health Monitoring**: Continuous tracking of vital signs including heart rate, body temperature, and other health parameters
- **IoT Integration**: Cloud-based data storage and remote access capabilities
- **Alert System**: Automated notifications for abnormal health conditions
- **Data Logging**: Historical data storage for medical analysis and tracking patient progress
- **Remote Accessibility**: Healthcare providers can monitor patients from anywhere [web:14][web:15]

## 🛠️ Hardware Components

- Arduino/ESP32 Microcontroller
- Pulse/Heart Rate Sensor
- Temperature Sensor (LM35/DS18B20)
- LCD Display (16x2)
- Wi-Fi Module (ESP8266 or built-in ESP32)
- Power Supply
- Connecting Wires and Breadboard [web:14][web:15]

## 📋 Software Requirements

- Arduino IDE (version 1.8.x or higher)
- Required Libraries:
  - ESP8266WiFi / WiFi (for ESP32)
  - ThingSpeak (or other IoT platform library)
  - LiquidCrystal (for LCD display)
  - OneWire and DallasTemperature (for temperature sensors) [web:12][web:15]

## 🔧 Installation & Setup

### 1. Hardware Setup
Connect the pulse sensor to analog pin A0

Connect temperature sensor to digital pin 4

Connect LCD display to digital pins 2,3,4,5,11,12

Connect ESP8266/ESP32 for Wi-Fi connectivity

Install Arduino IDE
Download and install required libraries through Arduino Library Manager
Clone this repository
git clone https://github.com/kavya6170/Health-Monitoring-device.git

Open the .ino file in Arduino IDE
Configure Wi-Fi credentials and API keys in the code
Upload the code to your microcontroller


### 3. IoT Platform Configuration
- Create an account on ThingSpeak (or preferred IoT platform)
- Create a new channel with required fields
- Generate API keys and update them in the code
- Configure alert settings as needed

## 💻 Usage

1. Power on the device
2. The system will automatically connect to Wi-Fi
3. Sensors will start collecting health data
4. Data will be displayed on LCD and uploaded to cloud platform
5. Access the dashboard through ThingSpeak or mobile app
6. Set up alerts for caregivers and doctors

## 📊 Data Monitored

- Heart Rate (BPM)
- Body Temperature (°C/°F)
- Real-time timestamps
- Patient activity status

## 🔮 Future Enhancements

- Integration with MySQL database for advanced data analytics
- Python-based data visualization dashboard
- Machine learning models for predictive health analysis
- AWS cloud integration for scalable storage
- Mobile application development
- Additional sensors (blood pressure, SpO2, etc.)

## 🤝 Contributing

Contributions are welcome! Please feel free to submit a Pull Request.

## 📧 Contact

**Developer**: Kavya
**GitHub**: [@kavya6170](https://github.com/kavya6170)
**Project Link**: [Health-Monitoring-device](https://github.com/kavya6170/Health-Monitoring-device)

## 📝 License

This project is open source and available under the MIT License.

## 🙏 Acknowledgments

- Jain College of Engineering for academic support
- Healthcare professionals for domain insights
- Open-source community for libraries and tools

---
**Last Updated**: November 2025

