/*
 * Copyright (C) EdgeTX
 *
 * Based on code named
 *   opentx - https://github.com/opentx/opentx
 *   th9x - http://code.google.com/p/th9x
 *   er9x - http://code.google.com/p/er9x
 *   gruvin9x - http://code.google.com/p/gruvin9x
 *
 * License GPLv2: http://www.gnu.org/licenses/gpl-2.0.html
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License version 2 as
 * published by the Free Software Foundation.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 */

#pragma once

#if defined(STM32F4)
  #define CPU_FREQ            168000000
  #define PERI1_FREQUENCY     42000000
  #define PERI2_FREQUENCY     84000000
  #define TIMER_MULT_APB1     2
  #define TIMER_MULT_APB2     2
#else
  #define CPU_FREQ            120000000
  #define PERI1_FREQUENCY     30000000
  #define PERI2_FREQUENCY     60000000
  #define TIMER_MULT_APB1     2
  #define TIMER_MULT_APB2     2
#endif

#define TELEMETRY_EXTI_PRIO             0 // required for soft serial

// Keys
#define KEYS_GPIO_REG_PAGEUP          GPIOD
#define KEYS_GPIO_PIN_PAGEUP          LL_GPIO_PIN_3  // PD.03
#define KEYS_GPIO_REG_PAGEDN          GPIOD
#define KEYS_GPIO_PIN_PAGEDN          LL_GPIO_PIN_7  // PD.07
#define KEYS_GPIO_REG_EXIT            GPIOC
#define KEYS_GPIO_PIN_EXIT            LL_GPIO_PIN_5  // PC.05

#define KEYS_GPIO_REG_PAGEDN          GPIOD
#define KEYS_GPIO_PIN_PAGEDN          LL_GPIO_PIN_3  // PD.03
#define KEYS_GPIO_REG_MENU            GPIOD
#define KEYS_GPIO_PIN_MENU            LL_GPIO_PIN_7  // PD.07
#define KEYS_GPIO_REG_EXIT            GPIOD
#define KEYS_GPIO_PIN_EXIT            LL_GPIO_PIN_2  // PD.02
#define KEYS_GPIO_REG_ENTER           GPIOE
#define KEYS_GPIO_PIN_ENTER           LL_GPIO_PIN_10 // PE.10

// Trims

#define TRIMS_GPIO_REG_LHL            GPIOD
#define TRIMS_GPIO_PIN_LHL            LL_GPIO_PIN_15 // PD.15
#define TRIMS_GPIO_REG_LHR            GPIOC
#define TRIMS_GPIO_PIN_LHR            LL_GPIO_PIN_1  // PC.01
#define TRIMS_GPIO_REG_LVD            GPIOE
#define TRIMS_GPIO_PIN_LVD            LL_GPIO_PIN_6  // PE.06
#define TRIMS_GPIO_REG_LVU            GPIOE
#define TRIMS_GPIO_PIN_LVU            LL_GPIO_PIN_5  // PE.05
#define TRIMS_GPIO_REG_RVD            GPIOC
#define TRIMS_GPIO_PIN_RVD            LL_GPIO_PIN_3  // PC.03
#define TRIMS_GPIO_REG_RHL            GPIOE
#define TRIMS_GPIO_PIN_RHL            LL_GPIO_PIN_3  // PE.03
#define TRIMS_GPIO_REG_RVU            GPIOC
#define TRIMS_GPIO_PIN_RVU            LL_GPIO_PIN_2  // PC.02
#define TRIMS_GPIO_REG_RHR            GPIOE
#define TRIMS_GPIO_PIN_RHR            LL_GPIO_PIN_4  // PE.04


// Switches

#define SWITCHES_GPIO_REG_A           GPIOC
#define SWITCHES_GPIO_PIN_A           LL_GPIO_PIN_13  // PC.13

  // ADC based switch

#define SWITCHES_GPIO_REG_A_L         GPIOE
#define SWITCHES_GPIO_PIN_A_L         LL_GPIO_PIN_7  // PE.07
#define SWITCHES_GPIO_REG_A_H         GPIOE
#define SWITCHES_GPIO_PIN_A_H         LL_GPIO_PIN_13 // PE.13

