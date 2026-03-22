# Arduino-Password-Security-System
Password-based access control system using Arduino,I2C LCD, and LED indicators
# 🔐 Arduino Password Security System

## 📌 Overview

This project implements a password-based access control system using Arduino and an I2C LCD display. It provides secure authentication with a lockout mechanism after multiple failed attempts.

## ⚙️ Components Used

* Arduino UNO
* I2C LCD (16x2)
* LED
* Jumper wires
* Breadboard

## 🔧 Working Principle

The system reads user input from the Serial Monitor and compares it with a predefined password. If the password matches, access is granted. Otherwise, access is denied.

A security feature limits the number of attempts to 3. After 3 incorrect attempts, the system locks temporarily.

## 🔒 Features

* Password authentication
* LED status indication
* 3-attempt security lockout
* Auto reset after delay

## 📊 Output Example

Access Granted
Access Denied
System Locked

## 🧠 Concepts Used

* Embedded C programming
* Conditional logic (if-else)
* Loop control
* Serial communication
* I2C interfacing

## 🚀 Future Improvements

* Replace Serial input with keypad
* Add EEPROM for password storage
* Add buzzer alert system
