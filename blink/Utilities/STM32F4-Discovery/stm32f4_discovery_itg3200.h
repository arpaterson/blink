/**
  ******************************************************************************
  * @file    stm32f4_discovery_itg3200.h
  * @author  Anthony Paterson
  * @version V0.0.0
  * @date    14-OCtober-2013
  * @brief
  ******************************************************************************
  * @attention
  *
  *>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef STM32F4_DISCOVERY_ITG3200_H_
#define STM32F4_DISCOVERY_ITG3200_H_

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


 /** @addtogroup STM32F4_DISCOVERY_ITG3200
   * @{
   */

 /** @defgroup STM32F4_DISCOVERY_ITG3200_Exported_Types
   * @{
   */

 /**
  * \struct ITG3200_InitTypeDef
  */
 typedef struct
 {

	 uint8_t Sample_Rate_Divider;
	 uint8_t Full_Scale;
	 uint8_t Low_Pass_Freq;
	 uint8_t Interrupt_Config;
	 uint8_t Power_Config;
	 uint8_t Clock_Config;

 }ITG3200_InitTypeDef;

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_ITG3200_Exported_Constants
   * @{
   */

 /** @brief ITG3200 i2c device id constant
   *
   */
//#define ITG3200_I2C_DEVID				0x69 //itg3200 returns its own address as devid

 /** @brief ITG3200 Default I2C Addresses
   * \attention AD0 (Pin 9) must not be floating.
   * 			AD0 (Pin 9) tied low sets 7bit address to Default of 0x68, high sets Alternate of 0x69.
   */
#define	ITG3200_I2C_7BIT_ADDRESS_DEFAULT	(uint8_t)0x68 //AD0 = 0, Pin 9 logic low
#define ITG3200_I2C_7BIT_ADDRESS_ALT		(uint8_t)0x69 //AD0 = 1, Pin 9 logic high
#define ITG3200_I2C_7BIT_ADDRESS			ITG3200_I2C_7BIT_ADDRESS_DEFAULT
#ifdef ITG3200_USE_ALT_ADDRESS
 #define ITG3200_I2C_7BIT_ADDRESS			ITG3200_I2C_7BIT_ADDRESS_ALT
#endif

 /**
 * @defgroup ITG3200_I2C_Interface_Pins
 */

#define ITG3200_I2C_INT_PIN            	GPIO_Pin_6				/*PB.9*/ 	//can this pin be used to drive an external interrupt EXTI?
#define ITG3200_I2C_INT_GPIO_PORT      	GPIOD
#define ITG3200_I2C_INT_GPIO_CLK       	RCC_AHB1Periph_GPIOD
#define ITG3200_I2C_INT_EXTI_LINE      	EXTI_Line6
#define ITG3200_I2C_INT_EXTI_PORT_SOURCE 	EXTI_PortSourceGPIOD
#define ITG3200_I2C_INT_EXTI_PIN_SOURCE  	EXTI_PinSource6
#define ITG3200_I2C_INT_EXTI_IRQn        	EXTI0_IRQn 				//correct?

 /**
 * @defgroup ITG3200_Registers
 */

 /**
  * \def ITG3200_WHO_AM_I_REG_ADDR
  * 		DEVID Register: Device Identification Register.
  * 		Read only.
  * 		Default value:.
  * 		Fixed value.
   */
#define ITG3200_WHO_AM_I_REG_ADDR				((uint8_t)	0x00)	// Read/Write. Yes. You can change the ID of this device. Power on Reset value is 0bx110100x

 /********************************************************************************/
#define ITG3200_SAMPLE_RATE_DIVIDER_REG_ADDR	((uint8_t)	0x15)	// Delivered sample rate. Fsample = Finternal/(divider+1), Finternal is either 1 or 8kHz, set by DLPF_CFG

 /********************************************************************************/
#define ITG3200_DLPF_FS_REG_ADDR				((uint8_t)	0x16)	// Bit4:Bit3 FS_SEL - Power on default 00h, BIT2:BIT0 DLPF_CFG.
#define ITG32000_DLPF_FS_FS_SEL_PLUS_MINUS_2000	((uint8_t)	0x03)	//Default.
//#define ITG3200_FS_SEL_2	((uint8_t)	0x02)	//Reserved Do Not Use.
//#define ITG3200_FS_SEL_1	((uint8_t)	0x01)	//Reserved Do Not Use.
//#define ITG3200_FS_SEL_0	((uint8_t)	0x00)	//Reserved Do Not Use.

//Digital Low Pass Filter config, also sets internal sample rate. See data sheet for filter characteristics.
//#define ITG3200_DLPF_CFG_7	((uint8_t)	0x07)	//Reserved Do Not Use.
#define ITG3200_DLPF_FS_DLPF_CFG_5Hz			((uint8_t)	0x06)	//1kHz internal sampling
#define ITG3000_DLPF_FS_DLPF_CFG_10Hz			((uint8_t)	0x05)	//1kHz internal sampling
#define ITG3000_DLPF_FS_DLPF_CFG_20Hz			((uint8_t)	0x04)	//1kHz internal sampling
#define ITG3200_DLPF_FS_DLPF_CFG_42Hz			((uint8_t)	0x03)	//1kHz internal sampling
#define ITG3200_DLPF_FS_DLPF_CFG_98Hz		((uint8_t)	0x02)	//1kHz internal sampling
#define ITG3200_DLPF_FS_DLPF_CFG_188Hz			((uint8_t)	0x01)	//1kHz internal sampling
#define ITG3200_DLPF_FS_DLPF_CFG_256Hz			((uint8_t)	0x00)	//8kHz internal sampling
 /********************************************************************************/
#define ITG3200_INT_CFG_REG_ADDR				((uint8_t)	0x17)

#define ITG3200_INT_CFG_ACTL_ENABLE				((uint8_t)	0x80)	//Logic level for INT output pin – 1=active low, 0=active high
#define ITG3200_INT_CFG_OD_ENABLE				((uint8_t)	0x40)	//Drive type for INT output pin – 1=open drain, 0=push-pull
#define ITG3200_INT_CFG_LATCH_ENABLE			((uint8_t)	0x20)	//Latch mode – 1=latch until interrupt is cleared, 0=50us pulse
#define ITG3200_INT_CFG_ANYRD_TO_CLEAR_ENABLE	((uint8_t)	0x10)	//Latch clear method – 1=any register read, 0=status register read only
 //Bit3 reserved, must set to 0.
#define ITG3200_INT_CFG_ITG_RDY_ENABLE			((uint8_t)	0x04)	//Enable interrupt when device is ready (PLL ready after changing clock source)
 //Bit1 reserved, must set to 0.
#define ITG3200_INT_CFG_RAW_RDY_ENABLE			((uint8_t)	0x01)	//Enable interrupt when data is available

 /********************************************************************************/
#define ITG3200_INT_STATUS_REG_ADDR				((uint8_t)	0x1A)
 //Bit7 reserved, must set to 0.
 //Bit6 reserved, must set to 0.
 //Bit5 reserved, must set to 0.
 //Bit4 reserved, must set to 0.
 //Bit3 reserved, must set to 0.
#define ITG3200_INT_STATUS_ITG_RDY				((uint8_t)	0x04)		//PLL Ready
 //Bit2 reserved, must set to 0.
#define ITG3200_INT_STATUS_RAW_DATA_RDY			((uint8_t)	0x01)		//Raw Data is ready

 /********************************************************************************/
#define ITG3200_TEMP_OUT_H_REG_ADDR				((uint8_t)	0x1B)
#define ITG3200_TEMP_OUT_L_REG_ADDR	 			((uint8_t)	0x1C)

 /********************************************************************************/
#define ITG3200_GYRO_XOUT_H_ADDR				((uint8_t)	0x1D)	//16-bit 2's-complement format
#define ITG3200_GYRO_XOUT_L_ADDR				((uint8_t)	0x1E)

 /********************************************************************************/
#define ITG3200_GYRO_YOUT_H_ADDR				((uint8_t)	0x1F)	//16-bit 2's-complement format
#define ITG3200_GYRO_YOUT_L_ADDR				((uint8_t)	0x20)

 /********************************************************************************/
#define ITG3200_GYRO_ZOUT_H_ADDR				((uint8_t)	0x21)	//16-bit 2's-complement format
#define ITG3200_GYRO_ZOUT_L_ADDR				((uint8_t)	0x22)

 /********************************************************************************/
#define ITG3200_POWER_MGMT_REG_ADDR				((uint8_t)	0x3E)

#define ITG3200_POWER_MGMT_H_RESET_ENABLE		((uint8_t)	0x80)	//Reset device and internal registers to the power-up-default settings
#define ITG3200_POWER_MGMT_SLEEP_ENABLE			((uint8_t)	0x40)	//Enable low power sleep mode
#define ITG3200_POWER_MGMT_STBY_XG_ENABLE		((uint8_t)	0x20)	//Put gyro X in standby mode (1=standby, 0=normal)
#define ITG3200_POWER_MGMT_STBY_YG_ENABLE		((uint8_t)	0x10)	//Put gyro Y in standby mode (1=standby, 0=normal)
#define ITG3200_POWER_MGMT_STBY_ZG_ENABLE		((uint8_t)	0x08)	//Put gyro Z in standby mode (1=standby, 0=normal)

//#define ITG3200_POWER_MGMT_CLK_SEL_7			((uint8_t)	0x07)	//Reserved Do Not Use.
//#define ITG3200_POWER_MGMT_CLK_SEL_6			((uint8_t)	0x06)	//Reserved Do Not Use.
#define ITG3200_POWER_MGMT_CLK_SEL_PLL_EXT_19_2MHz_REF		((uint8_t)	0x05)
#define ITG3200_POWER_MGMT_CLK_SEL_PLL_EXT_32_768KHz_REF	((uint8_t)	0x04)
#define ITG3200_POWER_MGMT_CLK_SEL_PLL_ZG_REF	((uint8_t)	0x03)
#define ITG3200_POWER_MGMT_CLK_SEL_PLL_YG_REF	((uint8_t)	0x02)
#define ITG3200_POWER_MGMT_CLK_SEL_PLL_XG_REF	((uint8_t)	0x01)
#define ITG3200_POWER_MGMT_CLK_SEL_INT_OSC		((uint8_t)	0x00)	//Default on power up. Highly recommend to configure a more stable source (Any of the others).

 /********************************************************************************/

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_ITG3200_Exported_Macros
   * @{
   */

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_ITG3200_Exported_Functions
   * @{
   */
 void ITG3200_Init(ITG3200_InitTypeDef *ITG3200_InitStruct);

 uint8_t ITG3200_ReadReg(uint8_t ITG3200_Reg);
 void ITG3200_WriteReg(uint8_t ITG3200_Reg, uint16_t ITG3200_RegValue);


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

#endif /* STM32F4_DISCOVERY_ITG3200_H_ */

 /**
   * @}
   */

 /**
   * @}
   */

 /**
   * @}
   */

