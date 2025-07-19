#include "thingProperties.h"

const int Switch1=18;
const int Switch2=19;
const int Switch3=22;
const int Switch4=23;

void setup() {
  // Initialize serial and wait for port to open:
  Serial.begin(9600);
  // This delay gives the chance to wait for a Serial Monitor without blocking if none is found
  delay(1500);

pinMode (Switch1, OUTPUT);
pinMode(Switch2, OUTPUT);
pinMode(Switch3, OUTPUT);
pinMode (Switch4, OUTPUT);

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


/*
  Since Fan1 is READ_WRITE variable, onFan1Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onFan1Change()  {
  // Add your code here to act upon Fan1 change

if(fan1)

{
digitalWrite(Switch1, HIGH);
Serial.println("ON");
}
else
{
digitalWrite(Switch1, LOW);
Serial.println("OFF");
}
}

/*
  Since Fan2 is READ_WRITE variable, onFan2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onFan2Change()  {
  // Add your code here to act upon Fan2 change
  if(fan2)

{
digitalWrite(Switch2, HIGH);
Serial.println("ON");
}
else
{
digitalWrite(Switch2, LOW);
Serial.println("OFF");
}
}

/*
  Since Light1 is READ_WRITE variable, onLight1Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onLight1Change()  {
  // Add your code here to act upon Light1 change
  if(light1)

{
digitalWrite(Switch3, HIGH);
Serial.println("ON");
}
else
{
digitalWrite(Switch3, LOW);
Serial.println("OFF");
}
}

/*
  Since Light2 is READ_WRITE variable, onLight2Change() is
  executed every time a new value is received from IoT Cloud.
*/
void onLight2Change()  {
  // Add your code here to act upon Light2 change

  if(light2)

{
digitalWrite(Switch4, HIGH);
Serial.println("ON");
}
else
{
digitalWrite(Switch4, LOW);
Serial.println("OFF");
}
  
}