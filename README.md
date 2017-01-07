# Raspberry Pi experiment

A small experiment with the Raspberry Pi 3 based on the 
[tux crossing](https://projects.drogon.net/raspberry-pi/gpio-examples/tux-crossing/).
Written in C++ and fairly rudimentary (some fugly procedural statements 
where used), it's all experimental.

### Wiring

- Green LED on GPIO 1
- Green LED on GPIO 7
- Yellow LED on GPIO 2
- Red LED on GPIO 0
- Red LED on GPIO 4
  
- Button on GPIO 21
- Button on GPIO 30
  
### Summary

- The program will exit when the button on GPIO 21 is pressed (and the 
program is not in "pedestrian walk mode"). 
- The "pedestrian walk mode" will initiate when the button on GPIO
30 is pressed (for longer than 100ms).