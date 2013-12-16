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

	ITG3200_InitTypeDef ITG3200_InitStruct;
	ITG3200_InitStruct.Sample_Rate_Divider = 9;
	ITG3200_InitStruct.Full_Scale = ITG32000_DLPF_FS_FS_SEL_PLUS_MINUS_2000;
	ITG3200_InitStruct.Low_Pass_Freq = ITG3200_DLPF_FS_DLPF_CFG_5Hz;
	ITG3200_InitStruct.Interrupt_Config = ITG3200_INT_CFG_RAW_RDY_ENABLE;
	//ITG3200_InitStruct.Power_Config =
	ITG3200_InitStruct.Clock_Config = ITG3200_POWER_MGMT_CLK_SEL_INT_OSC;
	ITG3200_Init(&ITG3200_InitStruct);

	uint8_t devid;
	devid = ITG3200_ReadReg(ITG3200_WHO_AM_I_REG_ADDR);

	printf("DEVID : %i ", devid);

	int i;

	while (1)
	{
		for(i = 0; i < 1000; i++){

		}

		devid = ITG3200_ReadReg(ITG3200_WHO_AM_I_REG_ADDR);
		printf("DEVID : %i \r\n", devid);


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
