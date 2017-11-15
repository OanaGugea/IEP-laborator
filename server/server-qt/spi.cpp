#include "spi.h"
#include <stdio.h>

Spi::Spi(uint8_t bit_order, uint8_t data_mode, uint16_t clock_driver, uint8_t chip_select, uint8_t active)
{
    bcm2835_spi_setBitOrder(bit_order);
    bcm2835_spi_setDataMode(data_mode);
    bcm2835_spi_setClockDivider(clock_driver);
    bcm2835_spi_chipSelect(chip_select);
    bcm2835_spi_setChipSelectPolarity(chip_select, active);
}

uint8_t Spi::transfer(uint8_t data_byte){
    uint8_t read_data = bcm2835_spi_transfer(data_byte);
    printf("Sent to SPI: 0x%02X. Read back from SPI: 0x%02X.\n", data_byte, read_data);
    return read_data;
}

