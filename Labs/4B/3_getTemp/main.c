/* Read and print the analog value off of a thermistor connected to pin A0
* then convert that reading into a voltage/temperature and print
* This version uses code from a Jameco TechTip regarding NTC thermistors
* Setup requires a 10K resistor as a voltage divider with the thermistor
* NOTE:
* math lib and vprintf must be included when compiled, 
* be sure next line is uncommented in  Makefile
* LDFLAGS += -Wl,-u,vfprintf -lprintf_flt -lm  ## for floating-point printf
*/

/* Put your #includes here */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "uart.h"
#include <unolib.h>
#include <analogRead.h>

void getTemp(float * t)
{
    // https://www.jameco.com/Jameco/workshop/TechTip/temperature-measurement-ntc-thermistors.html
    // Converts input from a thermistor voltage divider to a temperature value.
    // The voltage divider consists of thermistor Rt and series resistor R0 (use 10K resistor).
    // The value of R0 is equal to the thermistor resistance at T0.
    // You must set the following constants:
    //                  adcMax  ( ADC full range value )
    //                  analogPin (Arduino analog input pin)
    //                  invBeta  (inverse of the thermistor Beta value supplied by manufacturer).
    // Use Arduino's default reference voltage (5V or 3.3V) with this module.
    // This test used the Elegoo Kit MF52D-103f-3950 (assumed 103 is 10k ohms)

  const int analogPin = A0; // replace 0 with analog pin
  const float invBeta = 1.00 / 3950.00;   // replace "Beta" with beta of thermistor

  const  float adcMax = 1023.00;
  const float invT0 = 1.00 / 298.15;   // room temp in Kelvin

  int adcVal, i, numSamples = 5;
  float  K, C, F;

  adcVal = 0;
  for (i = 0; i < numSamples; i++)
   {
     adcVal = adcVal + analogRead(analogPin);
     delay(100);
   }
  adcVal = adcVal/5;
  t[0] = adcVal * 1.0;
  t[1] = adcVal * (5/1024.0);
  K = 1.00 / (invT0 + invBeta*(log ( adcMax / (float) adcVal - 1.00)));
  C = K - 273.15;               // convert to Celsius
  F = ((9.0*C)/5.00) + 32.00;   // convert to Fahrenheit
  t[2] = K;
  t[3] = C;
  t[4] = F;
  return;
}

/* Put your global variables here */

/* Main - is the function which C will look for to run at initialization*/ 
int main() {
/* initialize code goes here, similar to setup in the Arduino*/
    uart_init();
    stdout = &uart_output;
    stdin  = &uart_input;
                
    float temp[5];

// while(1) loop routine runs over and over again forever:
    while(1) {
        // this is the primary code section to execute
        getTemp(temp);
        printf("Readings are ADC %3.0f/1023 Voltage %5.2fV Temperature %3.1fF\n", temp[0], temp[1], temp[4]);

        delay(1000);
    }
    return(0);
}
