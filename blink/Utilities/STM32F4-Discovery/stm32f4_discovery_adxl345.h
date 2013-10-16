/**
  ******************************************************************************
  * @file    stm32f4_discovery_adxl345.h
  * @author  Anthony Paterson
  * @version V0.0.0
  * @date    10-OCtober-2013
  * @brief
  ******************************************************************************
  * @attention
  *
  *>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32F4_DISCOVERY_ADXL345_H_
#define STM32F4_DISCOVERY_ADXL345_H_

#ifdef __cplusplus
 extern "C" {
#endif

 /* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "i2c.h"

 /** @addtogroup Utilities
   * @{
   */

 /** @addtogroup STM32F4_DISCOVERY
   * @{
   */


 /** @addtogroup STM32F4_DISCOVERY_ADXL345
   * @{
   */


 /** @defgroup STM32F4_DISCOVERY_ADXL345_Exported_Types
   * @{
   */

 /* ADXL345 struct */
 typedef struct
 {
	 uint8_t Data_Format;
	 uint8_t Power_Mode;
	 uint8_t Interrupt_Enable;
 }ADXL345_InitTypeDef;

 /**
  * @}
  */


/** @defgroup STM32F4_DISCOVERY_ADXL345_Exported_Constants
* @{
*/

 /** @brief ADXL345 i2c device id constant
   *
   */
#define ADXL345_I2C_DEVID				0xE5

 /** @brief ADXL345 Default I2C Addresses
   * \attention !CS pin must be tied high to Vddio to put ADXL345 in i2c mode.
   * 			ALT_ADDRESS pin must not be floating.
   * 			ALT_ADDRESS tied high sets 7bit address to Default of 0x1D, low sets Alternate of 0x53.
   */
#define	ADXL345_I2C_7BIT_ADDRESS_DEFAULT	(uint8_t)0x1D //Tie SDO / alt address pin high
#define ADXL345_I2C_7BIT_ADDRESS_ALT		(uint8_t)0x53 //Ground SDO / pin
#define ADXL345_I2C_7BIT_ADDRESS			ADXL345_I2C_7BIT_ADDRESS_DEFAULT
#ifdef ADXL345_USE_ALT_ADDRESS
 #define ADXL345_I2C_7BIT_ADDRESS			ADXL345_7BIT_ADDRESS_ALT
#endif

/**
* @defgroup ADXL345_I2C_Interface_Pins
*/
//#define ADXL345_I2C							I2C1
//#define ADXL345_I2C_CLK						RCC_APB1Periph_I2C1

//#define ADXL345_I2C_SCL_PIN					GPIO_Pin_6
//#define ADXL345_I2C_SCL_GPIO_PORT     	  	GPIOB
//#define ADXL345_I2C_SCL_GPIO_CLK      	  	RCC_AHB1Periph_GPIOB
//#define ADXL345_I2C_SCL_SOURCE          	GPIO_PinSource6
//#define ADXL345_I2C_SCL_AF            		GPIO_AF_I2C1

//#define ADXL345_I2C_SDA_PIN					GPIO_Pin_7
//#define ADXL345_I2C_SDA_GPIO_PORT      		GPIOB
//#define ADXL345_I2C_SDA_GPIO_CLK        	RCC_AHB1Periph_GPIOB
//#define ADXL345_I2C_SDA_SOURCE          	GPIO_PinSource7
//#define ADXL345_I2C_SDA_AF              	GPIO_AF_I2C1

#define ADXL345_I2C_INT1_PIN            	GPIO_Pin_9				/*PB.9*/ 	//can this pin be used to drive an external interrupt EXTI?
#define ADXL345_I2C_INT1_GPIO_PORT      	GPIOB
#define ADXL345_I2C_INT1_GPIO_CLK       	RCC_AHB1Periph_GPIOB
#define ADXL345_I2C_INT1_EXTI_LINE      	EXTI_Line9
#define ADXL345_I2C_INT1_EXTI_PORT_SOURCE 	EXTI_PortSourceGPIOB
#define ADXL345_I2C_INT1_EXTI_PIN_SOURCE  	EXTI_PinSource9
#define ADXL345_I2C_INT1_EXTI_IRQn        	EXTI0_IRQn 				//correct?

