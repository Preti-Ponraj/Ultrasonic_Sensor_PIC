/*
 * File:   Ultrasonic_Sensor.c
 * Author: Preethi
 *
 * Created on 25 February, 2022, 5:42 PM
 */


#include <xc.h>
#define echo RA0
#define trigger RA1

void timer1()
{
    TMR1=0xD8F0;
    while(TMR1IF==1);
    TMR1IF=0;   
}

void main(void) 
{   
    PORTA=0x00;
    TRISA=0x01;
    ANSEL=0x00;
    ANSELH=0x00;
    T1CON=0x01;
    
    while(1)
    { 
    
        float pulse,time;
        float distance;
        trigger=1; 
        timer1();
        trigger=0;
        TMR1=0x0000;
        while(echo==0);
        T1CON=0x01;
        while(echo==1);
        T1CON=0x00;
        pulse=TMR1;
        time=pulse/10000.0;
        distance=((340000.0)*(float)time)/2.0;//converted s to ms
    }
        
   
}