// ADC based switch

#define SWITCHES_GPIO_REG_C_L         GPIOD
#define SWITCHES_GPIO_PIN_C_L         LL_GPIO_PIN_11 // PD.11
#define SWITCHES_GPIO_REG_C_H       GPIOE
#define SWITCHES_GPIO_PIN_C_H       LL_GPIO_PIN_0  // PE.00

// ADC based switch

#define SWITCHES_GPIO_REG_D_L         GPIOE
#define SWITCHES_GPIO_PIN_D_L         LL_GPIO_PIN_1  // PE.01
#define SWITCHES_GPIO_REG_D_H         GPIOE
#define SWITCHES_GPIO_PIN_D_H         LL_GPIO_PIN_2  // PE.02


#define SWITCHES_GPIO_REG_F           GPIOE
#define SWITCHES_GPIO_PIN_F           LL_GPIO_PIN_14 // PE.14

#define SWITCHES_GPIO_REG_H           GPIOD
#define SWITCHES_GPIO_PIN_H           LL_GPIO_PIN_14 // PD.14

#define ADC_SAMPTIME                    LL_ADC_SAMPLINGTIME_28CYCLES
#define ADC_CHANNEL_RTC_BAT             LL_ADC_CHANNEL_VBAT


#define HARDWARE_POT1
#define HARDWARE_POT2
#define ADC_GPIO_PIN_STICK_RV         LL_GPIO_PIN_0  // PA.00
#define ADC_GPIO_PIN_STICK_RH         LL_GPIO_PIN_1  // PA.01
#define ADC_GPIO_PIN_STICK_LV         LL_GPIO_PIN_2  // PA.02
#define ADC_GPIO_PIN_STICK_LH         LL_GPIO_PIN_3  // PA.03
#define ADC_CHANNEL_STICK_RV          LL_ADC_CHANNEL_0  // ADC1_IN0
#define ADC_CHANNEL_STICK_RH          LL_ADC_CHANNEL_1  // ADC1_IN1
#define ADC_CHANNEL_STICK_LV          LL_ADC_CHANNEL_2  // ADC1_IN2
#define ADC_CHANNEL_STICK_LH          LL_ADC_CHANNEL_3  // ADC1_IN3
#define ADC_GPIO_PIN_POT1             LL_GPIO_PIN_0  // PB.00

#define ADC_GPIO_PIN_BATT             LL_GPIO_PIN_0  // PC.00

#define ADC_DIRECTION {-1,1,-1,1,  1,1,  1,  1}

// PWR and LED driver

#define PWR_SWITCH_GPIO               GPIO_PIN(GPIOD, 1)  // PD.01
#define PWR_ON_GPIO                   GPIO_PIN(GPIOD, 0)  // PD.00

#define STATUS_LEDS
#define GPIO_LED_GPIO_ON              gpio_set
#define GPIO_LED_GPIO_OFF             gpio_clear
#define LED_GREEN_GPIO                GPIO_PIN(GPIOC, 4)  // PC.04
#define LED_RED_GPIO                  GPIO_PIN(GPIOC, 5)  // PC.05
#define LED_BLUE_GPIO                 GPIO_PIN(GPIOB, 1)  // PB.01

  // LED Strip
#if defined(RGBLEDS)
#define LED_STRIP_LENGTH                  1
#define LED_STRIP_GPIO                    GPIO_PIN(GPIOA, 10) // PA.10 / TIM1_CH3
#define LED_STRIP_GPIO_AF                 LL_GPIO_AF_1
#define LED_STRIP_TIMER                   TIM1
#define LED_STRIP_TIMER_FREQ              (PERI2_FREQUENCY * TIMER_MULT_APB2)
#define LED_STRIP_TIMER_CHANNEL           LL_TIM_CHANNEL_CH3
#define LED_STRIP_TIMER_DMA               DMA2
#define LED_STRIP_TIMER_DMA_CHANNEL       LL_DMA_CHANNEL_6
#define LED_STRIP_TIMER_DMA_STREAM        LL_DMA_STREAM_5
#define LED_STRIP_TIMER_DMA_IRQn          DMA2_Stream5_IRQn
#define LED_STRIP_TIMER_DMA_IRQHandler    DMA2_Stream5_IRQHandler
#define LED_STRIP_REFRESH_PERIOD          50  //ms
#endif

