# Digital Doorbell System V2

An Arduino Uno doorbell simulation built in Tinkercad Circuits. A button press increments a visitor counter, updates a 16×2 LCD and the Serial Monitor, and starts a three-tone piezo melody with an LED indicator. The melody is **non-blocking**, so the program continues checking the button while the tones play.

## Features
- Push-button input using 'INPUT_PULLUP'
- 50 ms software debounce
- Non-blocking melody using 'millis()'
- LED indicator during the melody
- LCD visitor counter
- Serial Monitor count at 9600 baud
- Presses during a melody are counted, but do not restart the melody

## Components
| Component | Quantity | Purpose |
|---|---:|---|
| Arduino Uno R3 | 1 | Main controller |
| Tinkercad-supported 16×2 LCD | 1 | Visitor count display |
| Push button | 1 | Visitor input |
| Piezo buzzer | 1 | Audible melody |
| LED | 1 | Visual indicator |
| 220 Ω resistor | 1 | Limits LED current |
| Breadboard and jumper wires | As needed | Connections |

## Connections
| Component | Arduino connection |
|---|---|
| Push button | D2 and GND |
| Buzzer (+) | D8 |
| Buzzer (−) | GND |
| LED anode (+) | D13 through 220 Ω resistor |
| LED cathode (−) | GND |
| LCD | SDA to SDA and SCL to SCL| (Connections screenshots are attached with the project).

## How it works
1. The Arduino initializes the pins, Serial Monitor at 9600 baud, and LCD.
2. The button uses 'INPUT_PULLUP': released is HIGH and pressed is LOW.
3. A 50 ms debounce interval helps filter button bounce.
4. A new press increments the visitor count and updates the LCD and Serial Monitor.
5. The buzzer plays 300 Hz for 250 ms, 400 Hz for 350 ms, and 500 Hz for 250 ms.
6. 'millis()' advances the melody without using 'delay()', allowing button scanning during playback.

## Simulation and evidence
- **Tinkercad link:** https://www.tinkercad.com/things/dbNoHVPNeGR-adi?sharecode=AX6534NSrLmmZdqNCqtg3WPb2IY8hHq8OaZGMd9twXQ
- For LED, LCD, Buzzer, Button and Arduino r3 board used in the project, the mages are attached with the project please check it.

## Files
- Complete Circuit image.png 
- LED, button and buzzer used.png
- LCD used in simulation.png
- Arduino r3 used in simulation.png
- Simulation video.mp4
- **Note:** All these files have been attached in the project so please check those to get a better view of the project.

## Limitations
- The visitor count resets when the Arduino restarts because it is stored in RAM.
- A press during melody playback is counted, but the melody does not restart.
- Very brief presses may not be detected if they do not satisfy the debounce logic.
- This is a simulation prototype, not a certified real-world door-entry system.

## Author
- Name: Aditya Pattanaik
- Course: IOT & Robotics @UNLOX
- Institution: BJB Autonomous College
- Submission date: 19/10/2026
