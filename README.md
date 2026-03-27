# LumiSense: Smart LPG Gas Detector

> **See your air quality in real-time.**

LumiSense is a smart, Arduino-based safety device that monitors the air for Liquefied Petroleum Gas (LPG) and combustible gases using an MQ-9 sensor. It provides real-time visual feedback via a WS2812B (NeoPixel) LED strip and triggers an audible alarm when dangerous gas levels are detected.

## 🌟 Features
* **Real-time Monitoring:** Continuously reads gas levels from the MQ-9 sensor.
* **Dynamic Visual Feedback:** The NeoPixel strip changes color dynamically from Green (safe) to Red (danger) based on the current gas concentration.
* **Critical Alarm System:** Flashes bright red and triggers a buzzer when gas levels exceed the safe threshold.
* **Auto-Calibration Mode:** Easy to tune the `safeLevel` and `alarmLevel` variables via the Arduino Serial Monitor.

## 🛠️ Hardware Requirements
* 1x Arduino Uno (or compatible board)
* 1x MQ-9 Gas Sensor Module
* 1x Adafruit NeoPixel LED Strip (WS2812B) - *Configured for 8 LEDs by default*
* 1x Active Buzzer
* Jumper Wires
* Breadboard (Optional)

## ⚡ Schematic & Wiring Guide

Connect your components to the Arduino as follows:

| Component | Pin / Label | Arduino Pin | Notes |
| :--- | :--- | :--- | :--- |
| **MQ-9 Sensor** | VCC | 5V | Power for the sensor heater |
| | GND | GND | Ground |
| | A0 (Analog Out) | **A0** | Sends analog gas readings |
| **NeoPixel Strip**| 5V / VCC | 5V | Best practice: Use an external 5V supply if using many LEDs. |
| | GND | GND | Ground |
| | DIN (Data In) | **D2** | Data signal for the LEDs. |
| **Buzzer** | Positive (+) | **D8** | Drives the tone |
| | Negative (-) | GND | Ground |

### System Architecture
```mermaid
graph LR
    subgraph Arduino
        5V[5V Power]
        GND[Ground]
        A0[Analog Pin A0]
        D2[Digital Pin 2]
        D8[Digital Pin 8]
    end

    subgraph Sensors & Outputs
        MQ9[MQ-9 Gas Sensor]
        NEO[NeoPixel LED Strip]
        BUZ[Active Buzzer]
    end

    5V -->|Power| MQ9
    5V -->|Power| NEO
    GND -->|Ground| MQ9
    GND -->|Ground| NEO
    GND -->|Ground| BUZ
    
    MQ9 -->|Gas Data| A0
    D2 -->|LED Control| NEO
    D8 -->|Alarm Signal| BUZ
