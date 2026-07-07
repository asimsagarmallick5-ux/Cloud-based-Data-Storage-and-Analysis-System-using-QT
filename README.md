# Cloud based Data Storage and Analysis System using QT
A cloud-based flight data analysis and monitoring system built with Qt and C++, featuring JSON data processing, risk assessment through DLL integration, and secure cloud backup functionality.
# Cloud-Based Flight Data Storage and Analysis System Using Qt

## Overview

The Cloud-Based Flight Data Storage and Analysis System is a desktop application developed using C++ and the Qt Framework. The system is designed to load flight log data, analyze critical flight parameters, assess operational risks, and securely back up flight records through a cloud storage simulation module.

The application provides an interactive graphical user interface (GUI) for monitoring flight information and visualizing safety-related metrics. It demonstrates the integration of data processing, desktop application development, risk assessment, DLL integration, and cloud-based storage concepts.

## Features

* Flight log management using JSON files
* Flight data analysis and monitoring
* Risk assessment engine using Dynamic Link Library (DLL)
* Interactive Qt-based graphical dashboard
* Flight status and risk score generation
* Cloud backup simulation with timestamp-based storage
* User-friendly desktop interface
* Modular and scalable architecture

## Technologies Used

* C++
* Qt Framework 6.11.1
* Qt Creator
* MinGW 64-bit Compiler
* JSON Data Storage
* Dynamic Link Library (DLL)
* CMake / qmake
* Git & GitHub

## System Workflow

1. Load flight log data from a JSON file.
2. Parse and extract flight parameters.
3. Send flight parameters to the Safety Analysis DLL.
4. Calculate risk scores and flight status.
5. Display analyzed results in the dashboard.
6. Store backup copies in the cloud storage directory.

## Project Structure

```text
FlightSafetyDashboard/
│
├── main.cpp
├── mainwindow.cpp
├── mainwindow.h
├── mainwindow.ui
│
├── safetyanalysis.h
├── safetyanalysis.cpp
├── libSafetyAnalysis.dll
│
├── flight_log.json
│
├── cloud_storage/
│
└── README.md
```

## Flight Parameters

* Flight ID
* Aircraft Type
* Altitude
* Speed
* Fuel Level
* Vertical Speed
* Risk Score
* Safety Status

## Risk Classification

| Risk Score | Status      |
| ---------- | ----------- |
| 0 – 29     | Low Risk    |
| 30 – 69    | Medium Risk |
| 70 – 100   | High Risk   |

## Cloud Backup

The application includes a cloud backup simulation module that automatically creates timestamped copies of flight log files inside the cloud storage directory for future analysis and record management.

## Future Enhancements

* Azure Cloud Integration
* Real-Time Flight Monitoring
* Database Connectivity
* AI-Based Risk Prediction
* Automated Alert System
* Web Dashboard Integration

## Author

Developed as a Cloud Computing and Qt Application Development project using C++, Qt Framework, JSON Processing, DLL Integration, and Cloud Backup Technologies.
