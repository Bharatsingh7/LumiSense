# LumiSense: Smart Home Air Quality & Gas Monitor

> **Breathe easy. See your air quality in real-time.**

LumiSense is a sleek, Arduino-based home gadget designed to keep your living space comfortable and safe. It continuously monitors your indoor air quality, providing beautiful, ambient visual feedback so you always know what you are breathing. As an added layer of security, LumiSense features an active gas leak detection system that instantly alerts you to dangerous levels of LPG or combustible gases.

## 🌟 Features
* **Ambient Air Quality Monitoring:** Continuously tracks indoor air conditions using an onboard MQ-9 sensor.
* **Dynamic Visual Interface:** The NeoPixel LED strip acts as an ambient display, seamlessly shifting its color gradient from Green (optimal air) to Yellow/Orange as air quality changes.
* **Emergency Gas Leak Detection:** Automatically switches from ambient monitoring to a critical alert state if high concentrations of LPG or other dangerous gases are detected.
* **Audio-Visual Alarm System:** Flashes a high-intensity red strobe and triggers an active buzzer during a severe gas leak.
* **Auto-Calibration Mode:** Easily tune the `safeLevel` and `alarmLevel` thresholds to match the baseline air quality of your specific home environment.

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
| | A0 (Analog Out) | **A0** | Sends analog air/gas readings |
| **NeoPixel Strip**| 5V / VCC | 5V | Best practice: Use an external 5V supply if using a longer strip. |
| | GND | GND | Ground |
| | DIN (Data In) | **D2** | Data signal for the ambient LEDs. |
| **Buzzer** | Positive (+) | **D8** | Drives the alarm tone |
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
        MQ9[MQ-9 Air/Gas Sensor]
        NEO[NeoPixel LED Strip]
        BUZ[Active Buzzer]
    end

    5V -->|Power| MQ9
    5V -->|Power| NEO
    GND -->|Ground| MQ9
    GND -->|Ground| NEO
    GND -->|Ground| BUZ
    
    MQ9 -->|Air Quality Data| A0
    D2 -->|Ambient LED Control| NEO
    D8 -->|Alarm Signal| BUZ
