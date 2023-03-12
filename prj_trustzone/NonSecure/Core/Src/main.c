/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include <stdio.h>
#include <string.h>

/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */
/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/

HASH_HandleTypeDef hhash;

RNG_HandleTypeDef hrng;

/* USER CODE BEGIN PV */

/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
static void MX_GPIO_Init(void);
static void MX_ICACHE_Init(void);
static void MX_HASH_Init(void);
static void MX_RNG_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */
#define INPUT_TAB_SIZE ((uint32_t)261) /* The size of the input data "aInput"  \
                                        */

__ALIGN_BEGIN static const uint8_t pKeyHASH[261] __ALIGN_END = {
    0x54, 0x68, 0x65, 0x20, 0x68, 0x61, 0x73, 0x68, 0x20, 0x70, 0x72, 0x6f,
    0x63, 0x65, 0x73, 0x73, 0x6f, 0x72, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20,
    0x66, 0x75, 0x6c, 0x6c, 0x79, 0x20, 0x63, 0x6f, 0x6d, 0x70, 0x6c, 0x69,
    0x61, 0x6e, 0x74, 0x20, 0x69, 0x6d, 0x70, 0x6c, 0x65, 0x6d, 0x65, 0x6e,
    0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x6f, 0x66, 0x20, 0x74, 0x68,
    0x65, 0x20, 0x73, 0x65, 0x63, 0x75, 0x72, 0x65, 0x20, 0x68, 0x61, 0x73,
    0x68, 0x20, 0x61, 0x6c, 0x67, 0x6f, 0x72, 0x69, 0x74, 0x68, 0x6d, 0x20,
    0x28, 0x53, 0x48, 0x41, 0x2d, 0x31, 0x29, 0x2c, 0x20, 0x74, 0x68, 0x65,
    0x20, 0x4d, 0x44, 0x35, 0x20, 0x28, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67,
    0x65, 0x2d, 0x64, 0x69, 0x67, 0x65, 0x73, 0x74, 0x20, 0x61, 0x6c, 0x67,
    0x6f, 0x72, 0x69, 0x74, 0x68, 0x6d, 0x20, 0x35, 0x29, 0x20, 0x68, 0x61,
    0x73, 0x68, 0x20, 0x61, 0x6c, 0x67, 0x6f, 0x72, 0x69, 0x74, 0x68, 0x6d,
    0x20, 0x61, 0x6e, 0x64, 0x20, 0x74, 0x68, 0x65, 0x20, 0x48, 0x4d, 0x41,
    0x43, 0x20, 0x28, 0x6b, 0x65, 0x79, 0x65, 0x64, 0x2d, 0x68, 0x61, 0x73,
    0x68, 0x20, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x20, 0x61, 0x75,
    0x74, 0x68, 0x65, 0x6e, 0x74, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e,
    0x20, 0x63, 0x6f, 0x64, 0x65, 0x29, 0x20, 0x61, 0x6c, 0x67, 0x6f, 0x72,
    0x69, 0x74, 0x68, 0x6d, 0x20, 0x73, 0x75, 0x69, 0x74, 0x61, 0x62, 0x6c,
    0x65, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x61, 0x20, 0x76, 0x61, 0x72, 0x69,
    0x65, 0x74, 0x79, 0x20, 0x6f, 0x66, 0x20, 0x61, 0x70, 0x70, 0x6c, 0x69,
    0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x73, 0x2e, 0x2a, 0x2a, 0x2a, 0x20,
    0x53, 0x54, 0x4d, 0x33, 0x32, 0x20, 0x2a, 0x2a, 0x2a};

