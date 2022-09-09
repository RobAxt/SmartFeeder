#ifndef Feeder_h
#define Feeder_h

#include "Arduino.h"
#include <SimpleStepper.h>
#include <Ticker.h>

class Feeder  {
    private:
        SimpleStepper _stepper;
        Ticker _stepperISR;
        
        static const uint8_t MOTOR_SPEED_MS = 3;
        static const uint8_t SLOT_COUNT = 8;
        static const uint8_t SLOT_OFFSET = 6;

	public:
		Feeder();
		void moveOneSlot(void);
        bool done(void);
};

#endif //Feeder_h