/**
  ******************************************************************************
  * @file    stm32f4_discovery_adxl345.c
  * @author  Anthony Paterson
  * @version V0.0.0
  * @date    10-OCtober-2013
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
#include "stm32f4_discovery_adxl345.h"

/** @addtogroup Utilities
  * @{
  */

/** @addtogroup STM32F4_DISCOVERY
  * @{
  */

/** @addtogroup STM32F4_DISCOVERY_ADXL345
  * @{
  */

/** @defgroup STM32F4_DISCOVERY_ADXL345
  * @brief This file includes the accelerometer driver for (ADXL345)
  * @{
  */

/**
  * @}
  */

/** @defgroup STM32F4_DISCOVERY_ADXL345_Private_TypesDefinitions
  * @{
  */

/**
  * @}
  */

/** @defgroup STM32F4_DISCOVERY_ADXL345_Private_Defines
  * @{
  */

/**
  * @}
  */

/** @defgroup STM32F4_DISCOVERY_ADXL345_Private_Macros
  * @{
  */

/**
  * @}
  */

/** @defgroup STM32F4_DISCOVERY_ADXL345_Private_Variables
  * @{
  */

/**
  * @}
  */

/** @defgroup STM32F4_DISCOVERY_ADXL345_Private_FunctionPrototypes
  * @{
  */
void ADXL345_LowLevel_Init();

/**
  * @}
  */

/** @defgroup STM32F4_DISCOVERY_ADXL345_Private_Functions
  * @{
  */

/**
  * @brief
  * @param
  * @param
  * @param
  * @retval
  */
 void ADXL345_Calibrate(){
	 	 //pre cal checks

		 //place sensor in x=y=0g, z=+1g orientation.

		 //Vs= on, Vddi/o = on

		 //wait 1.1ms

		 //init command sequence, set 16g range, 13bit mode, start measurement and enable data ready interrupt.

		 //wait 11.1ms (at ODR=100Hz) wait time depends on ODR settling and and 1.1ms+1/ODR

		 //sample min 100 points and average

		 //calculate calibration values. these will be *added* to accel measurements. get sign right.

		 //write to offset registers

		 //end
 }

/**
  * @brief
  * @param
  * @param
  * @param
  * @retval
  */
 void ADXL345_Self_Test(){
	 //pre test checks

	 //Vs= on, Vddi/o = on

	 //wait 1.1ms

	 //init command sequence, set 16g range, 13bit mode, start measurement and enable data ready interrupt.

	 //wait 11.1ms (at ODR=100Hz) wait time depends on ODR settling and and 1.1ms+1/ODR

	 //sample min 100 points and average

	 //activate self test by writing to DATA_FORMAT register. self test ON, 16g range, 13-bit mode.

	 //wait 1.1ms

	 //sample min 100 points and average

	 //deactivate self-test by writing to DATA_FORMAT register. self test OFF, 16g range, 13-bit mode.

	 //calculate delta and compare to data sheet limits.

 }

 /**
   * @brief
   * @param
   * @param
   * @param
   * @retval
   */


 /**
   * @brief
   * @param
   * @param
   * @param
   * @retval
   */

 /**
   * @brief
   * @param
   * @param
   * @param
   * @retval
   */
 void ADXL345_Init(ADXL345_InitTypeDef *ADXL345_InitStruct){


	  /* Configure the low level interface ---------------------------------------*/
	  ADXL345_LowLevel_Init();

	  /* Initialisation command sequence -----------------------------------------
	   * 	Minimum initialisation sequence:
	   * 		1.	Vs = ON. Vddio = ON
	   * 		2.	Wait 1.1ms	   *
	   * 		3.	Write DATA_FORMAT register, 16g, 13bit mode
	   * 		4.	Write POWER_CTL register, Start measurement
	   * 		5.	Write INT_ENABLE register, ENABLE_DATA_READY_INTERRUPT
	   *--------------------------------------------------------------------------*/

	  uint8_t dfopts = 0x00;
	  uint8_t pcopts = 0x00;
	  uint8_t ieopts = 0x00;

	  dfopts = ADXL345_InitStruct->Data_Format;
	  pcopts = ADXL345_InitStruct->Power_Mode;
	  ieopts = ADXL345_InitStruct->Interrupt_Enable;

	  ADXL345_WriteReg(ADXL345_DATA_FORMAT_REG_ADDR, dfopts);
	  ADXL345_WriteReg(ADXL345_POWER_CTL_REG_ADDR, pcopts);
	  ADXL345_WriteReg(ADXL345_INT_ENABLE_REG_ADDR, ieopts);
 }

 /**
   * @brief		ADXL345_LowLevel_Init, low level initialization routine for ADXL345 connected via I2C Peripheral
   * @param		None
   * @retval	None
   */
  void ADXL345_LowLevel_Init(){
	  GPIO_InitTypeDef	GPIO_InitStructure;

	  I2C_LowLevel_Init();

	  //Enable INT1 GPIO Clock
	  RCC_AHB1PeriphClockCmd(ADXL345_I2C_INT1_GPIO_CLK, ENABLE);

	  //Enable INT2 GPIO Clock
	  RCC_AHB1PeriphClockCmd(ADXL345_I2C_INT2_GPIO_CLK, ENABLE);

	  //Configure INT1 and INT2 pins to detect interrupts
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IN;
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz;
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_NOPULL;

	  GPIO_InitStructure.GPIO_Pin = ADXL345_I2C_INT1_PIN;
	  GPIO_Init(ADXL345_I2C_INT1_GPIO_PORT, &GPIO_InitStructure);

	  GPIO_InitStructure.GPIO_Pin = ADXL345_I2C_INT2_PIN;
	  GPIO_Init(ADXL345_I2C_INT2_GPIO_PORT, &GPIO_InitStructure);
  }

  /**
    * @brief
    * @param
    * @param
    * @param
    * @retval
    */
  uint8_t ADXL345_ReadReg(uint8_t ADXL345_Reg){
	 //Send request for register contents.
 	 I2C_Start(ADXL345_I2C_7BIT_ADDRESS<<1, I2C_Direction_Transmitter);
 	 I2C_Write(ADXL345_Reg);
 	 I2C_Stop();
 	 //retrieve data.
 	 I2C_Start(ADXL345_I2C_7BIT_ADDRESS<<1, I2C_Direction_Receiver);
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
 void ADXL345_WriteReg(uint8_t ADXL345_Reg, uint16_t ADXL345_RegValue){
	 I2C_Start(ADXL345_I2C_7BIT_ADDRESS<<1 , I2C_Direction_Transmitter);
	 I2C_Write(ADXL345_Reg);
	 I2C_Write(ADXL345_RegValue);
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
