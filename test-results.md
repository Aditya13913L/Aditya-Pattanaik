# Test Results — Digital Doorbell System V2

**Tester:** Aditya Pattanaik  
**Date:**  19/10/2026
**Tinkercad link:** https://www.tinkercad.com/things/dbNoHVPNeGR-adi?sharecode=AX6534NSrLmmZdqNCqtg3WPb2IY8hHq8OaZGMd9twXQ

**Each test is runned properly and checked and all the test results are displayed here after testing the simulation by myself.

| ID | Test | Expected result | Actual result / evidence | Status |
|---|---|---|---|---|
| T01 | Start simulation | LCD displayed DIGITAL DOORBELL and VISITORS: 0. Serial Monitor showed the ready message | Test Passed.
| T02 | Press once | Visitor count increased from 0 to 1. LED turned on and buzzer played the melody | Test Passed.
| T03 | Press again after melody ends | Visitor count increased from 1 to 2 and the melody played again | Test Passed.
| T04 | Release button | Visitor count remained unchanged when the button was released | Test Passed.
| T05 | Press during melody | Visitor count increased, but the current melody does not restart | Test Passed.
| T06 | Wait for melody to finish | Buzzer stopped and the LED turned off after the three tones | Test Passed.
| T07 | Press several distinct times | Each separate, detected button press increased the count by one | Test Passed.
| T08 | Compare LCD and Serial Monitor | Both displayed the same visitor count | Test Passed.
| T09 | Restart simulation | Visitor count returned to 0 after restarting the arduino | Test passed.

## Screenshots to capture
Screenshots are attached with the project file please check it in the media folder...

**Summary:** Tests passed: 9
             Failed: 0
             Not run: 0

**Conclusion:** All the components including the LED, buzzer, push button, LCD are all working properly without any problems.
                All the connections made to the breadboard from the Arduino with the LED, buzzer, push button, LCD are correct as all the tests are passed.
                For further checks the source code of the this simulation is included in the DOORBELL project file so please check it.
