#include <Arduino.h>
#include <Homie.h>
#include "FeederNode.hpp"

#define FW_NAME "smart-feeder"
#define FW_VERSION "0.0.0" 

/* Magic sequence for Autodetectable Binary Upload */
const char *__FLAGGED_FW_NAME = "\xbf\x84\xe4\x13\x54" FW_NAME "\x93\x44\x6b\xa7\x75";
const char *__FLAGGED_FW_VERSION = "\x6a\x3f\x3e\x0e\xe1" FW_VERSION "\xb0\x30\x48\xd4\x1a";
/* End of magic sequence for Autodetectable Binary Upload */

FeederNode feederNode("feeder", "Smart Feeder", "switch");

void setup() {
  Serial.begin(SERIAL_SPEED,SERIAL_8N1,SERIAL_TX_ONLY);
  Serial << endl << endl;
  Homie.getLogger() << F("Build Date and Time: ") << __DATE__ << " & " << __TIME__ << endl;

  Homie_setFirmware(FW_NAME, FW_VERSION);

  //Homie.setSetupFunction([](){});
  //Homie.setLoopFunction([](){});
  //Homie.setBroadcastHandler([](const String& level, const String& value){});
  //Homie.onEvent();
  Homie.setup();
}

void loop() {
  Homie.loop();  
}