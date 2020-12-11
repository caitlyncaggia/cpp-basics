#include "mbed.h"
#include "Speaker.h"
#include "PinDetect.h"
DigitalOut myled1(LED1);
DigitalOut myled2(LED2);
DigitalOut myled3(LED3);
DigitalOut myled4(LED4);
PinDetect pb1(p18); //you can use different pins
PinDetect pb2(p19); //you can use different pins
PinDetect pb3(p20); // you can use different pins

// setup instance of new Speaker class, mySpeaker using pin 21
// the pin must be a PWM output pin
Speaker mySpeaker(p21);
//---------------------------------------------------------------------------------------------------
// Callback routine is interrupt activated by a debounced pb1 hit
// That is … this code runs with interrupt is generated by first button press
void pb1_hit_callback (void)
{ myled1 = !myled1;
mySpeaker.PlayNote(200.0,0.25,0.1);
}
//---------------------------------------------------------------------------------------------------
// Callback routine is interrupt activated by a debounced pb2 hit
// That is … this code runs with interrupt is generated by second button press
void pb2_hit_callback (void)
{ myled2 = !myled2;
 mySpeaker.PlayNote(400.0,0.25,0.1);
}
//---------------------------------------------------------------------------------------------------
// Callback routine is interrupt activated by a debounced pb3 hit
// That is … this code runs with interrupt is generated by third button press
void pb3_hit_callback (void)
{ myled3 = !myled3;
mySpeaker.PlayNote(800.0,0.25,0.1);
}
//---------------------------------------------------------------------------------------------------
int main()
{
//setup push buttons
 pb1.mode(PullUp);
 pb2.mode(PullUp);
 pb3.mode(PullUp);
 // Delay for initial pullup to take effect
 wait(.01);
 // Setup Interrupt callback functions for a pb hit
 pb1.attach_deasserted(&pb1_hit_callback);
 pb2.attach_deasserted(&pb2_hit_callback);
 pb3.attach_deasserted(&pb3_hit_callback);
 // Start sampling pb inputs using interrupts
 pb1.setSampleFrequency();
 pb2.setSampleFrequency();
 pb3.setSampleFrequency();
// pushbuttons now setup and running
 while(1)
 {
 myled4 = !myled4;
 wait(0.5);
 }
} //end main