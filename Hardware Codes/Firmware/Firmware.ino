
// Include Libraries
#include "Arduino.h"
#include "Buzzer.h"
#include "FSR.h"
#include "LED.h"
#include "PIR.h"


// Pin Definitions
#define BUZZER_PIN_SIG	0
#define FSR_1_PIN_1	12
#define FSR_2_PIN_1	13
#define FSR_3_PIN_1	14
#define LEDR_1_PIN_VIN	1
#define LEDR_2_PIN_VIN	3
#define LEDR_3_PIN_VIN	4
#define PIR_PIN_SIG	2



// Global variables and defines

// object initialization
Buzzer buzzer(BUZZER_PIN_SIG);
FSR fsr_1(FSR_1_PIN_1);
FSR fsr_2(FSR_2_PIN_1);
FSR fsr_3(FSR_3_PIN_1);
LED ledR_1(LEDR_1_PIN_VIN);
LED ledR_2(LEDR_2_PIN_VIN);
LED ledR_3(LEDR_3_PIN_VIN);
PIR pir(PIR_PIN_SIG);


// define vars for testing menu
const int timeout = 10000;       //define timeout of 10 sec
char menuOption = 0;
long time0;

// Setup the essentials for your circuit to work. It runs first every time your circuit is powered with electricity.
void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    
    menuOption = menu();
    
}