#define ADXL345_I2C_INT2_PIN              	GPIO_Pin_0				/*PD.0*/ 	//can this pin be used to drive an external interrupt EXTI?
#define ADXL345_I2C_INT2_GPIO_PORT        	GPIOD
#define ADXL345_I2C_INT2_GPIO_CLK         	RCC_AHB1Periph_GPIOD
#define ADXL345_I2C_INT2_EXTI_LINE        	EXTI_Line0
#define ADXL345_I2C_INT2_EXTI_PORT_SOURCE 	EXTI_PortSourceGPIOD
#define ADXL345_I2C_INT2_EXTI_PIN_SOURCE  	EXTI_PinSource0
#define ADXL345_I2C_INT2_EXTI_IRQn        	EXTI1_IRQn 				//correct?


 /**
 * @defgroup ADXL345_Registers
 */

 /**
  * \def ADXL345_DEVID_REG_ADDR
  * 		DEVID Register: Device Identification Register.
  * 		Read only.
  * 		Default value: 0xE5.
  * 		Fixed value.
  */
#define ADXL345_DEVID_REG_ADDR 			(uint8_t)0x00

 /*******************************************************************************
 *
 *  Reserved: 0x01 to 0x1c
 *
 *******************************************************************************/

 /*******************************************************************************
 *  THRESH_TAP Register
 *  Read/Write
 *
 *******************************************************************************/
#define ADXL345_THRESH_TAP_REG_ADDR 	(uint8_t)0x1D

 /*******************************************************************************
 *	OFSX Register: Stores X axis bias correction value
 *	Read/Write
 *
 *******************************************************************************/
#define ADXL345_OFSX_REG_ADDR			(uint8_t)0x1E

 /*******************************************************************************
  *	OFSY Register: Stores Y axis bias correction value
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_OFSY_REG_ADDR			(uint8_t)0x1F

 /*******************************************************************************
  *	OFSZ Register: Stores Z axis bias correction value
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_OFSZ_REG_ADDR			(uint8_t)0x20

 /*******************************************************************************
  * DUR Register:
  * Read/Write
  *
  *******************************************************************************/
#define ADXL345_DUR_REG_ADDR			(uint8_t)0x21

 /*******************************************************************************
  * Latent Register:
  * Read/Write
  *
  *******************************************************************************/
#define ADXL345_Latent_REG_ADDR			(uint8_t)0x22

 /*******************************************************************************
  *	Window Register:
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_Window_REG_ADDR			(uint8_t)0x23

 /*******************************************************************************
  *	TRESH_ACT Register:
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_THRESH_ACT_REG_ADDR		(uint8_t)0x24

 /*******************************************************************************
  *	THRESH_INACT Register:
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_THRESH_INACT_REG_ADDR	(uint8_t)0x25

 /*******************************************************************************
  *	TIME_INACT Register:
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_TIME_INACT_REG_ADDR		(uint8_t)0x26

 /*******************************************************************************
  *	ACT_INACT_CTL Register:
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_ACT_INACT_CTL_REG_ADDR	(uint8_t)0x27

 /*******************************************************************************
  *	THRESH_FF_INACT Register:
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_THRESH_FF_REG_ADDR		(uint8_t)0x28

 /*******************************************************************************
  *	TIME_FF Register:
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_TIME_FF_REG_ADDR		(uint8_t)0x29

 /*******************************************************************************
  *	TAP_AXES Register:
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_TAP_AXES_REG_ADDR		(uint8_t)0x2A

 /*******************************************************************************
  * ACT_TAP_STATUS Register:
  *	Read only
  *
  *******************************************************************************/
#define ADXL345_ACT_TAP_STATUS_REG_ADDR	(uint8_t)0x2B

 /*******************************************************************************
  * BW_RATE Register:
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_BW_RATE_REG_ADDR		(uint8_t)0x2C	//R/W

 /*******************************************************************************
  * POWER_CTL Register:
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_POWER_CTL_REG_ADDR		(uint8_t)0x2D	//R/W

 /*******************************************************************************
  * INT_ENABLE Register:
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_INT_ENABLE_REG_ADDR		(uint8_t)0x2E	//R/W

 /*******************************************************************************
  * INT_MAP Register:
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_INT_MAP_REG_ADDR		(uint8_t)0x2F	//R/W

 /*******************************************************************************
  *	INT_SOURCE Register:
  *	Read only
  *
  *******************************************************************************/
