#ifndef PIN_H
#define PIN_H

#include <unistd.h>
#define ON 1
#define OFF 0

#define BCM2835_GPIO_PUD_UP 0b10
#define BCM2835_GPIO_FSEL_INPT 	0b000
#define BCM2835_GPIO_FSEL_OUTP 	0b001
#define UNDEFINED_VALUE NULL

class Pin{
private:
    uint8_t noPin;
    bool isInput;
    uint8_t pullUp;
public:
    Pin(uint8_t no, bool input);
    uint8_t get();
    void set(uint8_t value);
    void changeDirection();
};

#endif // PIN_H
