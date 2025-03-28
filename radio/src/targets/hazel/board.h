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

#include <inttypes.h>
#include "hal.h"
#include "hal/serial_port.h"
#include "hal/watchdog_driver.h"

#include "definitions.h"
#include "edgetx_constants.h"
#include "board_common.h"

#if defined(ROTARY_ENCODER_NAVIGATION)
// Rotary Encoder driver
void rotaryEncoderInit();
void rotaryEncoderCheck();
#endif

#define FLASHSIZE                       0x80000  // 512k
#define FLASH_PAGESIZE                  256
#define BOOTLOADER_SIZE                 0x8000
#define FIRMWARE_ADDRESS                0x08000000
#define FIRMWARE_LEN(fsize)             (fsize - BOOTLOADER_SIZE)
#define FIRMWARE_MAX_LEN                (FLASHSIZE - BOOTLOADER_SIZE)
#define APP_START_ADDRESS               (uint32_t)(FIRMWARE_ADDRESS + BOOTLOADER_SIZE)

#define LUA_MEM_MAX                     (0)    // max allowed memory usage for complete Lua  (in bytes), 0 means unlimited

# define BOOTLOADER_KEYS                0x42


extern uint16_t sessionTimer;

// Board driver
void boardInit();
void boardOff();

// PCBREV driver
enum {
  // X7
  PCBREV_X7_STD = 0,
  PCBREV_X7_40 = 1,
};

// Pulses driver
#define INTERNAL_MODULE_ON()   gpio_set(INTMODULE_PWR_GPIO)
#define INTERNAL_MODULE_OFF()  gpio_clear(INTMODULE_PWR_GPIO)
#define EXTERNAL_MODULE_ON()            EXTERNAL_MODULE_PWR_ON()
#define EXTERNAL_MODULE_OFF()           EXTERNAL_MODULE_PWR_OFF()

// Trainer driver
#define SLAVE_MODE()                    (g_model.trainerData.mode == TRAINER_MODE_SLAVE)

// POTS and SLIDERS default configuration

#if defined(FUNCTION_SWITCHES)

#define NUM_FUNCTIONS_SWITCHES 6
#define NUM_FUNCTIONS_GROUPS   3

#define DEFAULT_FS_CONFIG                                         \
  (SWITCH_2POS << 10) + (SWITCH_2POS << 8) + (SWITCH_2POS << 6) + \
      (SWITCH_2POS << 4) + (SWITCH_2POS << 2) + (SWITCH_2POS << 0)

#define DEFAULT_FS_GROUPS                                 \
  (1 << 10) + (1 << 8) + (1 << 6) + (1 << 4) + (1 << 2) + \
      (1 << 0)  // Set all FS to group 1 to act like a 6pos

#define DEFAULT_FS_STARTUP_CONFIG                         \
  ((FS_START_PREVIOUS << 10) + (FS_START_PREVIOUS << 8) + \
   (FS_START_PREVIOUS << 6) + (FS_START_PREVIOUS << 4) +  \
   (FS_START_PREVIOUS << 2) +                             \
   (FS_START_PREVIOUS << 0))  // keep last state by default

#else

#define NUM_FUNCTIONS_SWITCHES 0

#endif

#if defined(ADC_GPIO_PIN_STICK_TH)
  #define SURFACE_RADIO  true
#endif

#define HAS_HARDWARE_OPTIONS

PACK(typedef struct {
  uint8_t pcbrev:2;
}) HardwareOptions;

extern HardwareOptions hardwareOptions;

// Battery driver
#define BATT_SCALE                    123

