typedef enum {
    SPI_ERROR = -1,
    SPI_OK = 0,
    SPI_ERROR_TIMEOUT = 1,
    SPI_ERROR_ARGUMENT,
    SPI_ERROR_OVERRUN,
    SPI_ERROR_MODE_FAULT,
    SPI_ERROR_OVERRUN_AND_MODE_FAULT
} spi_status_t;

spi_status_t spi_selectChip(volatile void *spi, uint8_t chip);
spi_status_t spi_unselectChip(volatile void *spi, uint8_t chip);
spi_status_t spi_write(volatile void *spi, uint16_t data);