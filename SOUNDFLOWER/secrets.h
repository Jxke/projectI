/************************ Adafruit IO Config *******************************/

// visit io.adafruit.com if you need to create an account,
// or if you need your Adafruit IO key.
#define IO_USERNAME  "jubnuggets"
#define IO_KEY       "9b0ee3706c3e48f091714a286da59598"

/******************************* WIFI **************************************/

#define WIFI_SSID       "SBG7580AC-5B6F"
#define WIFI_PASS       "3W2337102174"

// comment out the following two lines if you are using fona or ethernet
#include "AdafruitIO_WiFi.h"
AdafruitIO_WiFi io(IO_USERNAME, IO_KEY, WIFI_SSID, WIFI_PASS);
