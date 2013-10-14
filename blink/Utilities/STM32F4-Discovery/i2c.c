/**
  ******************************************************************************
  * @file    i2c.c
  * @author  Anthony Paterson
  * @version V0.0.0
  * @date    15-OCtober-2013
  * @brief
  ******************************************************************************
  * @attention
  *
  *
  ******************************************************************************
  */

/* Includes ------------------------------------------------------------------*/
#include "i2c.h"

/** @addtogroup Utilities
  * @{
  */

 void I2C_Start(uint8_t address, uint8_t direction){
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

 void I2C_Write(uint8_t data){
	 //send byte
	 I2C_SendData(I2Cx, data);
	 //wait for byte received acknowledgement (I2C EV8_2)
	 while(!I2C_CheckEvent(I2Cx,I2C_EVENT_MASTER_BYTE_TRANSMITTED)){}
 }

 void I2C_Stop(){
	 // Send I2C1 STOP Condition
	 	I2C_GenerateSTOP(I2Cx, ENABLE);
 }

 uint8_t I2C_Read_Ack(){
	 //enable acknowledge of received data
	 I2C_AcknowledgeConfig(I2Cx, ENABLE);
	 //wait for received byte ready
	 while(!I2C_CheckEvent(I2Cx, I2C_EVENT_MASTER_BYTE_RECEIVED)){}
	 //read and return
	 uint8_t readbyte = I2C_ReceiveData(I2Cx);
	 return readbyte;
 }

 uint8_t I2C_Read_NAck(){
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

 void I2C_LowLevel_Init(){
	 GPIO_InitTypeDef	GPIO_InitStructure;
	 I2C_InitTypeDef	I2C_InitStructure;

	 //Enable I2C Peripheral Clock
	 RCC_APB1PeriphClockCmd(RCC_APB1Periph_I2Cx, ENABLE);

	 //Reset
	 RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2Cx, ENABLE);
	 RCC_APB1PeriphResetCmd(RCC_APB1Periph_I2Cx, DISABLE);

	 //Enable I2C GPIO Clocks
	 RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIO_SCL | RCC_AHB1Periph_GPIO_SDA , ENABLE);

	 //GPIO Alternate Function config
	  GPIO_PinAFConfig(GPIO_SCL, GPIO_PinSource_SCL, GPIO_AF_I2Cx);
	  GPIO_PinAFConfig(GPIO_SDA, GPIO_PinSource_SDA, GPIO_AF_I2Cx);

	  //I2C Pin Configuration
	  GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AF;		//Set pins to alternate function
	  GPIO_InitStructure.GPIO_OType = GPIO_OType_OD;	//Set Output type to open drain (pulled low, not driven high)
	  GPIO_InitStructure.GPIO_PuPd  = GPIO_PuPd_UP;		//Enable pull up resistors
	  GPIO_InitStructure.GPIO_Speed = GPIO_Speed_50MHz; //

	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_SCL;
	  GPIO_Init(GPIO_SCL, &GPIO_InitStructure);
	  GPIO_InitStructure.GPIO_Pin = GPIO_Pin_SDA;
	  GPIO_Init(GPIO_SDA, &GPIO_InitStructure);

	  //I2C Configuration
	  //I2C_DeInit(I2C);
	  I2C_InitStructure.I2C_ClockSpeed = 		I2Cx_ClockSpeed;		//5,50,100,400kHz
	  I2C_InitStructure.I2C_Mode = 				I2C_Mode_I2C;		//I2C Mode
	  I2C_InitStructure.I2C_DutyCycle = 		I2C_DutyCycle_2;	//Standard 50% duty cycle
	  I2C_InitStructure.I2C_OwnAddress1 =		0x00; 				//Own address not relevant in master mode.
	  I2C_InitStructure.I2C_Ack =				I2C_Ack_Disable; 	//Disable acknowledge when reading, change later on?
	  I2C_InitStructure.I2C_AcknowledgedAddress = I2C_AcknowledgedAddress_7bit;
	  I2C_Init(I2Cx, &I2C_InitStructure);

	  //Enable I2C port
	  I2C_Cmd(I2Cx, ENABLE);
 }






