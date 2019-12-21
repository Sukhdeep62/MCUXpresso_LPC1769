/*
===============================================================================
 Name        : main.c
 Author      : $(author)
 Version     :
 Copyright   : $(copyright)
 Description : main definition
===============================================================================
*/

#if defined (__USE_LPCOPEN)
#if defined(NO_BOARD_LIB)
#include "chip.h"
#else
#include "board.h"
#endif
#endif

#include <cr_section_macros.h>
#include<string>
#include<vector>


// TODO: insert other include files here

// TODO: insert other definitions and declarations here

struct LED_struct
{
    unsigned long int duration;
    size_t color;
    bool ON;

};

typedef struct LED_struct LED_t;
using std::vector;
//void delay  (1sec)
void delay(unsigned long int x);
void delay(unsigned long int x)
{
	for(size_t i=0;i!=x;i++)
	{
	  for(long unsigned int j=10000000;j!=0;j--)
      {}
    }
}

int main(void) {

#if defined (__USE_LPCOPEN)
    // Read clock settings and update SystemCoreClock variable
    SystemCoreClockUpdate();
#if !defined(NO_BOARD_LIB)
    // Set up and initialize all required blocks and
    // functions related to the board hardware
    Board_Init();
    // clear the LEDs"

    LED_t loadarr[]={{5,0,TRUE},{5,1,TRUE},{5,2,TRUE},{5,1,FALSE},{5,2,FALSE}};

    vector<LED_t> sequenceLED;
      Board_LED_Set(0, false);
      Board_LED_Set(1, false);
  	  Board_LED_Set(2, false);

  	    for(size_t i=0;i!=6;i++)
  	    {
  	    	sequenceLED.push_back(loadarr[i]);
  	    }
  	    for(size_t i=0;i!=6;i++)
  	    {
  	    if(sequenceLED[i].ON==TRUE)
        	 {
  	    	if(sequenceLED[i].color==0)
  	    	{
  	    	    Board_LED_Set(0, true);
  	    		delay(sequenceLED[i].duration);


              }
  	    	else if(sequenceLED[i].color==1)
  	    	{
  	    	    Board_LED_Set(1, true);
  	    		delay(sequenceLED[i].duration);


              }
  	    	else if(sequenceLED[i].color==2)
  	    	  	    	{
  	    	  	    	    Board_LED_Set(2, true);
  	    	  	    		delay(sequenceLED[i].duration);

  	    	              }
        	 }
  	    else if( sequenceLED[i].ON== FALSE)
  	    	 {
  	    	if(sequenceLED[i].color==0)
  	    	  	    	{
  	    	  	    	    Board_LED_Set(0, false);
  	    	  	    		delay(sequenceLED[i].duration);

  	    	              }
  	    	  	    	else if(sequenceLED[i].color==1)
  	    	  	    	{
  	    	  	    	    Board_LED_Set(1, false);
  	    	  	    		delay(sequenceLED[i].duration);

  	    	              }
  	    	  	    	else if(sequenceLED[i].color==2)
  	    	  	    	  	    	{
  	    	  	    	  	    	    Board_LED_Set(2, false);
  	    	  	    	  	    		delay(sequenceLED[i].duration);

  		      }}

	    }

#endif
#endif

    // TODO: insert code here

    // Force the counter to be placed into memory
    volatile static int i = 0 ;
    // Enter an infinite loop, just incrementing a counter
    while(1) {
        i++ ;
    }
    return 0 ;
}

//  Youtube Video Link : https://youtu.be/oYCeiVOQCWw

//  GitHub Link :https://github.com/Sukhdeep62/MCUXpresso_LPC1769.git
