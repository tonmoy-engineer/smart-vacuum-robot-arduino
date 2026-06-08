# Smart Vacuum Robot Arduino

Arduino-based robot control code developed for my B.Sc. final year project: **Smart Vacuum Cleaner Bot with Solar PV**.

This project demonstrates an embedded control system for a smart vacuum cleaner robot designed to support automated movement, obstacle handling, and renewable-energy-based operation.

---

## Project Overview

The main objective of this project was to design and implement a smart vacuum cleaner robot using Arduino-based embedded control logic.  
The system was developed as part of my undergraduate thesis project and focused on combining robotics, automation, and renewable energy concepts.

The robot was designed to move automatically, detect obstacles, and support cleaning-related operations using a basic embedded system architecture.

---

## Key Features

- Arduino-based robot control system
- Automated movement control
- Obstacle detection and avoidance logic
- Motor control for robot navigation
- Renewable-energy-supported project concept using Solar PV
- Embedded C/C++ based implementation
- Developed as part of a final year engineering project

---

## Hardware Components

The project concept may include the following components:

- Arduino microcontroller
- DC motors
- Motor driver module
- Ultrasonic sensor/obstacle detection sensor
- Battery power supply
- Solar PV support system
- Robot chassis
- Vacuum cleaning mechanism
- Connecting wires and basic electronic components

---

## Technologies Used

- Arduino
- Embedded C/C++
- Embedded Systems
- Robotics Control
- Sensor-based automation
- Renewable Energy Concept
- Basic Motor Control

---

## Software Logic

The Arduino program controls the robot by reading sensor inputs and sending control signals to the motor driver.  
Based on the obstacle detection condition, the robot can decide whether to move forward, stop, turn, or change direction.

Basic logic flow:

```text
Start
↓
Initialize sensors and motors
↓
Read obstacle sensor data
↓
If an obstacle is detected:
    Stop or change direction
Else:
    Move forward
↓
Repeat continuously
