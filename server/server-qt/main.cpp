#include "mainwindow.h"
#include <QApplication>
#include "pin.h"
#include "pwm.h"


#define PWM_NO 12
#define BUTTON_NO 3
#define FREQ 100

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    float dutyCycle = 0;
    Pin led = new Pin(PWM_NO, false);
    Pin button = new Pin(BUTTON_NO, true);
    PWM pwm = new PWM(FREQ, dutyCycle);

    while(1){
        if (button.get() != 0){
            if (dutyCycle == 100){
                dutyCycle = 0;
            }
            else{

                dutyCycle += 10;
            }
        }
        pwm.setDutyCycle(dutyCycle);

    }

    return a.exec();
}