__ALIGN_BEGIN const uint8_t aInput[INPUT_TAB_SIZE] __ALIGN_END = {
    0x54, 0x68, 0x65, 0x20, 0x68, 0x61, 0x73, 0x68, 0x20, 0x70, 0x72, 0x6f,
    0x63, 0x65, 0x73, 0x73, 0x6f, 0x72, 0x20, 0x69, 0x73, 0x20, 0x61, 0x20,
    0x66, 0x75, 0x6c, 0x6c, 0x79, 0x20, 0x63, 0x6f, 0x6d, 0x70, 0x6c, 0x69,
    0x61, 0x6e, 0x74, 0x20, 0x69, 0x6d, 0x70, 0x6c, 0x65, 0x6d, 0x65, 0x6e,
    0x74, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x20, 0x6f, 0x66, 0x20, 0x74, 0x68,
    0x65, 0x20, 0x73, 0x65, 0x63, 0x75, 0x72, 0x65, 0x20, 0x68, 0x61, 0x73,
    0x68, 0x20, 0x61, 0x6c, 0x67, 0x6f, 0x72, 0x69, 0x74, 0x68, 0x6d, 0x20,
    0x28, 0x53, 0x48, 0x41, 0x2d, 0x31, 0x29, 0x2c, 0x20, 0x74, 0x68, 0x65,
    0x20, 0x4d, 0x44, 0x35, 0x20, 0x28, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67,
    0x65, 0x2d, 0x64, 0x69, 0x67, 0x65, 0x73, 0x74, 0x20, 0x61, 0x6c, 0x67,
    0x6f, 0x72, 0x69, 0x74, 0x68, 0x6d, 0x20, 0x35, 0x29, 0x20, 0x68, 0x61,
    0x73, 0x68, 0x20, 0x61, 0x6c, 0x67, 0x6f, 0x72, 0x69, 0x74, 0x68, 0x6d,
    0x20, 0x61, 0x6e, 0x64, 0x20, 0x74, 0x68, 0x65, 0x20, 0x48, 0x4d, 0x41,
    0x43, 0x20, 0x28, 0x6b, 0x65, 0x79, 0x65, 0x64, 0x2d, 0x68, 0x61, 0x73,
    0x68, 0x20, 0x6d, 0x65, 0x73, 0x73, 0x61, 0x67, 0x65, 0x20, 0x61, 0x75,
    0x74, 0x68, 0x65, 0x6e, 0x74, 0x69, 0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e,
    0x20, 0x63, 0x6f, 0x64, 0x65, 0x29, 0x20, 0x61, 0x6c, 0x67, 0x6f, 0x72,
    0x69, 0x74, 0x68, 0x6d, 0x20, 0x73, 0x75, 0x69, 0x74, 0x61, 0x62, 0x6c,
    0x65, 0x20, 0x66, 0x6f, 0x72, 0x20, 0x61, 0x20, 0x76, 0x61, 0x72, 0x69,
    0x65, 0x74, 0x79, 0x20, 0x6f, 0x66, 0x20, 0x61, 0x70, 0x70, 0x6c, 0x69,
    0x63, 0x61, 0x74, 0x69, 0x6f, 0x6e, 0x73, 0x2e, 0x2a, 0x2a, 0x2a, 0x20,
    0x53, 0x54, 0x4d, 0x33, 0x32, 0x20, 0x2a, 0x2a, 0x2a};

__ALIGN_BEGIN static uint8_t aHashDigest[32] __ALIGN_END;
		
void print_hex(uint8_t *buf, uint32_t len) {
  for (uint32_t i = 0; i < len; ++i) {
    printf("%02X", *(buf + i));
  }
  printf("\r\n");
}

RNG_HandleTypeDef hrng;

/**
  * @brief RNG Initialization Function
  * @param None
  * @retval None
  */
//static void MX_RNG_Init(void)
//{

//  /* USER CODE BEGIN RNG_Init 0 */

//  /* USER CODE END RNG_Init 0 */

//  /* USER CODE BEGIN RNG_Init 1 */

//  /* USER CODE END RNG_Init 1 */
//  hrng.Instance = RNG;
//  hrng.Init.ClockErrorDetection = RNG_CED_ENABLE;
//  if (HAL_RNG_Init(&hrng) != HAL_OK)
//  {
//    Error_Handler();
//  }
//  /* USER CODE BEGIN RNG_Init 2 */

//  /* USER CODE END RNG_Init 2 */

//}

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  MX_ICACHE_Init();
  MX_HASH_Init();
  MX_RNG_Init();
  /* USER CODE BEGIN 2 */

  MX_RNG_Init();

  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
	  printf("Core Freq:%u Hz\n", SystemCoreClock);
		uint32_t random32bit;
