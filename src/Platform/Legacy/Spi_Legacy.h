#ifndef SPI_LEGACY_H
#define SPI_LEGACY_H


#include "../Base/Spi_Base.h"

// Don't compile if the platform is implemented elsewhere.
#if defined(PLATFORM_LEGACY)

NAMESPACE_SPI

/**
 * @brief 
 * SPI implementation for legacy platforms.
 */
class Spi_Legacy : public Spi_Base {

    public:

        void init(
            const uint8_t csPin,
            const uint8_t dcPin
        );

		void startTransaction(void);
		void endTransaction(void);
        void writeData16Multi(uint16_t data, uint32_t times);

        #if !defined (SPI_HAS_TRANSACTION)
        void setBitrate(uint32_t rate) override;
        #endif

    private:

		uint8_t _csPin;
        uint8_t _dcPin;
	
        SPISettings _spiSettings;

		void _selectData(void);
		void _selectCommand(void);
		void _deselect(void);
		void _write8(uint8_t c);
		void _write16(uint16_t c);
};

// Inline method definitions.
#include "Spi_Legacy.ipp"

NAMESPACE_SPI_END

#endif
#endif
