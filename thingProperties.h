

#include <ArduinoIoTCloud.h>
#include <Arduino_ConnectionHandler.h>

const char DEVICE_LOGIN_NAME[]  = "9bd181b3-a76f-47b4-89bf-0d3afc15d525";

const char SSID[]               = SECRET_SSID;    // Network SSID (name)
const char PASS[]               = SECRET_OPTIONAL_PASS;    // Network password (use for WPA, or use as key for WEP)
const char DEVICE_KEY[]  = SECRET_DEVICE_KEY;    // Secret device password

void onFan1Change();
void onFan2Change();
void onLight1Change();
void onLight2Change();

CloudSwitch fan1;
CloudSwitch fan2;
CloudSwitch light1;
CloudSwitch light2;

void initProperties(){

  ArduinoCloud.setBoardId(DEVICE_LOGIN_NAME);
  ArduinoCloud.setSecretDeviceKey(DEVICE_KEY);
  ArduinoCloud.addProperty(fan1, READWRITE, ON_CHANGE, onFan1Change);
  ArduinoCloud.addProperty(fan2, READWRITE, ON_CHANGE, onFan2Change);
  ArduinoCloud.addProperty(light1, READWRITE, ON_CHANGE, onLight1Change);
  ArduinoCloud.addProperty(light2, READWRITE, ON_CHANGE, onLight2Change);

}

WiFiConnectionHandler ArduinoIoTPreferredConnection(SSID, PASS);