#if defined(FUNCTION_SWITCHES)

#define GPIO_FSLED_GPIO_ON            GPIO_SetBits
#define GPIO_FSLED_GPIO_OFF           GPIO_ResetBits
#define FSLED_GPIO                    GPIOF
#define FSLED_GPIO_PIN_1              GPIO_PIN(FSLED_GPIO, 5)
#define FSLED_GPIO_PIN_2              GPIO_PIN(FSLED_GPIO, 4)
#define FSLED_GPIO_PIN_3              GPIO_PIN(FSLED_GPIO, 3)
#define FSLED_GPIO_PIN_4              GPIO_PIN(FSLED_GPIO, 2)
#define FSLED_GPIO_PIN_5              GPIO_PIN(FSLED_GPIO, 1)
#define FSLED_GPIO_PIN_6              GPIO_PIN(FSLED_GPIO, 0)
#endif

// Internal Module

#define INTMODULE_PWR_GPIO               GPIO_PIN(GPIOD, 15) // PD.15
#define INTMODULE_TX_GPIO                GPIO_PIN(GPIOA, 10) // PA.10
#define INTMODULE_TX_GPIO_AF             LL_GPIO_AF_1
#define INTMODULE_TIMER                  TIM1
#define INTMODULE_TIMER_Channel          LL_TIM_CHANNEL_CH3
#define INTMODULE_TIMER_IRQn             TIM1_UP_TIM10_IRQn
#define INTMODULE_TIMER_IRQHandler       TIM1_UP_TIM10_IRQHandler
#define INTMODULE_TIMER_DMA              DMA2
#define INTMODULE_TIMER_DMA_CHANNEL      LL_DMA_CHANNEL_6
#define INTMODULE_TIMER_DMA_STREAM       LL_DMA_STREAM_5
#define INTMODULE_TIMER_DMA_STREAM_IRQn  DMA2_Stream5_IRQn
#define INTMODULE_TIMER_DMA_IRQHandler   DMA2_Stream5_IRQHandler
#define INTMODULE_TIMER_FREQ             (PERI2_FREQUENCY * TIMER_MULT_APB2)

// External Module :Todo



// Trainer Port

#define TRAINER_TIMER                 TIM3
#define TRAINER_TIMER_IRQn            TIM3_IRQn
#define TRAINER_GPIO_AF               LL_GPIO_AF_2
#define TRAINER_TIMER_IRQn            TIM3_IRQn
#define TRAINER_TIMER_IRQHandler      TIM3_IRQHandler
#define TRAINER_TIMER_FREQ            (PERI1_FREQUENCY * TIMER_MULT_APB1)

// Serial Port

#define HARDWARE_TRAINER_AUX_SERIAL
#define AUX_SERIAL_GPIO                   GPIOB
#define AUX_SERIAL_TX_GPIO                GPIO_PIN(GPIOB, 10) // PB.10
#define AUX_SERIAL_RX_GPIO                GPIO_PIN(GPIOB, 11) // PB.11
#define AUX_SERIAL_USART                  USART3
#define AUX_SERIAL_USART_IRQn             USART3_IRQn
#define AUX_SERIAL_DMA_RX                 DMA1
#define AUX_SERIAL_DMA_RX_STREAM          LL_DMA_STREAM_1
#define AUX_SERIAL_DMA_RX_CHANNEL         LL_DMA_CHANNEL_4

