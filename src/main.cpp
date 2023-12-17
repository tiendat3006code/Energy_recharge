#include <Arduino.h>
#include "../include/lcd.h"
#include "../include/loadcell.h"

lcd lcd1;
loadcell load;
unsigned long currentTime = 0;
bool isOpen = false;

// put function declarations here:
//*Lay gia tri voltage dau vao Arduino don vi mV
int getVoltage() {
   int resistorResult = analogRead(RESISTOR_PIN);
   Serial.print("Resistor value: ");
   Serial.println(resistorResult);
   int voltage = map(resistorResult, 0, 785, 0, 3900);
   Serial.print("Voltage: ");
   Serial.println(voltage);
   delay(200);
   return voltage;
}

bool buttonRead() {
   Serial.println(digitalRead(BUTTON_PIN));
   if (digitalRead(BUTTON_PIN) == LOW) {
      return true;
   } else
      return false;
}

void setup() {
   // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(LED_PIN, OUTPUT);
   pinMode(BUTTON_PIN, INPUT_PULLUP);
#ifdef ROLE
   pinMode(ROLE_PIN, OUTPUT);
   digitalWrite(ROLE_PIN, HIGH);
#endif
   digitalWrite(LED_PIN, LOW);
   load.init();
   lcd1.lcd_init();
   delay(1000);
   lcd1.lcd_display_clear_all();
   lcd1.lcd_display_string("LUC:", 1, 1);
   lcd1.lcd_display_string("DIEN AP:", 1, 2);
   lcd1.lcd_display_string("V", 15, 2);
   lcd1.lcd_display_string("N", 15, 1);
}

void loop() {
   //*Chuyen don vi mV thanh V
   float voltage = getVoltage() / 1000.0;
   voltage = voltage * MAX_VOLTAGE / 3.9;
   // lcd1.lcd_display_number(voltage, 10, 2);
   int loadcellReturn = static_cast<int>(load.getWeight());
   float weight = loadcellReturn / 1.0;
   lcd1.lcd_display_number(weight, voltage, 10, 1, 10, 2);
   Serial.print("Force: ");
   Serial.println(weight);
   if (isOpen) {
      if (millis() - currentTime < TIMEOUT) {
         digitalWrite(LED_PIN, HIGH);
      } else {
         digitalWrite(LED_PIN, LOW);
         isOpen = false;
      }
   } else {
      digitalWrite(LED_PIN, LOW);
      currentTime = millis();
   }
   if (buttonRead()) {
      isOpen = true;
   }
#ifdef ROLE
   if ((voltage >= 12.2) && (voltage <= 16.2)) {
      digitalWrite(LED_PIN, HIGH);
   }
   if (digitalRead(LED_PIN) == HIGH)
      digitalWrite(ROLE_PIN, LOW);
   else
      digitalWrite(ROLE_PIN, HIGH);
#endif
}

// put function definitions here:
