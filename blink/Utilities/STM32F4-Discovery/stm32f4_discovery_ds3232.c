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

uint8_t DS3232_Get_Seconds(uint8_t regdata){

  uint8_t tens;
  uint8_t ones;
  uint8_t seconds;

  tens = ( (regdata & 0x70 ) >> 4 );
  ones = regdata & 0x0F;
  seconds = 10*tens + ones;

  return seconds;
}

uint8_t DS3232_Get_Minutes(uint8_t regdata){

  uint8_t tens;
  uint8_t ones;
  uint8_t minutes;

  tens = ( (regdata & 0x70 ) >> 4 );
  ones = regdata & 0x0F;
  minutes = 10*tens + ones;

  return minutes;
}

uint8_t DS3232_Get_Hours(uint8_t regdata){

  uint8_t tens;
  uint8_t ones;

  if ( DS3232_Get_Mode12Hr(regdata) ){
      tens = (regdata & 0x10) >> 4; // bit4 is tens, bit 5 is !am/pm
  } else{
      tens = (regdata & 0x30) >> 4; // bit5:4 is tens
  }

  // Get ones
  ones = (regdata & 0x0F);

  uint8_t hours = 10*tens + ones;
  return hours;
}

uint8_t DS3232_Get_Mode12Hr(uint8_t regdata){
  uint8_t mode12Hr = (regdata & 0x40) >> 6;
  return mode12Hr;
}

uint8_t DS3232_Get_PM(uint8_t regdata){
  uint8_t PM_flag;
  if( DS3232_Get_Mode12Hr(regdata) ){
      PM_flag = (regdata & 0x20) >> 5;
  }
  else{
      PM_flag = 0;
  }
  return PM_flag;
}


void DS3232_Get_Time(DS3232_TimeTypeDef * TimeStruct){
  uint8_t data[7];
  DS3232_ReadMulti(data, DS3232_SECONDS_REG_ADDR, 7);
  TimeStruct->PM        =       DS3232_Get_PM(data[2]);
  TimeStruct->Mode12Hour =       DS3232_Get_Mode12Hr(data[2]);
  TimeStruct->Hours     =       DS3232_Get_Hours(data[2]);
  TimeStruct->Minutes   =       DS3232_Get_Minutes(data[1]);
  TimeStruct->Seconds   =       DS3232_Get_Seconds(data[0]);

}

void DS3232_Get_Time_Str(char* timestr, unsigned int strlen){
  DS3232_TimeTypeDef TimeStruct;
  DS3232_Get_Time(&TimeStruct);
  if( TimeStruct.Mode12Hour && TimeStruct.PM){
      sprintf(timestr, "%02i:%02i:%02i PM", TimeStruct.Hours, TimeStruct.Minutes, TimeStruct.Seconds);
  }
  else if( TimeStruct.Mode12Hour && !TimeStruct.PM ){
      sprintf(timestr, "%02i:%02i:%02i AM", TimeStruct.Hours, TimeStruct.Minutes, TimeStruct.Seconds);
  }
  else{
      sprintf(timestr, "%02i:%02i:%02i", TimeStruct.Hours, TimeStruct.Minutes, TimeStruct.Seconds);
  }
}

uint8_t DS3232_Get_Day(uint8_t regdata){
    uint8_t day = (regdata & 0x07);
    return day;
}

void DS3232_Get_Date(DS3232_DateTypeDef * DateStruct){

}

void DS3232_Get_Date_Str(char * datestr, unsigned int strlen){

}

void DS3232_Set_Mode12Hr(){ //also ovrwrites hour data
  DS3232_WriteReg(DS3232_HOURS_REG_ADDR, 0x40);
}

void DS3232_Set_Mode24Hr(){ //also ovrwrites hour data
  DS3232_WriteReg(DS3232_HOURS_REG_ADDR, 0x00);
}

float DS3232_Get_Temp_C(){
  float temp;
  uint8_t data[2];
  DS3232_ReadMulti(data, DS3232_TEMP_MSB_REG_ADDR,2);
  short halfword = (data[0] << 8 ) | (data[1]);
  temp = halfword / 4;
  return temp;
}

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
 *
 * @param DS3232_Reg
 * @return
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
 *
 * @param retbuffer
 * @param startregaddr
 * @param count
 */
void DS3232_ReadMulti(uint8_t* retbuffer, uint8_t startregaddr, uint32_t count){
  /*
                    I2C_Start(ADXL345_I2C_7BIT_ADDRESS<<1, I2C_Direction_Transmitter);
                   I2C_Write(ADXL345_DATAX0_REG_ADDR);
                   I2C_RepeatedStart(ADXL345_I2C_7BIT_ADDRESS<<1, I2C_Direction_Receiver);
                   bytes_read = I2C_Read_Buf(buffer,2);
                   I2C_Stop();
  */

  //this should be moved to i2c source files
  //write target reg address
  uint8_t buffer[count];
  uint16_t bytes_read; //may not need to be as big as uint16_t

  I2C_Start(DS3232_I2C_7BIT_ADDRESS<<1, I2C_Direction_Transmitter);
  I2C_Write(startregaddr);
  I2C_RepeatedStart(DS3232_I2C_7BIT_ADDRESS<<1, I2C_Direction_Receiver);
  bytes_read = I2C_Read_Buf(buffer, count);
  //I2C_Stop(); not needed Read_Buf generates a stop. is readbuf using repeated starts?

  memcpy(retbuffer,buffer,count);

}

/**
 *
 * @param DS3232_Reg
 * @param DS3232_RegValue
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
