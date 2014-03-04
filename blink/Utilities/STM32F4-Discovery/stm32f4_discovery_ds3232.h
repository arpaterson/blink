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
#define DS3232_WHO_AM_I_REG_ADDR				((uint8_t)	0x00)	// Read/Write. Yes. You can change the ID of this device. Power on Reset value is 0bx110100x


 /********************************************************************************/

 /********************************************************************************/

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