// Telemetry
#define TELEMETRY_DIR_GPIO              GPIO_PIN(GPIOD, 4) // PD.04
#define TELEMETRY_SET_INPUT           0
#define TELEMETRY_TX_GPIO               GPIO_PIN(GPIOD, 5) // PD.05
#define TELEMETRY_RX_GPIO               GPIO_PIN(GPIOD, 6) // PD.06
#define TELEMETRY_USART                 USART2
#define TELEMETRY_DMA                   DMA1
#define TELEMETRY_DMA_Stream_TX         LL_DMA_STREAM_6
#define TELEMETRY_DMA_Channel_TX        LL_DMA_CHANNEL_4
#define TELEMETRY_DMA_TX_Stream_IRQ     DMA1_Stream6_IRQn
#define TELEMETRY_DMA_TX_IRQHandler     DMA1_Stream6_IRQHandler
#define TELEMETRY_DMA_TX_FLAG_TC        DMA_IT_TCIF6
#define TELEMETRY_USART_IRQHandler      USART2_IRQHandler
#define TELEMETRY_USART_IRQn            USART2_IRQn
#define TELEMETRY_EXTI_PORT             LL_SYSCFG_EXTI_PORTD
#define TELEMETRY_EXTI_SYS_LINE         LL_SYSCFG_EXTI_LINE6
#define TELEMETRY_EXTI_LINE             LL_EXTI_LINE_6
#define TELEMETRY_EXTI_TRIGGER          LL_EXTI_TRIGGER_RISING
// TELEMETRY_EXTI IRQ
#if !defined(USE_EXTI9_5_IRQ)
  #define USE_EXTI9_5_IRQ
#endif
// overwrite priority
#undef EXTI9_5_IRQ_Priority
#define EXTI9_5_IRQ_Priority            TELEMETRY_EXTI_PRIO

#define TELEMETRY_TIMER                 TIM11
#define TELEMETRY_TIMER_IRQn            TIM1_TRG_COM_TIM11_IRQn
#define TELEMETRY_TIMER_IRQHandler      TIM1_TRG_COM_TIM11_IRQHandler

// Software IRQ (Prio 5 -> FreeRTOS compatible)
#define TELEMETRY_RX_FRAME_EXTI_LINE    LL_EXTI_LINE_4
#define USE_EXTI4_IRQ
#define EXTI4_IRQ_Priority 5

// USB Charger
#if defined(USB_CHARGER)
  #define USB_CHARGER_GPIO              GPIO_PIN(GPIOB, 5)
#endif

// S.Port update connector

#define SPORT_MAX_BAUDRATE            400000

// Heartbeat for iXJT / ISRM synchro
#define INTMODULE_HEARTBEAT_TRIGGER               GPIO_FALLING
#if !defined(HARDWARE_EXTERNAL_MODULE)
#endif

// Trainer / Trainee from the module bay : TODO


// USB
#define USB_GPIO_VBUS                   GPIO_PIN(GPIOA, 9)  // PA.09
#define USB_GPIO_DM                     GPIO_PIN(GPIOA, 11) // PA.11
#define USB_GPIO_DP                     GPIO_PIN(GPIOA, 12) // PA.12
#define USB_GPIO_AF                     GPIO_AF10

// BackLight

// No backlight: OLED display

#define BACKLIGHT_TIMER_FREQ          (PERI1_FREQUENCY * TIMER_MULT_APB1)
#define BACKLIGHT_TIMER               TIM4
#define BACKLIGHT_GPIO                GPIO_PIN(GPIOD, 13) // PD.13
#define BACKLIGHT_GPIO_AF             GPIO_AF2
#define BACKLIGHT_CCMR1               TIM_CCMR1_OC2M_1 | TIM_CCMR1_OC2M_2 // Channel2, PWM
#define BACKLIGHT_CCER                TIM_CCER_CC2E
#define BACKLIGHT_COUNTER_REGISTER    BACKLIGHT_TIMER->CCR2

// LCD driver

#define LCD_MOSI_GPIO                 GPIO_PIN(GPIOC, 3)  // PC.3
#define LCD_CLK_GPIO                  GPIO_PIN(GPIOB, 10) // PB.10
#define LCD_A0_GPIO                   GPIO_PIN(GPIOE, 12) // PE.12 (DC)
#define LCD_NCS_GPIO                  GPIO_PIN(GPIOE, 14) // PE.14
#define LCD_RST_GPIO                  GPIO_PIN(GPIOE, 11) // PE.11

