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
 *
 * @return
 */
uint8_t ITG3200_Get_DevID(){
  return ITG3200_ReadReg(ITG3200_WHO_AM_I_REG_ADDR);
}

/**
 *
 * @param id
 */
void ITG3200_Set_DevID(uint8_t id){
   ITG3200_WriteReg(ITG3200_WHO_AM_I_REG_ADDR, id);
 }

/**
 *
 * @return
 */
int16_t ITG3200_Get_Temp(){
  uint8_t data[2];
  ITG3200_ReadMulti(data,ITG3200_TEMP_OUT_H_REG_ADDR,2);
  int16_t temp = ( (data[0]) | (data[1]) );
  return temp;
}

uint16_t ITG3200_Calc_Sample_Rate(){

}

uint8_t ITG3200_Get_Sample_Rate_Divider(){
  return ITG3200_ReadReg(ITG3200_SAMPLE_RATE_DIVIDER_REG_ADDR);
}

void ITG3200_Set_Sample_Rate_Divider(uint8_t value){
  ITG3200_WriteReg(ITG3200_SAMPLE_RATE_DIVIDER_REG_ADDR,value);
}

uint8_t ITG3200_Get_DLPF_Bandwidth_Hz(){
  uint8_t data = ITG3200_ReadReg(ITG3200_DLPF_FS_REG_ADDR);
  data = data & 0x07; // mask DLPF_CFG bits from FS_SEL bits.
  switch(data){
    case ITG3200_DLPF_FS_DLPF_CFG_5Hz:
      return 5;
      break;
    case ITG3000_DLPF_FS_DLPF_CFG_10Hz:
      return 10;
      break;
    case ITG3000_DLPF_FS_DLPF_CFG_20Hz:
      return 20;
      break;
    case ITG3200_DLPF_FS_DLPF_CFG_42Hz:
      return 42;
      break;
    case ITG3200_DLPF_FS_DLPF_CFG_98Hz:
      return 98;
      break;
    case ITG3200_DLPF_FS_DLPF_CFG_188Hz:
      return 188;
      break;
    case ITG3200_DLPF_FS_DLPF_CFG_256Hz:
      return 256;
      break;
    case 7: // reserved. go to error.
    default:
      return 0; //error condition
  }
}

/**
 *
 * @param newDLPFbits
 */
void ITG3200_Set_DLPF_Bandwidth(uint8_t newDLPFbits){
  uint8_t regdata_current = ITG3200_ReadReg(ITG3200_DLPF_FS_REG_ADDR);
  uint8_t regdata_new = (regdata_current & 0xf8) | (newDLPFbits & 0x07);
  ITG3200_WriteReg(ITG3200_DLPF_FS_REG_ADDR,regdata_new);
}

/**
 *
 * @return
 */
uint16_t ITG3200_Get_Fullscale_Range(){
  uint8_t data = ITG3200_ReadReg(ITG3200_DLPF_FS_REG_ADDR);
    data = (data & 0x18) >> 3; // mask FS_SEL bits from DLPF_CFG bits and right shift.
    switch(data){
      case ITG32000_DLPF_FS_FS_SEL_PLUS_MINUS_2000:
        return 2000;
        break;
      //all other cases reserved.
      default:
        return 0; //error condition
    }
}

void ITG3200_Set_Fullscale_Range(uint8_t newFS_SELbits){
  uint8_t regdata_current = ITG3200_ReadReg(ITG3200_DLPF_FS_REG_ADDR);
  uint8_t regdata_new = ((regdata_current & 0xE7) | ( (newFS_SELbits<<3) & 0x18));
  ITG3200_WriteReg(ITG3200_DLPF_FS_REG_ADDR,regdata_new);
}

/**
 *
 * @return
 */
