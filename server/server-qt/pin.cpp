/*class Pin{
private:
    int noPin;
    bool isInput;
    uint8_t pullUp;
public:
    Pin(int no, bool input);
    uint8_t get();
    void set(uint8_t value);
    void changeDirection();
};
*/

#include "pin.h"

Pin::Pin(uint8_t no, bool input){
    noPin = no;
    isInput = input;
    if (isInput){
        bcm2835_gpio_fsel(noPin, BCM2835_GPIO_FSEL_INPT);
        pullUp = BCM2835_GPIO_PUD_UP;
        bcm2835_gpio_set_pud(noPin, pullUp);
    }
    else{
        bcm2835_gpio_fsel(noPin, BCM2835_GPIO_FSEL_OUTP);
    }
}

uint8_t Pin::get(){
    if (!isInput){
        return UNDEFINED_VALUE;
    }
    uint8_t value = bcm2835_gpio_lev(noPin);
    printf("read from pin %d: %d\n", noPin, value);
    return value;
}

void Pin::set(uint8_t value){
    if (isInput){
        return;
    }
    bcm2835_gpio_write(noPin, value);
}

void Pin::changeDirection(){
    if (isInput){
        bcm2835_gpio_fsel(noPin, BCM2835_GPIO_FSEL_OUTP);

    }
    else{
        bcm2835_gpio_fsel(noPin, BCM2835_GPIO_FSEL_INPT);
        pullUp = BCM2835_GPIO_PUD_UP;
        bcm2835_gpio_set_pud(noPin, pullUp);
    }
    isInput = !isInput;
}