HAL_StatusTypeDef halStatus;
/****************************************************************************/
  /*************************** Hash-SHA1
   * ***************************************/
  /****************************************************************************/
  if (HAL_HASH_DeInit(&hhash) != HAL_OK) {
    Error_Handler();
  }
  MX_HASH_Init();

  if (HAL_HASH_SHA1_Start(&hhash, (uint8_t *)aInput, INPUT_TAB_SIZE,
                          aHashDigest, 0xFF) != HAL_OK) {
    Error_Handler();
  }
  printf("Hash-SHA1 test passed.\n");
  print_hex(aHashDigest, 20);

  /****************************************************************************/
  /*************************** Hash-MD5 ***************************************/
  /****************************************************************************/
  if (HAL_HASH_DeInit(&hhash) != HAL_OK) {
    Error_Handler();
  }
  MX_HASH_Init();

  if (HAL_HASH_MD5_Start(&hhash, (uint8_t *)aInput, INPUT_TAB_SIZE, aHashDigest,
                         0xFF) != HAL_OK) {
    Error_Handler();
  }
  printf("Hash-MD5 test passed.\n");
  print_hex(aHashDigest, 16);
  /****************************************************************************/
  /*************************** Hash-SHA224
   * ***************************************/
  /****************************************************************************/
  if (HAL_HASH_DeInit(&hhash) != HAL_OK) {
    Error_Handler();
  }
  MX_HASH_Init();

  if (HAL_HASHEx_SHA224_Start(&hhash, (uint8_t *)aInput, INPUT_TAB_SIZE,
                              aHashDigest, 0xFF) != HAL_OK) {
    Error_Handler();
  }
  printf("Hash-SHA224 test passed.\n");
  print_hex(aHashDigest, 28);

  /****************************************************************************/
  /*************************** Hash-SHA256
   * ***************************************/
  /****************************************************************************/
  if (HAL_HASH_DeInit(&hhash) != HAL_OK) {
    Error_Handler();
  }
  MX_HASH_Init();

  if (HAL_HASHEx_SHA256_Start(&hhash, (uint8_t *)aInput, INPUT_TAB_SIZE,
                              aHashDigest, 0xFF) != HAL_OK) {
    Error_Handler();
  }
  printf("Hash-SHA256 test passed.\n");
  print_hex(aHashDigest, 32);
	
  while (1)
  {
		halStatus = HAL_RNG_GenerateRandomNumber(&hrng, &random32bit);		  
		printf("%p %u %u\n", main, SystemCoreClock, HAL_GetTick());
		printf("%u, %p %08X\n", halStatus, &random32bit, random32bit); 
		HAL_Delay(3000);

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief HASH Initialization Function
  * @param None
  * @retval None
  */
static void MX_HASH_Init(void)
{

  /* USER CODE BEGIN HASH_Init 0 */

  /* USER CODE END HASH_Init 0 */

  /* USER CODE BEGIN HASH_Init 1 */

  /* USER CODE END HASH_Init 1 */
  hhash.Init.DataType = HASH_DATATYPE_8B;
  if (HAL_HASH_Init(&hhash) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN HASH_Init 2 */

  /* USER CODE END HASH_Init 2 */

}

/**
  * @brief ICACHE Initialization Function
  * @param None
  * @retval None
  */
static void MX_ICACHE_Init(void)
{

  /* USER CODE BEGIN ICACHE_Init 0 */

  /* USER CODE END ICACHE_Init 0 */

  /* USER CODE BEGIN ICACHE_Init 1 */

  /* USER CODE END ICACHE_Init 1 */

  /** Enable instruction cache in 1-way (direct mapped cache)
  */
  if (HAL_ICACHE_ConfigAssociativityMode(ICACHE_1WAY) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_ICACHE_Enable() != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN ICACHE_Init 2 */

  /* USER CODE END ICACHE_Init 2 */

}

/**
  * @brief RNG Initialization Function
  * @param None
  * @retval None
  */
static void MX_RNG_Init(void)
{

  /* USER CODE BEGIN RNG_Init 0 */

  /* USER CODE END RNG_Init 0 */

  /* USER CODE BEGIN RNG_Init 1 */

  /* USER CODE END RNG_Init 1 */
  hrng.Instance = RNG;
  hrng.Init.ClockErrorDetection = RNG_CED_ENABLE;
  if (HAL_RNG_Init(&hrng) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN RNG_Init 2 */

  /* USER CODE END RNG_Init 2 */

}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
