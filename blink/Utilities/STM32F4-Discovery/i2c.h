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
 void I2C_Write(uint8_t data);
 void I2C_Stop();
 uint8_t I2C_Read_Ack();
 uint8_t I2C_Read_NAck();


#ifdef __cplusplus
}
#endif

#endif /* I2C_H_ */
