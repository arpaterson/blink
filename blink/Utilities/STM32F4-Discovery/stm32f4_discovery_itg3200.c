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
void I2C_Start(I2C_TypeDef* I2Cx, uint8_t address, uint8_t direction);
void I2C_Write(I2C_TypeDef* I2Cx, uint8_t data);
void I2C_Stop(I2C_TypeDef* I2Cx);
uint8_t I2C_Read_Ack(I2C_TypeDef* I2Cx);
uint8_t I2C_Read_NAck(I2C_TypeDef* I2Cx);
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
void ITG3200_LowLevel_Init(){

}

/**
  * @brief
  * @param
  * @param
  * @param
  * @retval
  */
void ITG3200_Init(){

}


/**
  * @brief
  * @param
  * @param
  * @param
  * @retval
  */
uint8_t ITG3200_ReadReg(uint8_t ITG3200_Reg){

}

/**
  * @brief
  * @param
  * @param
  * @param
  * @retval
  */
void ITG3200_WriteReg(uint8_t ITG3200_Reg, uint16_t ITG3200_RegValue){

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