#define ADXL345_INT_SOURCE_REG_ADDR		(uint8_t)0x30	//R

 /*******************************************************************************
  * DATA_FORMAT Register:
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_DATA_FORMAT_REG_ADDR	(uint8_t)0x31	//R/W

 /*******************************************************************************
  *	DATAX0 Register:
  *	Read only
  *
  *******************************************************************************/
#define ADXL345_DATAX0_REG_ADDR			(uint8_t)0x32	//R

 /*******************************************************************************
  *	DATAX1 Register:
  *	Read only
  *
  *******************************************************************************/
#define ADXL345_DATAX1_REG_ADDR			(uint8_t)0x33	//R

 /*******************************************************************************
  *	DATAY0 Register:
  *	Read only
  *
  *******************************************************************************/
#define ADXL345_DATAY0_REG_ADDR			(uint8_t)0x34	//R

 /*******************************************************************************
  *	DATAY1 Register:
  *	Read only
  *
  *******************************************************************************/
#define ADXL345_DATAY1_REG_ADDR			(uint8_t)0x35	//R

 /*******************************************************************************
  *	DATAZ0 Register:
  *	Read only
  *
  *******************************************************************************/
#define ADXL345_DATAZ0_REG_ADDR			(uint8_t)0x36	//R

 /*******************************************************************************
  * DATAZ1 Register:
  *	Read only
  *
  *******************************************************************************/
#define ADXL345_DATAZ1_REG_ADDR			(uint8_t)0x37	//R

 /*******************************************************************************
  * FIFO_CTL Register:
  *	Read/Write
  *
  *******************************************************************************/
#define ADXL345_FIFO_CTL_REG_ADDR		(uint8_t)0x38	//R/W

 /*******************************************************************************
  * FIFO_STATUS Register:
  *	Read only
  *
  *******************************************************************************/
#define ADXL345_FIFO_STATUS_REG_ADDR	(uint8_t)0x39	//R


 /**
   * @defgroup ADXL345_mode_selection
   *
   */

#define ADXL345_ACT_AC_COUPLED				((uint8_t)	0x80) // disable: activity detection by comparing to THRESH_ACT
 	 	 	 	 	 	 	 	 	 	 	 	 	 	 	  // enable: activity detection by comparing measurements to measurement at start of activity detection
#define ADXL345_ACTX_ENABLE					((uint8_t)	0x40) // enable interrupt generation by activity detected
#define ADXL345_ACTY_ENABLE					((uint8_t)	0x20)
#define ADXL345_ACTZ_ENABLE					((uint8_t)	0x10)
#define ADXL345_INACT_AC_COUPLED			((uint8_t)	0x08)
#define ADXL345_INACTX_ENABLE				((uint8_t)	0x04) // enable interrupt generation by inactivity detected
#define ADXL345_INACTY_ENABLE				((uint8_t)	0x02)
#define ADXL345_INACTZ_ENABLE				((uint8_t)	0x01)

#define ADXL345_TAP_X_ENABLE				((uint8_t)	0x08)
#define ADXL345_TAP_Y_ENABLE				((uint8_t)	0x04)
#define ADXL345_TAP_Z_ENABLE				((uint8_t)	0x02)
#define ADXL345_TAP_SUPPRESS				((uint8_t)	0x01)

// read only register
// bit D8 unused
#define ADXL345_ACT_X_Source				((uint8_t)	0x04)
#define ADXL345_ACT_Y_Source				((uint8_t)	0x02)
#define ADXL345_ACT_Z_Source				((uint8_t)	0x01)
#define ADXL345_Asleep						((uint8_t)	0x08)
#define ADXL345_TAP_X_Source				((uint8_t)	0x04)
#define ADXL345_TAP_Y_Source				((uint8_t)	0x02)
#define ADXL345_TAP_Z_Source				((uint8_t)	0x01)