#if defined(__cplusplus) && !defined(SIMU)
extern "C" {
#endif

// Power driver
#define SOFT_PWR_CTRL
#if defined(PWR_BUTTON_PRESS)
#  define STARTUP_ANIMATION
#endif

void pwrInit();
uint32_t pwrCheck();
void pwrOn();
void pwrOff();
bool pwrPressed();
bool pwrOffPressed();
void pwrResetHandler();
#define pwrForcePressed()   false

// Backlight driver
#if defined(OLED_SCREEN)
#define BACKLIGHT_DISABLE()             lcdSetRefVolt(0)
#define BACKLIGHT_FORCED_ON             255
#else
#define BACKLIGHT_DISABLE()             backlightDisable()
#define BACKLIGHT_FORCED_ON             101
#endif


void backlightInit();
void backlightDisable();
void backlightFullOn();
uint8_t isBacklightEnabled();

//Todo : Display
#if defined(OLED_SCREEN)
  #define BACKLIGHT_ENABLE() lcdSetRefVolt(currentBacklightBright)
#else
  void backlightEnable(uint8_t level);
  #define BACKLIGHT_ENABLE() backlightEnable(currentBacklightBright)
#endif

#if defined(__cplusplus) && !defined(SIMU)
}
#endif

// Debug driver
void debugPutc(const char c);

// Audio driver
void audioInit();
void audioEnd();

// Haptic driver
void hapticInit();
void hapticOff();
#if defined(HAPTIC_PWM)
  void hapticOn(uint32_t pwmPercent);
#else
  void hapticOn();
#endif

#define DEBUG_BAUDRATE                  115200
#define LUA_DEFAULT_BAUDRATE            115200

const etx_serial_port_t* auxSerialGetPort(int port_nr);

// USB Charger
#if defined(USB_CHARGER)
void usbChargerInit();
bool usbChargerLed();
#endif

// LED driver
void ledInit();
void ledOff();
void ledRed();
void ledGreen();
void ledBlue();

//Todo : Display

// LCD driver
#define LCD_W                           128
#define LCD_H                           64
#define LCD_DEPTH                       1
#define IS_LCD_RESET_NEEDED()           true

#if defined(OLED_SCREEN)
#define LCD_CONTRAST_MIN                2
#define LCD_CONTRAST_MAX                254
#else
#define LCD_CONTRAST_MIN                10
#define LCD_CONTRAST_MAX                30
#endif

#if defined(OLED_SCREEN)
  #define LCD_CONTRAST_DEFAULT          254 // full brightness
#else
  #define LCD_CONTRAST_DEFAULT          15
#endif

#if defined(OLED_SCREEN)
  // add offset 2px because driver (SH1106) of the 1.3 OLED is for a 132 display
  #define LCD_W_OFFSET                  0x02
#endif

#define IS_LCD_RESET_NEEDED()           true

void lcdInit();
void lcdInitFinish();
void lcdOff();

// TODO lcdRefreshWait() stub in simpgmspace
#if defined(LCD_DMA) && !defined(SIMU)
void lcdRefreshWait();
#else
#define lcdRefreshWait()
#endif
#if defined(SIMU) || !defined(__cplusplus)
void lcdRefresh();
#else
void lcdRefresh(bool wait=true); // TODO uint8_t wait to simplify this
#endif
void lcdSetRefVolt(unsigned char val);
#if LCD_W == 128
void lcdSetInvert(bool invert);
#endif
#ifdef __cplusplus
void lcdSetContrast(bool useDefault = false);
#endif
void lcdFlushed();

// Top LCD driver
#if defined(TOPLCD_GPIO)
void toplcdInit();
void toplcdOff();
void toplcdRefreshStart();
void toplcdRefreshEnd();
void setTopFirstTimer(int32_t value);
void setTopSecondTimer(uint32_t value);
void setTopRssi(uint32_t rssi);
void setTopBatteryState(int state, uint8_t blinking);
void setTopBatteryValue(uint32_t volts);
#endif

#if defined(CROSSFIRE)
#define TELEMETRY_FIFO_SIZE             128
#else
#define TELEMETRY_FIFO_SIZE             64
#endif

#define INTMODULE_FIFO_SIZE            128


// --- MOSFET ---- R2 --- MCU
//                     |__ R1 --- GND
//
#define VBAT_DIV_R1       160 // kOhms
#define VBAT_DIV_R2       499 // kOhms
#define VBAT_MOSFET_DROP   25 // * 10mV
//--- MOSFET ---- R2 --- MCU

#define BATTERY_DIVIDER 26214
#define VOLTAGE_DROP 20
//--- MOSFET ---- R2 --- MCU

#define NUM_TRIMS                               4
#define NUM_TRIMS_KEYS                          (NUM_TRIMS * 2)
