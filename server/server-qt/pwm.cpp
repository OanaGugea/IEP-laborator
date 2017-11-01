#include "pwm.h"

/**
    private:
        float dutyCycle;
        float frequency;
    public:
        float getDutyCycle();
        void setDutyCycle(float dc);
        float getFrequency();
        void setFrequency(float f);**/

PWM::PWM()
{
    dutyCycle = 0;
    frequency = 0;
    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
    bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);
    bcm2835_pwm_set_range(PWM_CHANNEL, frequency);
    bcm2835_pwm_set_data(PWM_CHANNEL, dutyCycle);
}

PWM::PWM(float f, float dc){
    dutyCycle = dc;
    frequency = f;
    bcm2835_pwm_set_clock(BCM2835_PWM_CLOCK_DIVIDER_16);
    bcm2835_pwm_set_mode(PWM_CHANNEL, 1, 1);
    bcm2835_pwm_set_range(PWM_CHANNEL, frequency);
    bcm2835_pwm_set_data(PWM_CHANNEL, dutyCycle);
}

float PWM::getDutyCycle(){
    return (dutyCycle / frequency * 100);
}

void PWM::setDutyCycle(float dc){
    dutyCycle = (dc * frequency) / 100;
    bcm2835_pwm_set_data(PWM_CHANNEL, dutyCycle);
}

float PWM::getFrequency(){
    return frequency;
}

void PWM::setFrequency(float f){
    frequency = f;
}


