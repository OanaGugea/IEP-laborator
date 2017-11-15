#include "mainwindow.h"
#include <QApplication>
#include "pin.h"
#include "pwm.h"
#include "spi.h"
#include "bcm2835.h"


#define PWM_NO 12
#define BUTTON_NO 3
#define FREQ 100

int main(int argc, char *argv[])
{
    bcm2835_set_debug(1);
    QApplication a(argc, argv);
//    MainWindow w;
//    w.show();

//    float dutyCycle = 0;
//    Pin *led = new Pin(PWM_NO, false);
//    Pin *button = new Pin(BUTTON_NO, true);
//    PWM *pwm = new PWM(FREQ, dutyCycle);

//    while(1){
//        if (button->get() != 0){
//            if (dutyCycle == 100){
//                dutyCycle = 0;
//            }
//            else{

//                dutyCycle += 10;
//            }
//        }
//        pwm->setDutyCycle(dutyCycle);

//    }

    Spi *spi = new Spi (BCM2835_SPI_BIT_ORDER_MSBFIRST, BCM2835_SPI_MODE0, BCM2835_SPI_CLOCK_DIVIDER_65536, BCM2835_SPI_CS0, LOW);
    spi->transfer('a');

    return a.exec();
}
