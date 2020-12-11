#include "mbed.h"
#include "PinDetect.h"
#include "uLCD_4DGL.h"
#include "SDFileSystem.h"
#include "temperature.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>

SDFileSystem sd(p5, p6, p7, p8, "sd");
uLCD_4DGL uLCD(p28, p27, p29); // create a global lcd object
//declare objects for pins used with pushbuttons
PinDetect pb1(p18);
PinDetect pb2(p19);
PinDetect pb3(p20);
char currentLetter = 'Z';


//function prototypes
void displayConversion(char, char);
void displayCurrent(char);


// Callback routine is interrupt activated by a debounced pb3 hit
void pb3_hit_callback (void)
{
    //get position
    int count;
    FILE *fp = fopen("/sd/positionCipherSender.txt", "r");
    if(fp == NULL) {
        uLCD.printf("Fail SR!!!\n");
    } else {
        fscanf(fp, "%i", &count);
        fclose(fp);
    }
    int next = count+1;
    FILE *fp2 = fopen("/sd/positionCipherSender.txt", "w");
    if (fp2 == NULL) {
        uLCD.printf("Fail SW!!\n");
    }
    else {
        fprintf(fp2, "%i", next); // updates the sender file
        fclose(fp2);
    }
    
    //get key
    char keyArray[1001];
    FILE *fp3 = fopen("/sd/OTP.txt", "r");
    if(fp3 == NULL) {
        uLCD.printf("Fail OTP!!!\n");
    } else {
        fscanf(fp3, "%s", keyArray);
        fclose(fp3);
    }
        
    //encode letter
    int currentNum = ::currentLetter - 65; //subtract 65 to convert from ascii to position in alphabet
    char keyLetter = keyArray[count];
    int factor = keyLetter - 65; 
    int newNum = ((currentNum + factor) % 26) + 65;
    char encoded = newNum;
    
    //refresh screen
    displayConversion(::currentLetter, encoded);  
}

// Callback routine is interrupt activated by a debounced pb1 hit
void pb1_hit_callback (void) 
{
    if (::currentLetter == 'Z')
    {
        ::currentLetter = 'A';
        uLCD.cls();
        displayCurrent(::currentLetter);
    }
    else
    {
        ::currentLetter++;
        uLCD.cls();
        displayCurrent(::currentLetter);
    }
}

// Callback routine is interrupt activated by a debounced pb2 hit
void pb2_hit_callback (void)
{
    if (::currentLetter == 'A')
    {
        ::currentLetter = 'Z';
        uLCD.cls();
        displayCurrent(::currentLetter);
    }
    else
    {
        ::currentLetter--;
        uLCD.cls();
        displayCurrent(::currentLetter);
    }
}

//global functions
void displayConversion(char c, char n)
{
    uLCD.locate(0,0);
    uLCD.text_width(5);
    uLCD.text_height(5);
    uLCD.printf("%c\n%c",c, n);
}

void displayCurrent(char c)
{
    uLCD.locate(0,0);
    uLCD.text_width(5);
    uLCD.text_height(5);
    uLCD.printf("%c\n",c);
}


int main() {
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
 pb1.setSampleFrequency(); //default is 20KHz sampling
 pb2.setSampleFrequency();
 pb3.setSampleFrequency();
 // pushbuttons now setup and running

 }
