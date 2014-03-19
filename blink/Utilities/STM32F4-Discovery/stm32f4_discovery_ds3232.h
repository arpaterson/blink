/**
  ******************************************************************************
  * @file    stm32f4_discovery_ds3232.h
  * @author  Anthony Paterson
  * @version V0.0.0
  * @date    04-March-2014
  * @brief
  ******************************************************************************
  * @attention
  *
  *>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32F4_DISCOVERY_DS3232_H_
#define STM32F4_DISCOVERY_DS3232_H_

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


 /** @addtogroup STM32F4_DISCOVERY_DS3232
   * @{
   */

 /** @defgroup STM32F4_DISCOVERY_DS3232_Exported_Types
   * @{
   */

 /**
  * \struct DS3232_InitTypeDef
  */
 typedef struct
 {

	 uint8_t Sample_Rate_Divider;


 }DS3232_InitTypeDef;

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_DS3232_Exported_Constants
   * @{
   */

 /** @brief DS3232 i2c device id constant
   *
   */
//#define DS3232_I2C_DEVID				0x??

 /** @brief DS3232 Default I2C Addresses
   * \attention
   *
   */
#define	DS3232_I2C_7BIT_ADDRESS        (uint8_t)0x68 // 0b1101000

 /**
 * @defgroup DS3232_I2C_Interface_Pins
 */

#define DS3232_I2C_INT_PIN            	GPIO_Pin_6
#define DS3232_I2C_INT_GPIO_PORT      	GPIOD
#define DS3232_I2C_INT_GPIO_CLK       	RCC_AHB1Periph_GPIOD
#define DS3232_I2C_INT_EXTI_LINE      	EXTI_Line6
#define DS3232_I2C_INT_EXTI_PORT_SOURCE 	EXTI_PortSourceGPIOD
#define DS3232_I2C_INT_EXTI_PIN_SOURCE  	EXTI_PinSource6
#define DS3232_I2C_INT_EXTI_IRQn        	EXTI0_IRQn

 /**
 * @defgroup DS3232_Registers
 */

 /**
  * \def DS3232_WHO_AM_I_REG_ADDR
  * 		DEVID Register: Device Identification Register.
  * 		Read only.
  * 		Default value:.
  * 		Fixed value.
   */
//#define DS3232_WHO_AM_I_REG_ADDR				((uint8_t)	0x00)	// Read/Write. Yes. You can change the ID of this device. Power on Reset value is 0bx110100x


 /********************************************************************************/
#define DS3232_SECONDS_REG_ADDR         ((uint8_t)      0x00)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_MINUTES_REG_ADDR         ((uint8_t)      0x01)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_HOURS_REG_ADDR           ((uint8_t)      0x02)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_DAY_REG_ADDR             ((uint8_t)      0x03)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_DATE_REG_ADDR            ((uint8_t)      0x04)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_MONTH_CENTURY_REG_ADDR   ((uint8_t)      0x05)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_YEAR_REG_ADDR            ((uint8_t)      0x06)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_ALARM1_SECONDS_REG_ADDR  ((uint8_t)      0x07)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_ALARM1_MINUTES_REG_ADDR  ((uint8_t)      0x08)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_ALARM1_HOURS_REG_ADDR    ((uint8_t)      0x09)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_ALARM1_DAY_DATE_REG_ADDR ((uint8_t)      0x0A)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0


 /********************************************************************************/
#define DS3232_ALARM2_MINUTES_REG_ADDR  ((uint8_t)      0x0B)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_ALARM2_HOURS_REG_ADDR    ((uint8_t)      0x0C)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_ALARM2_DAY_DATE_REG_ADDR ((uint8_t)      0x0D)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0


 /********************************************************************************/
#define DS3232_CONTROL_REG_ADDR         ((uint8_t)      0x0E)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_CTRL_STATUS_REG_ADDR     ((uint8_t)      0x0F)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_AGING_OFFSET_REG_ADDR    ((uint8_t)      0x10)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_TEMP_MSB_REG_ADDR        ((uint8_t)      0x11)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
#define DS3232_TEMP_LSB_REG_ADDR        ((uint8_t)      0x12)

 //BIT7
 //BIT6
 //BIT5
 //BIT4
 //BIT3
 //BIT2
 //BIT1
 //BIT0

 /********************************************************************************/
// RESERVED FOR TEST ADDR 0x13 ALL BITS

 /********************************************************************************/
#define DS3232_SRAM_START_ADDR          ((uint8_t)      0x14)
#define DS3232_SRAM_END_ADDR            0x0FF


 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_DS3232_Exported_Macros
   * @{
   */

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_DS3232_Exported_Functions
   * @{
   */
 void DS3232_Init(DS3232_InitTypeDef *DS3232_InitStruct);

 uint8_t DS3232_ReadReg(uint8_t DS3232_Reg);
 void DS3232_WriteReg(uint8_t DS3232_Reg, uint16_t DS3232_RegValue);


 /**
   * @}
   */

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

#endif /* STM32F4_DISCOVERY_DS3232_H_ */

 /**
   * @}
   */

 /**
   * @}
   */

 /**
   * @}
   */

