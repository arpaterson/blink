/**
  ******************************************************************************
  * @file    stm32f4_discovery_itg3200.c
  * @author  Anthony Paterson
  * @version V0.0.0
  * @date    14-OCtober-2013
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
#include "stm32f4_discovery_itg3200.h"

 /** @addtogroup Utilities
   * @{
   */

 /** @addtogroup STM32F4_DISCOVERY
   * @{
   */


 /** @addtogroup STM32F4_DISCOVERY_ITG3200
   * @brief This file includes the accelerometer driver for (ADXL345)
   * @{
   */

 /** @defgroup STM32F4_DISCOVERY_ITG3200_Private_TypeDefinitions
   * @{
   */

 /**
   * @}
   */


 /** @defgroup STM32F4_DISCOVERY_ITG3200_Private_Defines
   * @{
   */

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_ITG3200_Private_Macros
   * @{
   */

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_ITG3200_Private_Variables
   * @{
   */

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_ITG3200_Private_FunctionPrototypes
   * @{
   */
void ITG3200_LowLevel_Init();

 /**
   * @}
   */

 /** @defgroup STM32F4_DISCOVERY_ITG3200_Private_Functions
   * @{
   */

/**
  * @brief
  * @param
  * @param
  * @param
  * @retval
  */
void ITG3200_Init(ITG3200_InitTypeDef *ITG3200_InitStruct){

	 /*
	  * Power up sequencing:
	  *
	  * NOTE: 	You cannot just tie Vlogic to Vdd.
	  * 		Vlogic must always be less than Vdd, and should rise after Vdd.
	  *
	  *
	  * 1. TVDDR is VDD rise time: Time for VDD to rise from 10% to 90% of its final value
	  * 2. TVDDR is <5msec
	  * 3. TVLGR is VLOGIC rise time:
	  * 	Time for VLOGIC to rise from 10% to 90% of its final value
	  * 4. TVLGR is <1msec
	  * 5. TVLG-VDD is the delay from the start of VDD ramp to the start of VLOGIC rise
	  * 6. TVLG-VDD is 0 to 20msec but VLOGIC amplitude must always be <VDD amplitude
	  * 7. VDD and VLOGIC must be monotonic ramps
	  */


	  /* Configure the low level interface ---------------------------------------*/
	  ITG3200_LowLevel_Init();

	  /* Initialisation command sequence -----------------------------------------
	   * 	Minimum initialisation sequence:
	   * 		1.	Vs = ON. Vddio = ON
	   * 		2.	Wait 1.1ms	   *
	   *
	   * 		.	Write PWR_MGM register, configuring
	   * 					Hard reset to power on defaults
	   * 					disable low power sleep mode
	   * 					disable standby on all axis
	   * 					select a clock source power on default is int osc (unstable)
	   * 						(must? check pll is ready after selceting a new clock source)
	   *
	   * 		.	Write Sample Rate Divider register
	   * 		.	Write DLPF_FS register, configuring Digital Low Pass Filter and Full Scale
	   * 				FS_SEL:
	   * 					Power on default: 00h.
	   * 					Set to 03h for normal operation (2000deg/sec)
	   * 				DLPF_CFG:
	   *
	   *
	   * 		.	Write INT_CFG register, power on default 00h
	   * 				configure interrupt output pin polarity, drain, latching, clearing,
	   * 				and triggering - when ready or when data available.
	   *
	   * 		. Read status reg, check PLL is ready
	   *--------------------------------------------------------------------------*/

	  uint8_t	power_mgmt_opts =	ITG3200_InitStruct->Power_Config |
									ITG3200_InitStruct->Clock_Config
									;

	  uint8_t	dlpf_fs_opts	=	ITG3200_InitStruct->Full_Scale |
									ITG3200_InitStruct->Low_Pass_Freq
									;

	  uint8_t	sample_rate_divider_opts	=
									ITG3200_InitStruct->Sample_Rate_Divider;

	  uint8_t	interrupt_opts	=	ITG3200_InitStruct->Interrupt_Config;

	  ITG3200_WriteReg(ITG3200_POWER_MGMT_REG_ADDR, power_mgmt_opts);
	  ITG3200_WriteReg(ITG3200_SAMPLE_RATE_DIVIDER_REG_ADDR, sample_rate_divider_opts);
	  ITG3200_WriteReg(ITG3200_DLPF_FS_REG_ADDR, dlpf_fs_opts);
	  ITG3200_WriteReg(ITG3200_INT_CFG_REG_ADDR, interrupt_opts);

}

 /**
   * @brief
   * @param
   * @param
   * @param
   * @retval
   */
void ITG3200_LowLevel_Init(){
	  GPIO_InitTypeDef	GPIO_InitStructure;

	  I2C_LowLevel_Init();

	  //Enable INT GPIO Clock
	  RCC_AHB1PeriphClockCmd(ITG3200_I2C_INT_GPIO_CLK, ENABLE);


	  //Configure INT pin to detect interrupts
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;

	  GPIO_InitStructure.GPIO_Pin = ITG3200_I2C_INT_PIN;
	  GPIO_Init(ITG3200_I2C_INT_GPIO_PORT, &GPIO_InitStructure);

}


/**
  * @brief
  * @param
  * @param
  * @param
  * @retval
  */
uint8_t ITG3200_ReadReg(uint8_t ITG3200_Reg){
	 //Send request for register contents.
	 I2C_Start(ITG3200_I2C_7BIT_ADDRESS<<1, I2C_Direction_Transmitter);
	 I2C_Write(ITG3200_Reg);
	 I2C_RepeatedStart(ITG3200_I2C_7BIT_ADDRESS<<1, I2C_Direction_Receiver);
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
void ITG3200_WriteReg(uint8_t ITG3200_Reg, uint16_t ITG3200_RegValue){
	 I2C_Start(ITG3200_I2C_7BIT_ADDRESS<<1 , I2C_Direction_Transmitter);
	 I2C_Write(ITG3200_Reg);
	 I2C_Write(ITG3200_RegValue);
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