#define ADXL345_BW_RATE_POWER_MODE_LOW		((uint8_t)	0x10)
#define ADXL345_BW_RATE_POWER_MODE_NORMAL	((uint8_t)	0x00)
#define ADXL345_BW_RATE_3200Hz				((uint8_t)	0x15)
#define ADXL345_BW_RATE_160Hz				((uint8_t)	0x14)
#define ADXL345_BW_RATE_800					((uint8_t)	0x13)
#define ADXL345_BW_RATE_400Hz				((uint8_t)	0x12)
#define ADXL345_BW_RATE_200Hz				((uint8_t)	0x11)
#define ADXL345_BW_RATE_100Hz				((uint8_t)	0x10)
#define ADXL345_BW_RATE_50Hz				((uint8_t)	0x09)
#define ADXL345_BW_RATE_25Hz				((uint8_t)	0x08)
#define ADXL345_BW_RATE_12_5Hz				((uint8_t)	0x07)
#define ADXL345_BW_RATE_6_25Hz				((uint8_t)	0x06)
#define ADXL345_BW_RATE_3_13Hz				((uint8_t)	0x05)
#define ADXL345_BW_RATE_1_56Hz				((uint8_t)	0x04)
#define ADXL345_BW_RATE_0_78Hz				((uint8_t)	0x03)
#define ADXL345_BW_RATE_0_39Hz				((uint8_t)	0x02)
#define ADXL345_BW_RATE_0_20Hz				((uint8_t)	0x01)
#define ADXL345_BW_RATE_0_10Hz				((uint8_t)	0x00)

#define ADXL345_POWER_CTL_Link_ENABLE		((uint8_t)	0x20)
#define ADXL345_POWER_CTL_AUTO_SLEEP_ENABLE	((uint8_t)	0x10)
#define ADXL345_POWER_CTL_Measure_ENABLE	((uint8_t)	0x08)
#define ADXL345_POWER_CTL_Sleep_ENABLE		((uint8_t)	0x04)

#define ADXL345_POWER_CTL_Wakeup_1Hz		((uint8_t)	0x03)
#define ADXL345_POWER_CTL_Wakeup_2Hz		((uint8_t)	0x02)
#define ADXL345_POWER_CTL_Wakeup_4Hz		((uint8_t)	0x01)
#define ADXL345_POWER_CTL_Wakeup_8Hz		((uint8_t)	0x00)


#define ADXL345_INT_ENABLE_DATA_READY_ENABLE	((uint8_t)	0x80) //enable interrupt outputs, and allow from each function
#define ADXL345_INT_ENABLE_SINGLE_TAP_ENABLE	((uint8_t)	0x40)
#define ADXL345_INT_ENABLE_DOUBLE_TAP_ENABLE	((uint8_t)	0x20)
#define ADXL345_INT_ENABLE_Activity_ENABLE		((uint8_t)	0x10)
#define ADXL345_INT_ENABLE_Inactivity_ENABLE	((uint8_t)	0x08)
#define ADXL345_INT_ENABLE_FREE_FALL_ENABLE		((uint8_t)	0x04)
#define ADXL345_INT_ENABLE_Watermark_ENABLE		((uint8_t)	0x02)
#define ADXL345_INT_ENABLE_Overrun_ENABLE		((uint8_t)	0x01)

#define ADXL345_INT_MAP_DATA_READY_ENABLE		((uint8_t)	0x80) //disable to send interupt to int1 pin. enable to send interrupt to int2 pin.
#define ADXL345_INT_MAP_SINGLE_TAP_ENABLE		((uint8_t)	0x40)
#define ADXL345_INT_MAP_DOUBLE_TAP_ENABLE		((uint8_t)	0x20)
#define ADXL345_INT_MAP_Activity_ENABLE			((uint8_t)	0x10)
#define ADXL345_INT_MAP_Inactivity_ENABLE		((uint8_t)	0x08)
#define ADXL345_INT_MAP_FREE_FALL_ENABLE		((uint8_t)	0x04)
#define ADXL345_INT_MAP_Watermark_ENABLE		((uint8_t)	0x02)
#define ADXL345_INT_MAP_Overrun_ENABLE			((uint8_t)	0x01)

#define ADXL345_INT_SOURCE_DATA_READY_ENABLE	((uint8_t)	0x80)
#define ADXL345_INT_SOURCE_SINGLE_TAP_ENABLE	((uint8_t)	0x40)
#define ADXL345_INT_SOURCE_DOUBLE_TAP_ENABLE	((uint8_t)	0x20)
#define ADXL345_INT_SOURCE_Activity_ENABLE		((uint8_t)	0x10)
#define ADXL345_INT_SOURCE_Inactivity_ENABLE	((uint8_t)	0x08)
#define ADXL345_INT_SOURCE_FREE_FALL_ENABLE		((uint8_t)	0x04)
#define ADXL345_INT_SOURCE_Watermark_ENABLE		((uint8_t)	0x02)
#define ADXL345_INT_SOURCE_Overrun_ENABLE		((uint8_t)	0x01)

