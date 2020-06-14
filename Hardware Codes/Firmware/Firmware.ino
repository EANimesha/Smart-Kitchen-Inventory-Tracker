
// Include Libraries
#include "Arduino.h"
#include "FSR.h"

//Connecting to wifi
#include <WiFi.h>
#include <FirebaseESP32.h>

FirebaseData firebaseData;

const char* ssid = "Nimesha";
const char* password = "11111111";

// Pin Definitions
#define FSR_1_PIN_1	12
#define FSR_2_PIN_1	13
#define FSR_3_PIN_1	14
#define LED_1	1
#define LED_2	3
#define LED_3	4



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

    //Connect to wifi
    WiFi.begin(ssid, password);
 
    while (WiFi.status() != WL_CONNECTED) {
      delay(500);
      Serial.print(".");
    }
 
    Serial.println(".......");
    Serial.println("WiFi Connected....IP Address:");
    Serial.println(WiFi.localIP());

    //connect to firebase project
    Firebase.begin("https://smart-kitchen-18f3f.firebaseio.com/", "AIzaSyC2L6b-K2QQB64H_7k2fnwuLEMDgHgPIDk");
    Serial.println("Firebase connected");
    
}

void loop() 
{
    
    float fsr_1Force = fsr_1.getForce();
    if (Firebase.setDouble(firebaseData, "/user001/item1", fsr_1Force)){
      Serial.print(F("Force: ")); Serial.print(fsr_1Force); Serial.println(F(" [g]")); 
    }

    float fsr_2Force = fsr_2.getForce();
    if (Firebase.setDouble(firebaseData, "/user001/item2", fsr_2Force)){
      Serial.print(F("Force: ")); Serial.print(fsr_2Force); Serial.println(F(" [g]"));
    }

    float fsr_3Force = fsr_3.getForce();
    if (Firebase.setDouble(firebaseData, "/user001/item3", fsr_3Force)){
    Serial.print(F("Force: ")); Serial.print(fsr_3Force); Serial.println(F(" [g]"));
    }

    delay(5000);
    
}
