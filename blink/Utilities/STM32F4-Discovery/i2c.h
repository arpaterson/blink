/**
  ******************************************************************************
  * @file    i2c.h
  * @author  Anthony Paterson
  * @version V0.0.0
  * @date    15-OCtober-2013
  * @brief
  ******************************************************************************
  * @attention
  *
  *>
  ******************************************************************************
  */

/* Define to prevent recursive inclusion -------------------------------------*/
#ifndef I2C_H_
#define I2C_H_

#ifdef __cplusplus
 extern "C" {
#endif

 /* Includes ------------------------------------------------------------------*/
#include "stm32f4xx.h"
#include "i2c_conf.h"

 /** @addtogroup Utilities
   * @{
   */
 void I2C_LowLevel_Init();
 void I2C_Start(uint8_t address, uint8_t direction);
 void I2C_RepeatedStart(uint8_t address, uint8_t direction);
 void I2C_Stop();

 void I2C_Write(uint8_t data);
 uint32_t I2C_Write_Buf(uint8_t* buffer, uint32_t count);

 uint8_t I2C_Read_Ack();
 uint8_t I2C_Read_NAck();
 uint32_t I2C_Read_Buf(uint8_t* buffer, uint32_t count);

 void I2C_LowLevel_DeInit(void);

#ifdef __cplusplus
}
#endif

#endif /* I2C_H_ */
