/**
  ******************************************************************************
  * @file    stm32f4_discovery_ds3232.c
  * @author  Anthony Paterson
  * @version V0.0.0
  * @date    04-March-2014
  * @brief
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "stm32f4_discovery.h"
#include "stm32f4_discovery_ds3232.h"

 /** @addtogroup Utilities
   * @{
   */

 /** @addtogroup STM32F4_DISCOVERY
   * @{
   */


 /** @addtogroup STM32F4_DISCOVERY_DS3232
   * @brief This file includes the rtc driver for Maxim DS3232
   * @{
   */

 /** @defgroup STM32F4_DISCOVERY_DS3232_Private_TypeDefinitions
   * @{
   */

 /**
   * @}
   */


 /** @defgroup STM32F4_DISCOVERY_DS3232_Private_Defines
   * @{
   */

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_DS3232_Private_Macros
   * @{
   */

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_DS3232_Private_Variables
   * @{
   */

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_DS3232_Private_FunctionPrototypes
   * @{
   */
void DS3232_LowLevel_Init();

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_DS3232_Private_Functions
   * @{
   */

/**
  * @brief
  * @param
  * @param
  * @param
  * @retval
  */
void DS3232_Init(DS3232_InitTypeDef *DS3232_InitStruct){

	 /**
	  * Power up sequencing: Refer Page to the device datasheet
	  *
	  *     Note:   This is a battery backed device "Power on Reset"
	  *             is defined as the first the device is
	  *             powered by Vcc or Vbat.
	  *
	  *             Additionally:
	  *
	  *             If first power up, The oscillator will not start,
	  *             and no temp conversion and capacitance update
          *             will take place UNTIL Vcc > Vpf.
          *             Once Vcc > Vpf, the oscillator will start.
          *             If not first power up, oscillator will run
          *             on Vbat unless !EOSC is set to 1.
	  *
	  */


	  /* Configure the low level interface ---------------------------------------*/
	  DS3232_LowLevel_Init();

	  /** Initialisation command sequence -----------------------------------------
	   * 	Minimum initialisation sequence:
	   *
	   *            Note the RTC does not power down with the rest of the
	   * 		        system like other devices.
	   *
	   * 		1.      !IMPORTANT! Check oscillator has NOT been stopped
	   * 		                (OSF==0 in CTRL_STATUS register).
	   * 		                fire error handler if OSF==1,
	   * 		                perhaps report !EOSC bit also
	   * 		                write OSF=0 when error has been handled.
	   * 		                Check Vcc > Vpf?
	   *
           *                    Check Vbat?,
           *                    Check if temp conversion taking/taken place
           *                    (check BSY==0 for periodic conversion,
           *                    check CONV==0 for user requested conversions)
           *                    Perform a conversion if none observed?
           *                    Wait for completion (wait on CONV==0 and BSY==0)
	   * 		        - Set / get time registers
	   * 		        - Alarms ?
	   * 		        - !INT/SQW output config (bit 6 control register)
	   * 		        - Set 12/24 hour mode (bit 6 of hour register)
	   * 		        -
	   *--------------------------------------------------------------------------*/



}

 /**
   * @brief
   * @param
   * @param
   * @param
   * @retval
   */
void DS3232_LowLevel_Init(){
	  GPIO_InitTypeDef	GPIO_InitStructure;

	  I2C_LowLevel_Init();

	  //Enable INT GPIO Clock
	  RCC_AHB1PeriphClockCmd(DS3232_I2C_INT_GPIO_CLK, ENABLE);


	  //Configure INT pin to detect interrupts
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;

	  GPIO_InitStructure.GPIO_Pin = DS3232_I2C_INT_PIN;
	  GPIO_Init(DS3232_I2C_INT_GPIO_PORT, &GPIO_InitStructure);

}


/**
  * @brief
  * @param
  * @param
  * @param
  * @retval
  */
uint8_t DS3232_ReadReg(uint8_t DS3232_Reg){
	 //Send request for register contents.
	 I2C_Start(DS3232_I2C_7BIT_ADDRESS<<1, I2C_Direction_Transmitter);
	 I2C_Write(DS3232_Reg);
	 I2C_RepeatedStart(DS3232_I2C_7BIT_ADDRESS<<1, I2C_Direction_Receiver);
	 uint8_t readvalue = I2C_Read_NAck();
	 return readvalue;
}

/**
  * @brief
  * @param
  * @param
  * @param
  * @retval
  */
void DS3232_WriteReg(uint8_t DS3232_Reg, uint16_t DS3232_RegValue){
	 I2C_Start(DS3232_I2C_7BIT_ADDRESS<<1 , I2C_Direction_Transmitter);
	 I2C_Write(DS3232_Reg);
	 I2C_Write(DS3232_RegValue);
	 I2C_Stop();
}




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

 /**
   * @}
   */

 /**
   * @}
   */
