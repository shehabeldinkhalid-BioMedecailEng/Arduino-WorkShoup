# Arduino Workshop 🔌

A collection of hands-on Arduino Uno exercises built and simulated in **Tinkercad**, covering digital/analog I/O, sensors, actuators, sound, and transistor-based signal amplification. Each project pairs a circuit schematic (Tinkercad export) with its corresponding sketch (`.ino`).

## 📋 Table of Contents

| # | Project | Concepts |
|---|---------|----------|
| 1 | [Traffic Light Simulation](#1-traffic-light-simulation) | Digital output, timing with `delay()` |
| 2 | [Tone & Buzzer Keyboard](#2-tone--buzzer-keyboard) | `tone()`, push-buttons, arrays |
| 3 | [BJT Signal Amplifier](#3-bjt-signal-amplifier) | Transistor switching, digital-to-power interfacing |
| 4 | [Amplifying a Digital Signal (Relay)](#4-amplifying-a-digital-signal-relay) | Relays, custom blink function, pulse control |
| 5 | [Fire & Smoke Detector](#5-fire--smoke-detector) | Gas/temperature sensing, RGB LED, buzzer alarm |
| 6 | [4x4 Keypad + 7-Segment Display](#6-4x4-keypad--7-segment-display) | Keypad matrix scanning, 7-segment decoding |
| 7 | [DC Motor Driver](#7-dc-motor-driver) | Transistor motor control from a digital pin |
| 8 | [Servo Motor Control](#8-servo-motor-control) | Potentiometer input, `Servo` library, `map()` |
| 9 | [Signal Calibration & Mapping](#9-signal-calibration--mapping) | `map()`, `constrain()`, Serial input, sound feedback |
| 10 | [Joystick Module Test](#10-joystick-module-test) | Analog joystick (X/Y/switch) reading |
| 11 | [Blink + Tone Training Sketch](#11-blink--tone-training-sketch) | Combining digital output with `tone()` |
| 12 | [Master + Slave + Led + Potentimeter](#SPI-Test) | Combining digital output with `<SPI.h>` |


---

### 1. Traffic Light Simulation
**Files:** `task_1.pdf`, `task_11.ino`
A basic traffic-light controller using three LEDs (red, yellow, green) with current-limiting resistors. The sketch cycles the lights through a realistic timed sequence (long red/green phases, short yellow transitions) using `digitalWrite()` and `delay()`.

### 2. Tone & Buzzer Keyboard
**Files:** `tone_and_buzzer_sound.pdf`, `tone_and_buzzer_sound1.ino`
A simple 6-key piezo "piano." Six push-buttons (using `INPUT_PULLUP`) are each mapped to a musical note frequency (C, D, E, F, G, A), and pressing one plays the corresponding tone on a piezo buzzer via `tone()`.

### 3. BJT Signal Amplifier
**Files:** `AMP_BJT_.pdf`, `amp_bjt_1.ino`
Demonstrates using an NPN transistor as a switch/amplifier to drive a load (LED) from a separate 9V supply, controlled by a low-current digital pin on the Arduino. Shows how a microcontroller pin can safely switch higher-power loads it can't drive directly.
### 4. Amplifying a Digital Signal (Relay)
**Files:** `Amp_of_Dig_Signjal.pdf`, `amp_of_dig_signjal1.ino`
Uses a relay module and a potentiometer/function-generator input to switch a separate circuit on and off. The sketch defines a reusable `Blink(pin, duration, count)` function to generate configurable pulse trains at varying speeds.

<img width="1362" height="823" alt="Capture2" src="https://github.com/user-attachments/assets/d31adfa3-766d-4578-80a4-abe56245ddcc" />


<img width="1273" height="819" alt="Capture4" src="https://github.com/user-attachments/assets/1747eb4d-cb83-40b6-b85a-1333fecc04e4" />

### 5. Fire & Smoke Detector
**Files:** `Fire_and_smoke.pdf`, `fire_and_smoke1.ino`
A safety-monitoring system combining a gas sensor and a temperature sensor. An RGB LED gives visual status (green = safe, blue = gas detected, red = high temperature, purple = both), and a buzzer sounds different alert tones depending on the condition detected.

<img width="938" height="857" alt="Capture5" src="https://github.com/user-attachments/assets/91dd9376-35ed-42b6-8917-6ea02a0baf71" />

### 6. 4x4 Keypad + 7-Segment Display
**Files:** `KP.pdf`, `kp1.ino`
Reads digits 1–9 from a matrix keypad (via the `Keypad` library) and drives a 7-segment display to show the pressed digit, using a lookup table that maps each digit to its segment on/off pattern.

<img width="990" height="737" alt="Capture6" src="https://github.com/user-attachments/assets/5f57117c-1ffd-4f53-9e1d-8f543a6868a8" />

### 7. DC Motor Driver
**Files:** `Motor_Work.pdf`, `motor_work1.ino`
A DC motor is switched on and off through an NPN transistor (since the Arduino pin alone can't supply enough current), powered by a separate 9V battery. The sketch toggles the control pin on a 1-second interval to turn the motor on and off repeatedly.



https://github.com/user-attachments/assets/9d50b2b8-04c2-470c-ac6e-85d4b597b31c



### 8. Servo Motor Control
**Files:** `servo_motor1.ino`
A potentiometer on `A0` is read and mapped from its 0–1023 analog range to a 0–180° servo angle using `map()`, letting the servo position be controlled live by turning the knob.


https://github.com/user-attachments/assets/aefc1564-ea0f-415d-9b4d-dc7ce4ae54ec



https://github.com/user-attachments/assets/0d7ee465-924b-40f0-84f3-ea8a59a6e8b6


### 9. Signal Calibration & Mapping
**Files:** `معايره (Calibration).pdf`, `map_and_constrain1.ino`
An analog input signal is calibrated against a user-entered reference value (read via `Serial.parseInt()`), then converted into an audible frequency using `map()` and `constrain()`, with the result played on a piezo buzzer and logged over Serial for debugging.


<img width="710" height="743" alt="Capture7" src="https://github.com/user-attachments/assets/1689d9bb-df36-4d42-ad0d-e807dacca718" />

<img width="466" height="830" alt="Capture3" src="https://github.com/user-attachments/assets/a2b75bbc-f43d-4423-b87f-28853b67aa9d" />


### 10. Joystick Module Test
**Files:** `fabulous_hango1.ino`
Reads the X and Y axes plus the push-button of an analog joystick module, converts the raw analog readings into a normalized position range (–10 to 10), and prints everything to the Serial Monitor — a foundational test sketch for joystick-controlled projects.

### 11. Blink + Tone Training Sketch

**Files:** `training_21.ino`
An introductory exercise combining two outputs: an LED that alternates with a buzzer tone, used to practice coordinating multiple `digitalWrite()`/`tone()` calls on different pins within a single loop.

<img width="1393" height="646" alt="Capture9" src="https://github.com/user-attachments/assets/db2f2778-a8c8-42ac-b9e4-7f504ac6f2da" />

---

## 🛠 Hardware Used
- Arduino Uno
- LEDs (red, yellow, green, RGB) + resistors
- Piezo buzzer
- Push-buttons / 4x4 matrix keypad
- Potentiometer / analog joystick module
- Servo motor
- DC motor + NPN transistor (BJT)
- Relay module
- Gas sensor (MQ-series) + temperature sensor
- 7-segment display

## 🧰 Tools
- [Arduino IDE](https://www.arduino.cc/en/software) for writing/uploading sketches
- [Tinkercad Circuits](https://www.tinkercad.com/) for circuit design and simulation

## 📁 Repository Structure
```
├── task_1.pdf                  # Traffic light schematic
├── task_11.ino
├── tone_and_buzzer_sound.pdf   # Buzzer keyboard schematic
├── tone_and_buzzer_sound1.ino
├── AMP_BJT_.pdf                # BJT amplifier schematic
├── amp_bjt_1.ino
├── Amp_of_Dig_Signjal.pdf      # Relay/digital signal amp schematic
├── amp_of_dig_signjal1.ino
├── Fire_and_smoke.pdf          # Fire & smoke detector schematic
├── fire_and_smoke1.ino
├── KP.pdf                      # Keypad + 7-segment schematic
├── kp1.ino
├── Motor_Work.pdf              # DC motor driver schematic
├── motor_work1.ino
├── servo_motor1.ino            # Servo control sketch
├── معايره (Calibration).pdf    # Signal calibration schematic
├── map_and_constrain1.ino
├── fabulous_hango1.ino         # Joystick test sketch
└── training_21.ino             # Blink + tone practice sketch
```

<img width="1650" height="1275" alt="AMP BJT  (1)_merged_pages-to-jpg-0010" src="https://github.com/user-attachments/assets/949f4dcc-ae38-48c9-9a43-3b72c880a847" />
<img width="1650" height="1275" alt="AMP BJT  (1)_merged_pages-to-jpg-0009" src="https://github.com/user-attachments/assets/9da47e89-3927-40bb-83f7-8901cd33977f" />
<img width="1650" height="1275" alt="AMP BJT  (1)_merged_pages-to-jpg-0008" src="https://github.com/user-attachments/assets/6f2d76a5-0a9f-44b6-8804-beb66dc22512" />
<img width="1650" height="1275" alt="AMP BJT  (1)_merged_pages-to-jpg-0007" src="https://github.com/user-attachments/assets/70f1d2f4-0b2e-4d7a-9e82-5e1fa45bab54" />
<img width="1650" height="1275" alt="AMP BJT  (1)_merged_pages-to-jpg-0006" src="https://github.com/user-attachments/assets/96f215f4-10b6-42b7-8279-ee3b0f42f951" />
<img width="1650" height="1275" alt="AMP BJT  (1)_merged_pages-to-jpg-0005" src="https://github.com/user-attachments/assets/4c79db46-80ef-4439-8100-e441f91bacea" />
<img width="1650" height="1275" alt="AMP BJT  (1)_merged_pages-to-jpg-0004" src="https://github.com/user-attachments/assets/f95ec08d-e605-4159-8128-2386afc21967" />
<img width="1650" height="1275" alt="AMP BJT  (1)_merged_pages-to-jpg-0003" src="https://github.com/user-attachments/assets/e13896ce-f470-4267-955b-cc17c343935c" />
<img width="1650" height="1275" alt="AMP BJT  (1)_merged_pages-to-jpg-0002" src="https://github.com/user-attachments/assets/1d0e1813-a309-4fa3-9fae-1b06108af440" />
<img width="1650" height="1275" alt="AMP BJT  (1)_merged_pages-to-jpg-0001" src="https://github.com/user-attachments/assets/3d4ac51f-29f2-490d-91d3-45cecd7ec9da" />


## ▶️ How to Run
1. Open the desired `.ino` file in the Arduino IDE.
2. Wire the circuit as shown in the matching schematic PDF (or recreate it in Tinkercad).
3. Install any required libraries (`Servo`, `Keypad`) via **Sketch → Include Library → Manage Libraries**.
4. Select your board/port and click **Upload**.
