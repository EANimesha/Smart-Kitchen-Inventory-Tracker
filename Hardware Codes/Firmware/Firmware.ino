
// Include Libraries
#include "Arduino.h"
#include "FSR.h"


// Pin Definitions
#define FSR_1_PIN_1	12
#define FSR_2_PIN_1	13
#define FSR_3_PIN_1	14
#define LEDR_1	1
#define LEDR_2	3
#define LEDR_3	4



// Global variables and defines

// object initialization
//Buzzer buzzer(BUZZER_PIN_SIG);
FSR fsr_1(FSR_1_PIN_1);
FSR fsr_2(FSR_2_PIN_1);
FSR fsr_3(FSR_3_PIN_1);



void setup() 
{
    // Setup Serial which is useful for debugging
    // Use the Serial Monitor to view printed messages
    Serial.begin(9600);
    while (!Serial) ; // wait for serial port to connect. Needed for native USB
    Serial.println("start");
    
    
}

void loop() 
{
    
    float fsr_1Force = fsr_1.getForce();
    Serial.print(F("Force: ")); Serial.print(fsr_1Force); Serial.println(F(" [g]"));

    float fsr_2Force = fsr_2.getForce();
    Serial.print(F("Force: ")); Serial.print(fsr_2Force); Serial.println(F(" [g]"));

  
    float fsr_3Force = fsr_3.getForce();
    Serial.print(F("Force: ")); Serial.print(fsr_3Force); Serial.println(F(" [g]"));


    
}
