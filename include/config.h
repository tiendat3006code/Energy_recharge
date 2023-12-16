#ifndef CONFIG_H
#define CONFIG_H

// #define ROLE

// LCD 16x2
#define LCD_ADDRESS  0x27
#define SDA          A4
#define SCL          A5

// CHAN INPUT CUA HX711
#define DT_PIN       4
#define SCK_PIN      5

// LED
#define LED_PIN      11

// ROLE
#define ROLE_PIN     10

// FORCE THREESHOLD
#define THREESHOLD   5.0

// RESISTOR
#define RESISTOR_PIN A0

// BUTTON
#define BUTTON_PIN   9

// TIMEOUT
#define TIMEOUT      2000

#endif  // CONFIG_H