ITG3200_DataPointTypeDef ITG3200_Get_DataPoint(){
  ITG3200_DataPointTypeDef datapoint;
  uint8_t data[8];
  ITG3200_ReadMulti(data,ITG3200_TEMP_OUT_H_REG_ADDR,8);
  datapoint.Temp = ( (data[0] << 8) | (data[1]));
  datapoint.X = ( (data[2] << 8) | (data[3]));
  datapoint.Y = ( (data[4] << 8) | (data[5]));
  datapoint.Z = ( (data[6] << 8) | (data[7]));
  return datapoint;
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
 *
 * @param retbuffer
 * @param startregaddr
 * @param count
 */
void ITG3200_ReadMulti(uint8_t* retbuffer, uint8_t startregaddr, uint32_t count){
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

   I2C_Start(ITG3200_I2C_7BIT_ADDRESS<<1, I2C_Direction_Transmitter);
   I2C_Write(startregaddr);
   I2C_RepeatedStart(ITG3200_I2C_7BIT_ADDRESS<<1, I2C_Direction_Receiver);
   bytes_read = I2C_Read_Buf(buffer, count);
   //I2C_Stop(); not needed Read_Buf generates a stop. is readbuf using repeated starts?

   memcpy(retbuffer,buffer,count);

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
          * NOTE:       You cannot just tie Vlogic to Vdd.
          *             Vlogic must always be less than Vdd, and should rise after Vdd.
          *
          *
          * 1. TVDDR is VDD rise time: Time for VDD to rise from 10% to 90% of its final value
          * 2. TVDDR is <5msec
          * 3. TVLGR is VLOGIC rise time:
          *     Time for VLOGIC to rise from 10% to 90% of its final value
          * 4. TVLGR is <1msec
          * 5. TVLG-VDD is the delay from the start of VDD ramp to the start of VLOGIC rise
          * 6. TVLG-VDD is 0 to 20msec but VLOGIC amplitude must always be <VDD amplitude
          * 7. VDD and VLOGIC must be monotonic ramps
          */


          /* Configure the low level interface ---------------------------------------*/
          ITG3200_LowLevel_Init();

          /* Initialisation command sequence -----------------------------------------
           *    Minimum initialisation sequence:
           *            1.      Vs = ON. Vddio = ON
           *            2.      Wait 1.1ms         *
           *
           *            .       Write PWR_MGM register, configuring
           *                                    Hard reset to power on defaults
           *                                    disable low power sleep mode
           *                                    disable standby on all axis
           *                                    select a clock source power on default is int osc (unstable)
           *                                            (must? check pll is ready after selceting a new clock source)
           *
           *            .       Write Sample Rate Divider register
           *            .       Write DLPF_FS register, configuring Digital Low Pass Filter and Full Scale
           *                            FS_SEL:
           *                                    Power on default: 00h.
           *                                    Set to 03h for normal operation (2000deg/sec)
           *                            DLPF_CFG:
           *
           *
           *            .       Write INT_CFG register, power on default 00h
           *                            configure interrupt output pin polarity, drain, latching, clearing,
           *                            and triggering - when ready or when data available.
           *
           *            . Read status reg, check PLL is ready
           *--------------------------------------------------------------------------*/

          uint8_t       power_mgmt_opts =       ITG3200_InitStruct->Power_Config |
                                                                        ITG3200_InitStruct->Clock_Config
                                                                        ;

          uint8_t       interrupt_opts  =       ITG3200_InitStruct->Interrupt_Config;

          ITG3200_WriteReg(ITG3200_POWER_MGMT_REG_ADDR, power_mgmt_opts);
          ITG3200_WriteReg(ITG3200_INT_CFG_REG_ADDR, interrupt_opts);

          ITG3200_Set_Sample_Rate_Divider(ITG3200_InitStruct->Sample_Rate_Divider);
          ITG3200_Set_DLPF_Bandwidth(ITG3200_InitStruct->Low_Pass_Freq);
          ITG3200_Set_Fullscale_Range(ITG3200_InitStruct->Full_Scale);


}

/**
  * @brief
  * @param
  * @param
  * @param
  * @retval
  */
void ITG3200_LowLevel_Init(){
         GPIO_InitTypeDef      GPIO_InitStructure;

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
