/* OpenGarage Firmware
 *
 * OpenGarage macro defines and hardware pin assignments
 * Mar 2016 @ OpenGarage.io
 *
 * This file is part of the OpenGarage library
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see
 * <http://www.gnu.org/licenses/>.
 */

#ifndef _DEFINES_H
#define _DEFINES_H

/** Firmware version, hardware version, and maximal values */
#define OG_FWV    107   // Firmware version: 107 means 1.0.7

/** GPIO pins */
#define PIN_RELAY  15 //D8 on nodemcu
#define PIN_BUTTON  0
#define PIN_TRIG   12 //D6 on nodemcu
#define PIN_ECHO   14 //D5 on nodemcu
#define PIN_LED     2
#define PIN_RESET  16
#define PIN_BUZZER 13
#define PIN_SWITCH 4  //D2 on nodemcu

// Default device name
#define DEFAULT_NAME    "My OpenGarage"
// Default device key
#define DEFAULT_DKEY    "opendoor"
// Config file name
#define CONFIG_FNAME    "/config.dat"
// Log file name
#define LOG_FNAME       "/log.dat"

#define OG_ACC_LOCAL    0x00
#define OG_ACC_BOTH     0x01
#define OG_ACC_CLOUD    0x02

#define OG_MNT_CEILING  0x00
#define OG_MNT_SIDE     0x01
#define OG_SWITCH_LOW   0x02
#define OG_SWITCH_HIGH  0x03

#define OG_ALM_NONE     0x00
#define OG_ALM_5        0x01
#define OG_ALM_10       0x02

#define OG_MOD_AP       0xA9
#define OG_MOD_STA      0x2A

#define OG_AUTO_NONE    0x00
#define OG_AUTO_NOTIFY  0x01
#define OG_AUTO_CLOSE   0x02

//Automation Option C - Notify settings
#define OG_NOTIFY_NONE  0x00
#define OG_NOTIFY_DO    0x01
#define OG_NOTIFY_DC    0x02
#define OG_NOTIFY_VL    0x03
#define OG_NOTIFY_VA    0x04

#define OG_STATE_INITIAL        0
#define OG_STATE_CONNECTING     1
#define OG_STATE_CONNECTED      2
#define OG_STATE_TRY_CONNECT    3
#define OG_STATE_RESET          9
#define OG_STATE_RESTART        10

#define BLYNK_PIN_LED   V0
#define BLYNK_PIN_RELAY V1
#define BLYNK_PIN_LCD   V2
#define BLYNK_PIN_DIST  V3
#define BLYNK_PIN_RCNT  V4
#define BLYNK_PIN_IP    V5

#define MAX_LOG_RECORDS    100
#define ALARM_FREQ         1000
// door status histogram
// number of values (maximum is 8)
#define DOOR_STATUS_HIST_K  4
#define DOOR_STATUS_REMAIN_CLOSED 0
#define DOOR_STATUS_REMAIN_OPEN   1
#define DOOR_STATUS_JUST_OPENED   2
#define DOOR_STATUS_JUST_CLOSED   3
#define DOOR_STATUS_MIXED         4

typedef enum {
  OPTION_FWV = 0, // firmware version
  OPTION_ACC,     // accessbility
  OPTION_MNT,     // mount type
  OPTION_DTH,     // distance threshold door
  OPTION_VTH,     // distance threshold vehicle detection
  OPTION_RIV,     // read interval
  OPTION_ALM,     // alarm mode
  OPTION_HTP,     // http port
  OPTION_CDT,     // click delay time
  OPTION_MOD,     // mode
  OPTION_ATI,     // automation interval (in minutes)
  OPTION_ATO,     // automation options
  OPTION_ATIB,    // automation interval B (in hours)
  OPTION_ATOB,    // automation options B
  OPTION_ATOC,    // automation options C
  OPTION_USI,     // use static IP
  OPTION_SSID,    // wifi ssid
  OPTION_PASS,    // wifi password
  OPTION_AUTH,    // Blynk authentication token
  OPTION_DKEY,    // device key
  OPTION_NAME,    // device name
  OPTION_IFTT,    // IFTTT token
  OPTION_MQTT,    // MQTT IP
  OPTION_DVIP,    // device IP
  OPTION_GWIP,    // gateway IP
  OPTION_SUBN,    // subnet
  NUM_OPTIONS     // number of options
} OG_OPTION_enum;

// if button is pressed for at least 5 seconds, reset to AP mode
#define BUTTON_APRESET_TIMEOUT 4000
// if button is pressed for at least 10 seconds, factory reset
#define BUTTON_FACRESET_TIMEOUT  8000

#define LED_FAST_BLINK 100
#define LED_SLOW_BLINK 500

#define TIME_SYNC_TIMEOUT  1800 //Issues connecting to MQTT can throw off the time function, sync more often

/** Serial debug functions */
//#define SERIAL_DEBUG
#if defined(SERIAL_DEBUG)

  #define DEBUG_BEGIN(x)   { delay(2000); Serial.begin(x); }
  #define DEBUG_PRINT(x)   Serial.print(x)
  #define DEBUG_PRINTLN(x) Serial.println(x)

#else

  #define DEBUG_BEGIN(x)   {}
  #define DEBUG_PRINT(x)   {}
  #define DEBUG_PRINTLN(x) {}

#endif

typedef unsigned char byte;
typedef unsigned long ulong;
typedef unsigned int  uint;

#endif  // _DEFINES_H
