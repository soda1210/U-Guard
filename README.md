# U-Guard

U-Guard Smart Bike Meter is an intelligent device designed for electric-assisted bicycles. It features automatic locking and unlocking, adjusts the state based on the distance between the user and the vehicle, and provides vehicle locating and anti-theft warning functions.

U-Guard 智能車錶是一個為電力輔助自行車設計的智能設備。它具備自動上鎖和解鎖功能，並能根據使用者與車輛之間的距離進行狀態切換，同時提供尋車和防盜警告功能。

## Description

The U-Guard Smart Bike Meter project aims to enhance the safety and convenience of electric-assisted bicycles. Using NodeMCU32s control module and UWB technology, it enables bidirectional communication and precise distance measurement with the bicycle. Users can enjoy the following features:

- **Automatic Locking and Unlocking**: Automatically locks or unlocks the vehicle as the user approaches or moves away, without manual operation.
- **Assist Power Output Control**: Dynamically adjusts electric assist output according to user needs, enhancing riding experience.
- **Vehicle Locating**: Displays the distance between the vehicle and user on the display and enables the vehicle to emit sound for quick retrieval.
- **Anti-Theft Warning**: Issues sound alerts and notifies the user in case of abnormal vehicle movement, providing real-time theft prevention alerts.

The main hardware components of this project include NodeMCU32s, UWB module, buzzer, and 1.54-inch e-Paper display module, collectively forming a powerful and user-friendly smart bike meter system.

## Features

- **Automatic Locking and Unlocking**: Automatically controls the bike lock as the user approaches or moves away.
- **Assist Power Output Control**: Adjusts electric assist output based on user preferences.
- **Vehicle Locating**: Displays vehicle distance and emits sound for easy retrieval.
- **Anti-Theft Warning**: Alerts and notifies the user when the vehicle is moved.

## Hardware

- **NodeMCU32s**: Primary control module.
- **UWB**: Bidirectional communication module for calculating orientation and distance.
- **Buzzer**: Provides audible alerts.
- **1.54-inch e-Paper Module Rev2.1**: Display module.

## Installation

1. Clone this repository:
   ```bash
   git clone https://github.com/yourusername/U-Guard.git
   cd U-Guard