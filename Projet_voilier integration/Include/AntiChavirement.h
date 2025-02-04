/* ************************************
Titre : 			Driver pour syt�me antichavirement (F4)

Auteur: 			Zaouali Mazin

Description: 	Code pour mise en place su SPI et communcation avec capteur d'inertie
***************************************** */

#ifndef ANTICHAV_H
#define ANTICHAV_H


#include "stm32f10x.h"
#include "math.h"

// https://www.engineersgarage.com/adxl345-accelerometer-sensor-how-to-use/
// activer le bus SPI
// configurer la ADXL345

#define	DEVID		0x00	//Device ID Register
#define THRESH_TAP	0x1D	//Tap Threshold
#define	OFSX		0x1E	//X-axis offset
#define	OFSY		0x1F	//Y-axis offset
#define	OFSZ		0x20	//Z-axis offset
#define	DURATION	0x21	//Tap Duration
#define	LATENT		0x22	//Tap latency
#define	WINDOW		0x23	//Tap window
#define	THRESH_ACT	0x24	//Activity Threshold
#define	THRESH_INACT	0x25	//Inactivity Threshold
#define	TIME_INACT	0x26	//Inactivity Time
#define	ACT_INACT_CTL	0x27	//Axis enable control for activity and inactivity detection
#define	THRESH_FF	0x28	//free-fall threshold
#define	TIME_FF		0x29	//Free-Fall Time
#define	TAP_AXES	0x2A	//Axis control for tap/double tap
#define ACT_TAP_STATUS	0x2B	//Source of tap/double tap
#define	BW_RATE		0x2C	//Data rate and power mode control
#define POWER_CTL	0x2D	//Power Control Register
#define	INT_ENABLE	0x2E	//Interrupt Enable Control
#define	INT_MAP		0x2F	//Interrupt Mapping Control
#define	INT_SOURCE	0x30	//Source of interrupts
#define	DATA_FORMAT	0x31	//Data format control
#define DATAX0		0x32	//X-Axis Data 0
#define DATAX1		0x33	//X-Axis Data 1
#define DATAY0		0x34	//Y-Axis Data 0
#define DATAY1		0x35	//Y-Axis Data 1
#define DATAZ0		0x36	//Z-Axis Data 0
#define DATAZ1		0x37	//Z-Axis Data 1
#define	FIFO_CTL	0x38	//FIFO control
#define	FIFO_STATUS	0x39	//FIFO status

#define TIM_DELAY TIM3
#define ARR_1MS 71
#define PSC_1MS 0


void GPIO_Config (void);
void SPI_Config(void);
void SPI_Transmission(uint8_t *data,int size);
void SPI_Receive (uint8_t *data,int size);

void SPI_Enable (void);
void SPI_Disable (void);
void CS_Enable (void);
void CS_Disable (void);

void adxl345_read (uint8_t address, uint8_t* RxData);
void adxl345_write (uint8_t address, uint8_t value);
void adxl345_init (void);
	
void Delay_us (uint16_t us);
void Delay_ms (uint16_t us);
#endif

