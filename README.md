# Architecture for Keyboard FW

This repository is intended to create a architecture and simulation for the
keyboard prototype.

## Components:

* Input System
  * Key Interrupt Controller (GPIO)
  * Host inputs from USB
* Event based Application
  * Key Mapper (GPIO -> Key)
  * Key Input Process (Key -> Event)
  * Event Dispatcher (Event(s) -> Event Dispatcher)
  * LED Controller (LED Mode of Operation)
  * USB Programming (A different state?)
* Output System
  * Output to host through USB (Event Dispatcher calls Output(event))
  * LED Blinkers
  
## Components for Simulation

Input and output system can be simulated for the microcontroller.
  
* Input System (Simulated)
  * Key Interrupt Controller (Take GPIO from standard input)
  * Host inputs from USB (Take USB inputs from standard input)

Host can give inputs like Caps Light, 
    
* Output System (Simulated)
  * Output to host (Outputs to standard output)
  * LED Blinkers (Output to standard out of some other application?)
  

## Instructions to run


### Build 

```
cd build
cmake ..
make
```

### Run

```
./kbd-fw
```
