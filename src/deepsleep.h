
#ifndef DeepSleepSeconds 
  #define DeepSleepSeconds 5
#endif

#define uS_TO_S_FACTOR 1000000  /* Conversion factor for micro seconds to seconds */

void DeepSleepInit() {  
  esp_sleep_wakeup_cause_t wakeup_reason;

  wakeup_reason = esp_sleep_get_wakeup_cause();

  String Ret = "ESP 32 DeepSleep : ";

  switch(wakeup_reason)
  {
    case ESP_SLEEP_WAKEUP_EXT0 :      Ret = "Wakeup caused by external signal using RTC_IO"   ; break;
    case ESP_SLEEP_WAKEUP_EXT1 :      Ret = "Wakeup caused by external signal using RTC_CNTL" ; break;
    case ESP_SLEEP_WAKEUP_TIMER :     Ret = "Wakeup caused by timer"                          ; break;
    case ESP_SLEEP_WAKEUP_TOUCHPAD :  Ret = "Wakeup caused by touchpad"                       ; break;
    case ESP_SLEEP_WAKEUP_ULP :       Ret = "Wakeup caused by ULP program"                    ; break;
    default :                         Ret = "Wakeup was not caused by deep sleep"             ; break;
  }

  esp_sleep_enable_timer_wakeup(DeepSleepSeconds * uS_TO_S_FACTOR);
  Serial.println(Ret + " -> Setup sleep for " + String(DeepSleepSeconds) + " Seconds");


  //esp_deep_sleep_pd_config(ESP_PD_DOMAIN_RTC_PERIPH, ESP_PD_OPTION_OFF);
  //Serial.println("Configured all RTC Peripherals to be powered down in sleep");


}
