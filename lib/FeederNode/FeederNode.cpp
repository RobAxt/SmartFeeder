#include "FeederNode.hpp"

FeederNode::FeederNode(const char* id, const char* name, const char* type) : HomieNode(id,name,type), _feeder() {}

void
FeederNode::setup() {
    Homie.getLogger() << F("Calling Node On Setup...") << endl;
  
    setRunLoopDisconnected(false);
    advertise("on").setName("On")
                   .setDatatype("boolean")
                   .setFormat("true,false")
                   .settable([this](const HomieRange& range, const String& value) {
                              return feederOnHandler(value == "true");
                             });
}

void
FeederNode::loop() {
     if(_feeder.done() && flagDone){
        setProperty("on").overwriteSetter(false).send("false");
        flagDone = false;
    }
}

void
FeederNode::onReadyToOperate() { 

}

bool 
FeederNode::handleInput(const HomieRange& range, const String& property, const String& value) {
    Homie.getLogger() << F("Calling Node Handle Input...") << endl;
    if (property != "on" || (value != "true" && value != "false")) {
        Homie.getLogger() << F("  ◦ Error: property not handle or wrong value") << endl;
        return true;
    }
    Homie.getLogger() << F("  ◦ Receive Property/Value: ") << property  << F(" ━► ") << value << endl;
    return false;
}

bool 
FeederNode::feederOnHandler(const bool on) {
    if(on == true) { 
        _feeder.moveOneSlot();
        flagDone = true;
    }
    else if(on == false)
        ; // Do Nothing
    else
        return false;
    return true;
}