#define ADXL345_DATAFORMAT_SELF_TEST_ENABLE		((uint8_t)	0x80)
#define ADXL345_DATAFORMAT_SPI_ENABLE			((uint8_t)	0x40) //enable for 3-wire SPI mode, disable for 4-wire SPI mode.
#define ADXL345_DATAFORMAT_INT_INVERT			((uint8_t)	0x20)
 //
#define ADXL345_DATAFORMAT_FULL_RES_ENABLE		((uint8_t)	0x08) // enable to use full resolution mode, maintaining 4mg/LSB scale factor, disable to use scale factor set by range bits.
#define ADXL345_DATAFORMAT_Justify_ENABLE		((uint8_t)	0x04)
#define ADXL345_DATAFORMAT_Range_PLUS_MINUS_16g	((uint8_t)	0x03)
#define ADXL345_DATAFORMAT_Range_PLUS_MINUS_8g	((uint8_t)	0x02)
#define ADXL345_DATAFORMAT_Range_PLUS_MINUS_4g	((uint8_t)	0x01)
#define ADXL345_DATAFORMAT_Range_PLUS_MINUS_2g	((uint8_t)	0x00)

#define ADXL345_FIFO_CTL_MODE_Trigger			((uint8_t)	0xC0)
#define ADXL345_FIFO_CTL_MODE_Stream			((uint8_t)	0x80)
#define ADXL345_FIFO_CTL_MODE_FIFO				((uint8_t)	0x40)
#define ADXL345_FIFO_CTL_MODE_Bypass			((uint8_t)	0x00)
#define ADXL345_FIFO_CTL_TRIGGER_				((uint8_t)	0x20)
#define ADXL345_FIFO_CTL_Samples_MASK			((uint8_t)	0x1F)
 // bypass mode: 	none
 //	FIFO mode: 		sets number of FIFO entries needed to trigger water mark threshold
 // Stream mode: 	sets number of FIFO entries needed to trigger water mark threshold
 //	Trigger mode:	Specifies how many FIFO samples are retained in the FIFO buffer before a trigger event.

//read only register
#define ADXL345_FIFO_STATUS_TRIG_EVENT_FLAG		((uint8_t)	0x80)
 // bit D6 not used
#define ADXL345_FIFO_STATUS_Entries_MASK		((uint8_t)	0x3F)


 /**
  * @}
  */

/** @defgroup STM32F4_DISCOVERY_ADXL345_Exported_Macros
* @{
*/

 /**
   * @}
   */

/** @defgroup STM32F4_DISCOVERY_ADXL345_Exported_Functions
* @{
*/

 void ADXL345_Calibrate();
 void ADXL345_Self_Test();
 void ADXL345_Init(ADXL345_InitTypeDef *ADXL345_InitStruct);
 uint32_t ADXL345_ReadOffsets();
 void ADXL345_WriteOffsets(uint8_t offsx, uint8_t offsy, uint8_t offsz);

 uint8_t ADXL345_ReadReg(uint8_t ADXL345_Reg);
 void ADXL345_WriteReg(uint8_t ADXL345_Reg, uint16_t ADXL345_RegValue);




 /**
 * @brief Uncomment the line below if you want to use user defined Delay function
 *        (for precise timing), otherwise default _delay_ function defined within
 *         this driver is used (less precise timing).
 */
 /* #define USE_Delay */

 #ifdef USE_Delay
 #include "main.h"
 #define _delay_     Delay  /* !< User can provide more timing precise _delay_ function
 								(with 10ms time base), using SysTick for example */
 #else
 #define _delay_     delay      /* !< Default _delay_ function with less precise timing */
 #endif

 /**
   * @}
   */

#ifdef __cplusplus
}
#endif

#endif /* STM32F4_DISCOVERY_ADXL345_H_ */

 /**
   * @}
   */

 /**
   * @}
   */

 /**
   * @}
   */

 /**
   * @}
   */



