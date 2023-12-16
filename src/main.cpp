#include <Arduino.h>
#include "../include/lcd.h"
#include "../include/loadcell.h"

lcd lcd1;
loadcell load;
unsigned long currentTime = 0;
bool isOpen = false;

// put function declarations here:
int myFunction(int, int);
//*Lay gia tri voltage dau vao Arduino don vi mV
int getVoltage() {
   int resistorResult = analogRead(RESISTOR_PIN);
   //  Serial.print("Resistor value: ");
   //  Serial.println(resistorResult);
   int voltage = map(resistorResult, 0, 1023, 0, 5000);
   //  Serial.print("Voltage: ");
   //  Serial.println(voltage);
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
   pinMode(ROLE_PIN, OUTPUT);
   digitalWrite(ROLE_PIN, HIGH);
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
   lcd1.lcd_display_number(voltage, 10, 2);
   float weight = load.getWeight() / 1.0;
   lcd1.lcd_display_number(weight, 10, 1);
   Serial.print("Force: ");
   Serial.println(weight);
   if (isOpen) {
      if (millis() - currentTime < TIMEOUT) {
#ifdef ROLE
         digitalWrite(ROLE_PIN, LOW);
#endif
         digitalWrite(LED_PIN, HIGH);
      } else {
#ifdef ROLE
         digitalWrite(ROLE_PIN, HIGH);
#endif
         digitalWrite(LED_PIN, LOW);
         isOpen = false;
      }
   } else {
#ifdef ROLE
      digitalWrite(ROLE_PIN, HIGH);
#endif
      digitalWrite(LED_PIN, LOW);
      currentTime = millis();
   }
   if (buttonRead()) {
      isOpen = true;
   }
}

// put function definitions here:
int myFunction(int x, int y) {
   return x + y;
}