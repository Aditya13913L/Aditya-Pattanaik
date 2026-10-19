# Components and Connections

## Parts
- Arduino Uno R3
- Tinkercad-supported 16×2 LCD
- Push button
- Piezo buzzer
- LED and 220 Ω resistor
- Breadboard and jumper wires

## Connections
- Button: D2 to button; other side to GND. `INPUT_PULLUP` means pressed = LOW.
- Buzzer positive: Connected to D8; negative: Connected to GND.
- LED anode: Connected to D13 through a 220 Ω resistor; cathode: GND.
- LCD: use the wiring in such a manner as GND - GND, VCC - 5V, SDA - SDA, SCL - SCL;
- For more information about the components and connections please check the screenshots attached in the project file.

## Melody
- 300 Hz for 250 ms
- 400 Hz for 350 ms
- 500 Hz for 250 ms