// Main logic of your circuit. It defines the interaction between the components you selected. After setup, it runs over and over again, in an eternal loop.
void loop() 
{
    
    
    if(menuOption == '1') {
    // Buzzer - Test Code
    // The buzzer will turn on and off for 500ms (0.5 sec)
    buzzer.on();       // 1. turns on
    delay(500);             // 2. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    buzzer.off();      // 3. turns off.
    delay(500);             // 4. waits 500 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }
    else if(menuOption == '2') {
    // Force Sensitive Resistor 0.5'' #1 - Test Code
    // Read FSR resistance value. try also fsr_1.getResistance()
    // For more information see Sparkfun website - www.sparkfun.com/products/9375
    // Note, the default Vcc and external resistor values for FSR calculations are 5V ang 3300Okm, if you are not 
    //       using these default valuse in your circuit go to FSR.cpp and change default values in FSR constructor
    float fsr_1Force = fsr_1.getForce();
    Serial.print(F("Force: ")); Serial.print(fsr_1Force); Serial.println(F(" [g]"));

    }
    else if(menuOption == '3') {
    // Force Sensitive Resistor 0.5'' #2 - Test Code
    // Read FSR resistance value. try also fsr_2.getResistance()
    // For more information see Sparkfun website - www.sparkfun.com/products/9375
    // Note, the default Vcc and external resistor values for FSR calculations are 5V ang 3300Okm, if you are not 
    //       using these default valuse in your circuit go to FSR.cpp and change default values in FSR constructor
    float fsr_2Force = fsr_2.getForce();
    Serial.print(F("Force: ")); Serial.print(fsr_2Force); Serial.println(F(" [g]"));

    }
    else if(menuOption == '4') {
    // Force Sensitive Resistor 0.5'' #3 - Test Code
    // Read FSR resistance value. try also fsr_3.getResistance()
    // For more information see Sparkfun website - www.sparkfun.com/products/9375
    // Note, the default Vcc and external resistor values for FSR calculations are 5V ang 3300Okm, if you are not 
    //       using these default valuse in your circuit go to FSR.cpp and change default values in FSR constructor
    float fsr_3Force = fsr_3.getForce();
    Serial.print(F("Force: ")); Serial.print(fsr_3Force); Serial.println(F(" [g]"));

    }
    else if(menuOption == '5') {
    // LED - Basic Red 5mm #1 - Test Code
    // The LED will turn on and fade till it is off
    for(int i=255 ; i> 0 ; i -= 5)
    {
    ledR_1.dim(i);                      // 1. Dim Led 
    delay(15);                               // 2. waits 5 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }                                          
    ledR_1.off();                        // 3. turns off
    }
    else if(menuOption == '6') {
    // LED - Basic Red 5mm #2 - Test Code
    // The LED will turn on and fade till it is off
    for(int i=255 ; i> 0 ; i -= 5)
    {
    ledR_2.dim(i);                      // 1. Dim Led 
    delay(15);                               // 2. waits 5 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }                                          
    ledR_2.off();                        // 3. turns off
    }
    else if(menuOption == '7') {
    // LED - Basic Red 5mm #3 - Test Code
    // The LED will turn on and fade till it is off
    for(int i=255 ; i> 0 ; i -= 5)
    {
    ledR_3.dim(i);                      // 1. Dim Led 
    delay(15);                               // 2. waits 5 milliseconds (0.5 sec). Change the value in the brackets (500) for a longer or shorter delay in milliseconds.
    }                                          
    ledR_3.off();                        // 3. turns off
    }
    else if(menuOption == '8') {
    // Infrared PIR Motion Sensor Module - Test Code
    bool pirVal = pir.read();
    Serial.print(F("Val: ")); Serial.println(pirVal);

    }
    
    if (millis() - time0 > timeout)
    {
        menuOption = menu();
    }
    
}



// Menu function for selecting the components to be tested
// Follow serial monitor for instrcutions
char menu()
{

    Serial.println(F("\nWhich component would you like to test?"));
    Serial.println(F("(1) Buzzer"));
    Serial.println(F("(2) Force Sensitive Resistor 0.5'' #1"));
    Serial.println(F("(3) Force Sensitive Resistor 0.5'' #2"));
    Serial.println(F("(4) Force Sensitive Resistor 0.5'' #3"));
    Serial.println(F("(5) LED - Basic Red 5mm #1"));
    Serial.println(F("(6) LED - Basic Red 5mm #2"));
    Serial.println(F("(7) LED - Basic Red 5mm #3"));
    Serial.println(F("(8) Infrared PIR Motion Sensor Module"));
    Serial.println(F("(menu) send anything else or press on board reset button\n"));
    while (!Serial.available());

    // Read data from serial monitor if received
    while (Serial.available()) 
    {
        char c = Serial.read();
        if (isAlphaNumeric(c)) 
        {   
            
            if(c == '1') 
    			Serial.println(F("Now Testing Buzzer"));
    		else if(c == '2') 
    			Serial.println(F("Now Testing Force Sensitive Resistor 0.5'' #1"));
    		else if(c == '3') 
    			Serial.println(F("Now Testing Force Sensitive Resistor 0.5'' #2"));
    		else if(c == '4') 
    			Serial.println(F("Now Testing Force Sensitive Resistor 0.5'' #3"));
    		else if(c == '5') 
    			Serial.println(F("Now Testing LED - Basic Red 5mm #1"));
    		else if(c == '6') 
    			Serial.println(F("Now Testing LED - Basic Red 5mm #2"));
    		else if(c == '7') 
    			Serial.println(F("Now Testing LED - Basic Red 5mm #3"));
    		else if(c == '8') 
    			Serial.println(F("Now Testing Infrared PIR Motion Sensor Module"));
            else
            {
                Serial.println(F("illegal input!"));
                return 0;
            }
            time0 = millis();
            return c;
        }
    }
}

/*******************************************************

*    Circuito.io is an automatic generator of schematics and code for off
*    the shelf hardware combinations.

*    Copyright (C) 2016 Roboplan Technologies Ltd.

*    This program is free software: you can redistribute it and/or modify
*    it under the terms of the GNU General Public License as published by
*    the Free Software Foundation, either version 3 of the License, or
*    (at your option) any later version.

*    This program is distributed in the hope that it will be useful,
*    but WITHOUT ANY WARRANTY; without even the implied warranty of
*    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
*    GNU General Public License for more details.

*    You should have received a copy of the GNU General Public License
*    along with this program.  If not, see <http://www.gnu.org/licenses/>.

*    In addition, and without limitation, to the disclaimers of warranties 
*    stated above and in the GNU General Public License version 3 (or any 
*    later version), Roboplan Technologies Ltd. ("Roboplan") offers this 
*    program subject to the following warranty disclaimers and by using 
*    this program you acknowledge and agree to the following:
*    THIS PROGRAM IS PROVIDED ON AN "AS IS" AND "AS AVAILABLE" BASIS, AND 
*    WITHOUT WARRANTIES OF ANY KIND EITHER EXPRESS OR IMPLIED.  ROBOPLAN 
*    HEREBY DISCLAIMS ALL WARRANTIES, EXPRESS OR IMPLIED, INCLUDING BUT 
*    NOT LIMITED TO IMPLIED WARRANTIES OF MERCHANTABILITY, TITLE, FITNESS 
*    FOR A PARTICULAR PURPOSE, NON-INFRINGEMENT, AND THOSE ARISING BY 
*    STATUTE OR FROM A COURSE OF DEALING OR USAGE OF TRADE. 
*    YOUR RELIANCE ON, OR USE OF THIS PROGRAM IS AT YOUR SOLE RISK.
*    ROBOPLAN DOES NOT GUARANTEE THAT THE PROGRAM WILL BE FREE OF, OR NOT 
*    SUSCEPTIBLE TO, BUGS, SECURITY BREACHES, OR VIRUSES. ROBOPLAN DOES 
*    NOT WARRANT THAT YOUR USE OF THE PROGRAM, INCLUDING PURSUANT TO 
*    SCHEMATICS, INSTRUCTIONS OR RECOMMENDATIONS OF ROBOPLAN, WILL BE SAFE 
*    FOR PERSONAL USE OR FOR PRODUCTION OR COMMERCIAL USE, WILL NOT 
*    VIOLATE ANY THIRD PARTY RIGHTS, WILL PROVIDE THE INTENDED OR DESIRED
*    RESULTS, OR OPERATE AS YOU INTENDED OR AS MAY BE INDICATED BY ROBOPLAN. 
*    YOU HEREBY WAIVE, AGREE NOT TO ASSERT AGAINST, AND RELEASE ROBOPLAN, 
*    ITS LICENSORS AND AFFILIATES FROM, ANY CLAIMS IN CONNECTION WITH ANY OF 
*    THE ABOVE. 
********************************************************/