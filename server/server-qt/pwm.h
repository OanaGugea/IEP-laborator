#ifndef PWM_H
#define PWM_H

#include "bcm2835.h"

class PWM
{
    private:
        float dutyCycle;
        float frequency;
    public:
        float getDutyCycle();
        void setDutyCycle(float dc);
        float getFrequency();
        void setFrequency(float f);
        PWM::PWM(float f, float dc);
        PWM::PWM();
};

#endif // PWM_H
