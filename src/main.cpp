#include <Arduino.h>

#define DeepSleepSeconds   5
#define AwakePhaseSeconds      5
#include "deepsleep.h"


RTC_DATA_ATTR int bootCount = 0;
unsigned long  TimerAwakePhase = 0;

void setup(){
  Serial.begin(115200); while (!Serial) { delay(1);}



  // RTC_DATA_ATTR Var überlebt DeepSleep!
  ++bootCount;
  Serial.println("Wakeup... Boot number: " + String(bootCount));


  DeepSleepInit();

  TimerAwakePhase = millis() + ( AwakePhaseSeconds * 1000); 

}

void loop(){
  static unsigned long TimerTask  = 0 ;
  // Mach WAS immer

  if (millis() > TimerTask ) {
    Serial.println("Task...");
    TimerTask = millis() +  1000; 
  }

  if (millis() > TimerAwakePhase ) {
      // Erst mal Mach WAS Daten senden... DANN:  
      Serial.println("Sleeping...");
      Serial.flush(); 
      esp_deep_sleep_start();      
  }

}