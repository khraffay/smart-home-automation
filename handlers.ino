

#include "thingProperties.h"

const int Switch1 = 18;
const int Switch2 = 19;
const int Switch3 = 22;
const int Switch4 = 23;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

  pinMode(Switch1, OUTPUT);
  pinMode(Switch2, OUTPUT);
  pinMode(Switch3, OUTPUT);
  pinMode(Switch4, OUTPUT);

  // Defined in thingProperties.h
  initProperties();

  // Connect to Arduino IoT Cloud
  ArduinoCloud.begin(ArduinoIoTPreferredConnection);
  
  /*
     The following function allows you to obtain more information
     related to the state of network and IoT Cloud connection and errors
     the higher number the more granular information you’ll get.
     The default is 0 (only errors).
     Maximum is 4
 */
  setDebugMessageLevel(2);
  ArduinoCloud.printDebugInfo();
}

void loop() {
  ArduinoCloud.update();
  // Your code here 
}

void onFan1Change() {
  if (fan1) {
    digitalWrite(Switch1, HIGH);
    Serial.println("Fan 1: ON");
  } else {
    digitalWrite(Switch1, LOW);
    Serial.println("Fan 1: OFF");
  }
}

void onFan2Change() {
  if (fan2) {
    digitalWrite(Switch2, HIGH);
    Serial.println("Fan 2: ON");
  } else {
    digitalWrite(Switch2, LOW);
    Serial.println("Fan 2: OFF");
  }
}

void onLight1Change() {
  if (light1) {
    digitalWrite(Switch3, HIGH);
    Serial.println("Light 1: ON");
  } else {
    digitalWrite(Switch3, LOW);
    Serial.println("Light 1: OFF");
  }
}

void onLight2Change() {
  if (light2) {
    digitalWrite(Switch4, HIGH);
    Serial.println("Light 2: ON");
  } else {
    digitalWrite(Switch4, LOW);
    Serial.println("Light 2: OFF");
  }
}