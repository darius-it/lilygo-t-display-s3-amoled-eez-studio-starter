#include <LilyGo_AMOLED.h> 
#include <lvgl.h>
#include <TFT_eSPI.h>
#include <ui.h>
#include <LV_Helper.h>

#define LV_COLOR_SCREEN_TRANSP 1

// TODO: Replace with correct screen resolution
static const uint16_t screenWidth  = 536;
static const uint16_t screenHeight = 240;

LilyGo_Class amoled;

void setup()
{
  Serial.begin(115200);

  bool rslt = false;

  // Automatically determine the access device
  rslt = amoled.begin();
  if (!rslt) {
      while (1) {
          Serial.println("The board model cannot be detected, please raise the Core Debug Level to an error");
          delay(1000);
      }
  }

  beginLvglHelper(amoled); // Use LILYGO LVGL helper to init LVGL
  ui_init(); // Initialize EEZ Studio UI

  amoled.setHomeButtonCallback([](void *ptr) {
      Serial.println("Home button pressed");
  }, NULL);
}

void loop() {
  lv_timer_handler();

  ui_tick(); // Update UI
}
