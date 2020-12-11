#include "mbed.h"
#include "PinDetect.h"
#include "uLCD_4DGL.h"
#include "SDFileSystem.h"
#include "temperature.h"
#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <stdlib.h>

SDFileSystem sd(p5, p6, p7, p8, "sd");
uLCD_4DGL uLCD(p28, p27, p29); // create a global lcd object
//declare objects for pins used with pushbuttons
PinDetect pb1(p18);
PinDetect pb2(p19);
PinDetect pb3(p20);

enum InputType {NO, YES, STAY};
enum StateType {START, WAIT, COPY, END};

//initializing
InputType input = STAY;
StateType state = START;

//function prototypes
char* generateKey();
void writeFiles(char*);


// Callback routine is interrupt activated by a debounced pb3 hit
void pb3_hit_callback (void)
{
    input = STAY;
}
// Callback routine is interrupt activated by a debounced pb1 hit
void pb1_hit_callback (void)
{
    input = YES;
}
// Callback routine is interrupt activated by a debounced pb2 hit
void pb2_hit_callback (void)
{
    input = NO;
}

void writeFiles(char* key)
{
    int count = 0;
    FILE *fp = fopen("/sd/Lab4/OTP.txt", "w");
    fprintf(fp, "%s", key);
    fclose(fp);
    FILE *fp2 = fopen("/sd/Lab4/positionCipherSender.txt", "w");
    fprintf(fp2, "%i", count);
    fclose(fp2);
    FILE *fp3 = fopen("/sd/Lab4/positionCipherReceiver.txt", "w");
    fprintf(fp3, "%i", count);
    fclose(fp3);
}

char* generateKey()
{
    char *keyArray = new char[1001];
    srand(time(NULL));
    for (int i = 0; i < 1000; i++) {
        TMP36 myTMP36(p15);
        float temp1 , temp2;
        temp1 = myTMP36.read();
        temp2 = myTMP36.read();
        int thermRandNum = (temp1 - temp2) * 1000 + rand();
        char randchar;
        randchar = thermRandNum %26 + 65;
        keyArray[i] = randchar;
    } //end for loop
    keyArray[1000]='\0';
    //string key = keyArray;
    return(&keyArray[0]);
} //end generateKey


int main()
{
    pb1.mode(PullUp);
    pb2.mode(PullUp);
    pb3.mode(PullUp);
    
    char keyArray[1001];
    srand(time(NULL));
    TMP36 myTMP36(p15);
    for (int i = 0; i < 1000; i++) {
        float temp1 , temp2;
        temp1 = myTMP36.read();
        temp2 = myTMP36.read();
        int thermRandNum = (temp1 - temp2) * 1000 + rand();
        char randchar;
        randchar = thermRandNum %26 + 65;
        keyArray[i] = randchar;
    } //end for loop
    keyArray[1000]='\0';
    int count =0;
    //mkdir("/sd/Lab4", 0777);
    bool keepgoing = true;
    FILE *fp = fopen("/sd/OTP.txt", "w");
    if (fp == NULL)
    { uLCD.printf("error open\n"); }
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


    while(keepgoing) {

        switch(state) {

            case(START):
            {
                    uLCD.printf("Do you want me to create a one-time pad? (Press yes or no.) \n");
                    state = WAIT;
                    break;
            }//end case START

            case (WAIT):
            {
                if (input == YES)
                { 
                    state = COPY;
                    input = STAY;
                }
                else if (input == NO)
                {
                    state = END;
                }
                break;
            } //end case WAIT

            case (COPY):
            {
            //Produce output for this state: create files
                //uLCD.printf("entered copy\n");
                fprintf(fp,"%s", keyArray);
                fclose(fp);
                uLCD.printf("I have created a one-time pad. Do you want to copy it again? (Press yes or no.) \n");
                state = WAIT;
                break;
            } //end case COPY

            case (END):
            {
                uLCD.printf("Goodbye.");
                keepgoing = false;
                break;
            }//end case END

        }//end switch
        wait (0.1);
    } //end while loop
    FILE *fp2 = fopen("/sd/positionCipherSender.txt", "w");
    fprintf(fp2, "%i", count);
    fclose(fp2);
    FILE *fp3 = fopen("/sd/positionCipherReceiver.txt", "w");
    fprintf(fp3, "%i", count);
    fclose(fp3);
    //uLCD.printf("made files\n");
return 0;
} //end main

