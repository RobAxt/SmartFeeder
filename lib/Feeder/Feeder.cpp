#include "Feeder.hpp"

Feeder::Feeder() :_stepper(SimpleStepper::FULLSTEP, true, D5, D6, D7, D8) {
    _stepperISR.attach_ms(MOTOR_SPEED_MS,[this](){
                                                 _stepper.step(); 
                                                 if(_stepper.ready())
                                                    _stepper.offCoils();
                                               });
}

void 
Feeder::moveOneSlot(){
  if(_stepper.ready()) {
      _stepper.setStep(_stepper.getFullRotationSteps()/SLOT_COUNT+SLOT_OFFSET);
  }
}

bool 
Feeder::done(){   
  return _stepper.ready();
}