#define LCD_DMA                       DMA1
#define LCD_DMA_Stream                DMA1_Stream7
#define LCD_DMA_Stream_IRQn           DMA1_Stream7_IRQn
#define LCD_DMA_Stream_IRQHandler     DMA1_Stream7_IRQHandler
#define LCD_DMA_FLAGS                 (DMA_HIFCR_CTCIF7 | DMA_HIFCR_CHTIF7 | DMA_HIFCR_CTEIF7 | DMA_HIFCR_CDMEIF7 | DMA_HIFCR_CFEIF7)
#define LCD_DMA_FLAG_INT              DMA_HIFCR_CTCIF7
#define LCD_SPI                       SPI3
#define LCD_GPIO_AF                   GPIO_AF6

#if defined(SSD1309_LCD)
  #define LCD_SPI_PRESCALER             SPI_CR1_BR_1
#else
  #define LCD_SPI_PRESCALER             0
#endif

// I2C Bus 1: EEPROM and CAT5137 digital pot for volume control :TODO


// EEPROM

#define EEPROM_WP_GPIO                GPIOB
#define EEPROM_WP_GPIO_PIN            LL_GPIO_PIN_9  // PB.09

// I2C Volume control:TODO

#define I2C_B1_CLK_RATE                 400000

// EEPROM
#define EEPROM_I2C_ADDRESS              0x51
#define EEPROM_I2C_BUS                  I2C_Bus_1
#define EEPROM_PAGESIZE                 64
#define EEPROM_SIZE                     (32*1024)

// Second I2C Bus: IMU : TODO


// SD - SPI2

#define SD_PRESENT_GPIO           GPIO_PIN(GPIOD, 9)  // PD.09
#define STORAGE_USE_SDCARD_SPI

#define SD_GPIO_PIN_CS                  GPIO_PIN(GPIOC, 11) // PC.11
#define SD_GPIO_PIN_SCK                 GPIO_PIN(GPIOC, 12) // PC.12
#define SD_GPIO_PIN_MISO                GPIO_PIN(GPIOC, 8) // PC.8
#define SD_GPIO_PIN_MOSI                GPIO_PIN(GPIOD, 2) // PD.2

#define SD_SPI                          SPI2
#define SD_SPI_DMA                      DMA1
#define SD_SPI_DMA_RX_STREAM            LL_DMA_STREAM_3
#define SD_SPI_DMA_TX_STREAM            LL_DMA_STREAM_4
#define SD_SPI_DMA_CHANNEL              LL_DMA_CHANNEL_0

// Audio
#define AUDIO_RCC_APB1Periph            LL_APB1_GRP1_PERIPH_DAC1
#define AUDIO_OUTPUT_GPIO               GPIO_PIN(GPIOA, 4)
#define AUDIO_DMA                       DMA1
#define AUDIO_TIM_IRQn                  TIM6_DAC_IRQn
#define AUDIO_TIM_IRQHandler            TIM6_DAC_IRQHandler
#define AUDIO_DMA_Stream                DMA1_Stream5
#define AUDIO_DMA_Stream_IRQn           DMA1_Stream5_IRQn
#define AUDIO_DMA_Stream_IRQHandler     DMA1_Stream5_IRQHandler
#define AUDIO_TIMER                     TIM6

// Bluetooth : TODO


// Millisecond timer
#define MS_TIMER                        TIM14
#define MS_TIMER_IRQn                   TIM8_TRG_COM_TIM14_IRQn
#define MS_TIMER_IRQHandler             TIM8_TRG_COM_TIM14_IRQHandler

// Mixer scheduler timer
#define MIXER_SCHEDULER_TIMER                TIM12
#define MIXER_SCHEDULER_TIMER_FREQ           (PERI1_FREQUENCY * TIMER_MULT_APB1)
#define MIXER_SCHEDULER_TIMER_IRQn           TIM8_BRK_TIM12_IRQn
#define MIXER_SCHEDULER_TIMER_IRQHandler     TIM8_BRK_TIM12_IRQHandler
