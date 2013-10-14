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
	  I2C_InitTypeDef	I2C_InitStructure;

	  //Enable I2C Peripheral Clock
	  RCC_APB1PeriphClockCmd(ADXL345_I2C_CLK, ENABLE);

	  //Enable I2C GPIO Clocks
	  RCC_AHB1PeriphClockCmd(ADXL345_I2C_SDA_GPIO_CLK | ADXL345_I2C_SCL_GPIO_CLK , ENABLE);

	  //Enable INT1 GPIO Clock
	  RCC_AHB1PeriphClockCmd(ADXL345_I2C_INT1_GPIO_CLK, ENABLE);

	  //Enable INT2 GPIO Clock
	  RCC_AHB1PeriphClockCmd(ADXL345_I2C_INT2_GPIO_CLK, ENABLE);

	  //GPIO Alternate Function config
	  GPIO_PinAFConfig(ADXL345_I2C_SCL_GPIO_PORT, ADXL345_I2C_SCL_SOURCE, ADXL345_I2C_SCL_AF);
	  GPIO_PinAFConfig(ADXL345_I2C_SDA_GPIO_PORT, ADXL345_I2C_SDA_SOURCE, ADXL345_I2C_SDA_AF);

	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//Set pins to alternate function
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;	//Set Output type to open drain (pulled low, not driven high)
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;		//Enable pull up resistors
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //

	  //I2C Pin Configuration
	  GPIO_InitStructure.GPIO_Pin = ADXL345_I2C_SCL_PIN;
	  GPIO_Init(ADXL345_I2C_SCL_GPIO_PORT, &GPIO_InitStructure);
	  GPIO_InitStructure.GPIO_Pin = ADXL345_I2C_SDA_PIN;
	  GPIO_Init(ADXL345_I2C_SDA_GPIO_PORT, &GPIO_InitStructure);

	  //I2C Configuration
	  //I2C_DeInit(ADXL345_I2C);
	  I2C_InitStructure.I2C_ClockSpeed = 		ADXL345_I2C_DATA_TRANSFER_MODE;				//100Khz or 400KHz are supported
	  I2C_InitStructure.I2C_Mode = 				I2C_Mode_I2C;		//I2C Mode
	  I2C_InitStructure.I2C_DutyCycle = 		I2C_DutyCycle_2;	//Standard 50% duty cycle
	  I2C_InitStructure.I2C_OwnAddress1 =		0x00; 				//Own address not relevant in master mode.
	  I2C_InitStructure.I2C_Ack =				I2C_Ack_Disable; 	//Disable acknowledge when reading, change later on?
	  I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	  I2C_Init(ADXL345_I2C, &I2C_InitStructure);

	  //Enable I2C port
	  I2C_Cmd(ADXL345_I2C, ENABLE);

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
 	 I2C_Start(ADXL345_I2C, ADXL345_I2C_7BIT_ADDRESS<<1, I2C_Direction_Transmitter);
 	 I2C_Write(ADXL345_I2C,ADXL345_Reg);
 	 I2C_Stop(ADXL345_I2C);
 	 //retrieve data.
 	 I2C_Start(ADXL345_I2C, ADXL345_I2C_7BIT_ADDRESS<<1, I2C_Direction_Receiver);
 	 uint8_t readvalue = I2C_Read_NAck(ADXL345_I2C);
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
	 I2C_Start(ADXL345_I2C, ADXL345_I2C_7BIT_ADDRESS<<1 , I2C_Direction_Transmitter);
	 I2C_Write(ADXL345_I2C, ADXL345_Reg);
	 I2C_Write(ADXL345_I2C, ADXL345_RegValue);
	 I2C_Stop(ADXL345_I2C);
 }

 void I2C_Start(I2C_TypeDef* I2Cx, uint8_t address, uint8_t direction){
	 //wait for i2c bus to be free
	 while(I2C_GetFlagStatus(I2Cx,I2C_FLAG_BUSY)){}
	 //send start
	 I2C_GenerateSTART(I2Cx, ENABLE);
	 //wait for slave to acknowledge (I2C EV5)
	 while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_MODE_SELECT)){}
	 // send slave address
	 I2C_Send7bitAddress(I2Cx, address, direction);
	 /* wait for I2C1 EV6, check if
	  * either Slave has acknowledged Master transmitter or
	  * Master receiver mode, depending on the transmission
	  * direction
	  */
	 if(direction == I2C_Direction_Transmitter){
		 while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_TRANSMITTER_MODE_SELECTED));
	 }
	 else if(direction == I2C_Direction_Receiver){
		 while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_RECEIVER_MODE_SELECTED));
	 }
 }

 void I2C_Write(I2C_TypeDef* I2Cx, uint8_t data){
	 //send byte
	 I2C_SendData(ADXL345_I2C, data);
	 //wait for byte received acknowledgement (I2C EV8_2)
	 while(!I2C_CheckEvent(ADXL345_I2C,I2C_EVENT_MASTER_BYTE_TRANSMITTED)){}
 }

 void I2C_Stop(I2C_TypeDef* I2Cx){
	 // Send I2C1 STOP Condition
	 	I2C_GenerateSTOP(I2Cx, ENABLE);
 }

 uint8_t I2C_Read_Ack(I2C_TypeDef* I2Cx){
	 //enable acknowledge of received data
	 I2C_AcknowledgeConfig(I2Cx, ENABLE);
	 //wait for received byte ready
	 while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED)){}
	 //read and return
	 uint8_t readbyte = I2C_ReceiveData(I2Cx);
	 return readbyte;
 }

 uint8_t I2C_Read_NAck(I2C_TypeDef* I2Cx){
	 // disable acknowledge of received data
	 // also generates stop condition after last byte received
	 I2C_AcknowledgeConfig(I2Cx, DISABLE);
	 I2C_GenerateSTOP(I2Cx, ENABLE);
	 //wait for received byte ready
	 while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED)){}
	 //read from I2C peripheral and return
	 uint8_t readbyte = I2C_ReceiveData(I2Cx);
	 return readbyte;
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
