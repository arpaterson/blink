/**
  ******************************************************************************
  * @file    i2c_conf.h
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

#ifndef I2C_CONF_H_
#define I2C_CONF_H_

// Default speed is 100kHz, you may define your own to the compiler
#ifndef I2Cx_ClockSpeed
 #define I2Cx_ClockSpeed						5000
#endif
// or enable fast mode
#ifdef USE_I2C_FASTMODE
 #define I2Cx_ClockSpeed						400000
#endif

//GPIO and I2C Peripheral (I2C3 Configuration)
#define I2Cx                      I2C1  //Selected I2C peripheral
#define RCC_APB1Periph_I2Cx       RCC_APB1Periph_I2C1 //Bus where the peripheral is connected
#define RCC_AHB1Periph_GPIO_SCL   RCC_AHB1Periph_GPIOB  //Bus for GPIO Port of SCL
#define RCC_AHB1Periph_GPIO_SDA   RCC_AHB1Periph_GPIOB  //Bus for GPIO Port of SDA
#define GPIO_AF_I2Cx              GPIO_AF_I2C1    //Alternate function for GPIO pins
#define GPIO_SCL                  GPIOB
#define GPIO_SDA                  GPIOB
#define GPIO_Pin_SCL              GPIO_Pin_6
#define GPIO_Pin_SDA              GPIO_Pin_7
#define GPIO_PinSource_SCL        GPIO_PinSource6
#define GPIO_PinSource_SDA        GPIO_PinSource7

#endif /* I2C_CONF_H_ */
