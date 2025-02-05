# Automatic Drunken Driver Detecting System for Autonomous Vehicles

## Overview
This project aims to improve road safety by preventing drunk driving. The system uses an alcohol sensor to detect alcohol levels in the driver’s breath and automatically disables the vehicle’s ignition if the detected level exceeds a threshold. Additionally, it integrates IoT capabilities to notify authorities or family members in case of a violation.

## Features
- **Alcohol Detection**: Uses the MQ-3 alcohol sensor to monitor the driver’s breath.
- **Ignition Control**: Prevents the vehicle from starting if alcohol is detected.
- **IoT Connectivity**: Sends alerts to a mobile app via Blynk.
- **Real-Time Monitoring**: Displays system status on an LCD screen.
- **Mobile Alerts**: Sends notifications to registered users in case of detection.
- **Emergency Override**: Includes a manual override for emergency situations.

## Components Used
- **Microcontroller**: NodeMCU (ESP8266/ESP32)
- **Alcohol Sensor**: MQ-3 sensor
- **Relay Module**: Controls the ignition system
- **LCD Display**: Shows system status
- **Buzzer**: Alerts driver upon alcohol detection
- **Mobile App**: Blynk-based remote monitoring

## Software Requirements
- **Arduino IDE** (for programming the NodeMCU)
- **Blynk IoT Platform** (for remote monitoring and notifications)
- **Embedded C** (for firmware development)

## Setup & Usage
1. **Hardware Setup**: Connect all components as per the circuit diagram.
2. **Software Installation**: Install the necessary libraries in the Arduino IDE.
3. **Code Upload**: Flash the NodeMCU with the provided firmware.
4. **Testing**: Verify alcohol detection and ignition control functionality.
5. **Blynk Integration**: Set up the Blynk app to receive alerts.

## Future Enhancements
- Integration with GPS to send location-based alerts.
- Addition of voice alerts for driver warnings.
- Cloud-based data logging for law enforcement use.

## Contribution
Feel free to submit issues or pull requests to improve the system.

## License
This project is licensed under the MIT License.

