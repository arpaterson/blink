/**
  ******************************************************************************
  * @file    main.c 
  * @author  MCD Application Team
  * @version V1.0.0
  * @date    19-September-2011
  * @brief   Main program body
  ******************************************************************************
  * @attention
  *
  * THE PRESENT FIRMWARE WHICH IS FOR GUIDANCE ONLY AIMS AT PROVIDING CUSTOMERS
  * WITH CODING INFORMATION REGARDING THEIR PRODUCTS IN ORDER FOR THEM TO SAVE
  * TIME. AS A RESULT, STMICROELECTRONICS SHALL NOT BE HELD LIABLE FOR ANY
  * DIRECT, INDIRECT OR CONSEQUENTIAL DAMAGES WITH RESPECT TO ANY CLAIMS ARISING
  * FROM THE CONTENT OF SUCH FIRMWARE AND/OR THE USE MADE BY CUSTOMERS OF THE
  * CODING INFORMATION CONTAINED HEREIN IN CONNECTION WITH THEIR PRODUCTS.
  *
  * <h2><center>&copy; COPYRIGHT 2011 STMicroelectronics</center></h2>
  ******************************************************************************
  */ 

/* Includes ------------------------------------------------------------------*/
#include "main.h"

/** @addtogroup STM32F4-Discovery_Demo
  * @{
  */

/* Private typedef -----------------------------------------------------------*/
/* Private define ------------------------------------------------------------*/

/* Private macro -------------------------------------------------------------*/

/* Private variables ---------------------------------------------------------*/

/* Private function prototypes -----------------------------------------------*/

/* Private functions ---------------------------------------------------------*/



/**
  * @brief  Main program.
  * @param
  * @retval
  */
int main(void){

  /*!< At this stage the microcontroller clock setting is already configured,
	   this is done through SystemInit() function which is called from startup
	   file (startup_stm32f4xx.s) before to branch to application main.
	   To reconfigure the default setting of SystemInit() function, refer to
	   system_stm32f4xx.c file
	 */


	STM32f4_Discovery_LCD_Init();
	LCD_RGB_Test();

	STM32f4_Discovery_Debug_Init();
	/* Output a message on Hyperterminal using printf function */
	printf("\n\rUSART Printf Example: retarget the C library printf function to the USART\n\r");

	ADXL345_InitTypeDef ADXL345_InitStruct;
	//ADXL345_InitStruct.Output_Data_Rate = 	ADXL345_BW_RATE_400;
	ADXL345_InitStruct.Data_Format =		(	ADXL345_DATAFORMAT_Range_PLUS_MINUS_16g | \
												ADXL345_DATAFORMAT_FULL_RES_ENABLE
												);
	ADXL345_InitStruct.Power_Mode = 		(ADXL345_POWER_CTL_Measure_ENABLE | ADXL345_POWER_CTL_Wakeup_1Hz);
	ADXL345_InitStruct.Interrupt_Enable = 	(ADXL345_INT_ENABLE_DATA_READY_ENABLE);
	ADXL345_Init(&ADXL345_InitStruct);

	//read devid
	uint8_t devid;
	devid = ADXL345_ReadReg(ADXL345_DEVID_REG_ADDR);
	printf("DEVID : %i ", devid);

	//set xyz offset (debugging multibyte write).
	uint8_t ofsx = 0x08;
	uint8_t ofsy = 0x07;
	uint8_t ofsz = 0x01;
	ADXL345_WriteOffsets(ofsx,ofsy,ofsz);

	//read data (multibyte read)
	uint32_t offsets;
	while (1)
	{
		offsets = ADXL345_ReadOffsets();
		ofsx = ((offsets & 0x000000FF) );
		ofsy = ((offsets & 0x0000FF00) >> 8 );
		ofsz = ((offsets & 0x00FF0000) >> 16	);
		printf("%i	%i	%i	\n\r", ofsx,ofsy,ofsz); //full res mode maintains 4mg/LSB. range bits set range.
	}
}

#ifdef  USE_FULL_ASSERT

/**
  * @brief  Reports the name of the source file and the source line number
  *   where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t* file, uint32_t line)
{ 
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */

  /* Infinite loop */
  while (1)
  {
  }
}
#endif

/**
  * @}
  */


/******************* (C) COPYRIGHT 2011 STMicroelectronics *****END OF FILE****/
