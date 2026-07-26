# 🎮 Pixel Runner

https://github.com/user-attachments/assets/967b7514-a33b-42ca-a3e1-172d2bff10ed

**Pixel Runner** is a retro-style endless runner game built for Arduino and other microcontroller platforms. It runs on a **16×2 LCD display** and is controlled using a **joystick module**.

The project is developed with **PlatformIO** and written in **C++**, following a modular architecture to keep the source code clean and maintainable.

---

## ✨ Features

* 🎮 Joystick controls
* 🏃 Endless runner gameplay
* ⚡ Multiple difficulty levels
* 📈 Score tracking
* 💀 Game Over screen
* 🎨 Custom LCD characters
* 🧩 Modular code structure

---

## 🛠 Hardware

* Arduino Uno R3
* 16×2 LCD (HD44780 compatible)
* Joystick Module (KY-023 or compatible)
* Jumper wires

---

## 🔌 Wiring

### LCD 16×2

| LCD Pin  | Arduino Pin                  |
| -------- | ---------------------------- |
| RS       | D7                           |
| E        | D6                           |
| D4       | D5                           |
| D5       | D4                           |
| D6       | D3                           |
| D7       | D2                           |
| VSS      | GND                          |
| VDD      | 5V                           |
| RW       | GND                          |
| VO       | 10k Potentiometer (Contrast) |
| A (LED+) | 5V (through a 220Ω resistor) |
| K (LED−) | GND                          |

### Joystick Module

| Joystick Pin | Arduino Pin |
| ------------ | ----------- |
| VRx          | A0          |
| VRy          | A1          |
| VCC          | 5V          |
| GND          | GND         |

> **Note:** If your hardware connections are different, update the pin definitions in the source code accordingly.

---

## 📁 Project Structure

```text
include/
├── characters.h
├── constants.h
├── enum.h
├── functions.h
├── structures.h
└── variables.h

src/
├── characters.cpp
├── functions.cpp
├── main.cpp
└── variables.cpp
```

---

## 🚀 Getting Started

1. Clone the repository:

```bash
git clone https://github.com/plutron/pixel-runner-Arduino.git
```

2. Open the project in **PlatformIO**.
3. Connect your Arduino Uno.
4. Build and upload the project.

---

## 🎮 How to Play

* Select the game speed.
* Move the joystick to control the player.
* Avoid incoming obstacles.
* Survive as long as possible and achieve the highest score.

---

## 🤝 Contributing

Contributions, suggestions, and bug reports are welcome. Feel free to open an issue or submit a pull request.

---

## 📄 License

This project is licensed under the **MIT License**.

---

Made with ❤️ using **Arduino**, **PlatformIO**, and **C++**.
