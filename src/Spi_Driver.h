#ifndef SPI_DRIVER_H
#define SPI_DRIVER_H

#include "Driver/Spi_Platform_Include.h"

USE_NAMESPACE_SPI

class SPI_Driver : public Spi_Interface {

    public:

        // Declaration for 'validatePins' method.
        #include "Driver/Spi_ValidatePins_Declaration.h"

        // Declaration for 'init' method.
        #include "Driver/Spi_Init_Declaration.h"

        inline void startTransaction(void) { Spi_.startTransaction(); }
        inline void endTransaction(void) { Spi_.endTransaction(); }
        inline void writeCommand8(const uint8_t c) { Spi_.writeCommand8(c); }
        inline void writeCommand16(uint16_t c) { Spi_.writeCommand16(c); }
        inline void writeData8(uint8_t c) { Spi_.writeData8(c); }
        inline void writeData16(uint16_t d) { Spi_.writeData16(d); }
        inline void writeCommand8AndDeselect(const uint8_t c) { Spi_.writeCommand8AndDeselect(c); }
        inline void writeData8AndDeselect(uint8_t c) { Spi_.writeData8AndDeselect(c); }
        inline void writeData16AndDeselect(uint16_t d) { Spi_.writeData16AndDeselect(d); }
        inline void writeData16Multi(uint16_t data,uint32_t times) { Spi_.writeData16Multi(data, times); }
        inline void deselectAndEndTransaction(void) { Spi_.deselectAndEndTransaction(); }

    private:

        // Declaration for SPI object instance.
        #include "Driver/Spi_Instance_Declaration.h"
};

#endif
