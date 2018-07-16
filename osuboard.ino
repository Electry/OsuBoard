#include <SK6812.h>
#include <Keyboard.h>

SK6812 LED(3);

RGBW rgbw_glow  = {  0,   0, 255,  50};
RGBW rgbw_left  = { 11,  50,   1,   0};
RGBW rgbw_right = {  1,   5,  50,   0};
RGBW rgbw_off   = {  0,   0,   0,   0};

int pin_1 = 7;
int pin_2 = 8;

void setup() {
  pinMode(pin_1, INPUT);
  pinMode(pin_2, INPUT);

  LED.set_output(4); // Digital Pin 4
  Keyboard.begin();
}

void loop() {
  // Underglow
  LED.set_rgbw(2, rgbw_glow);

  delay(1);
  int key_1 = digitalRead(pin_1);
  delay(1);
  int key_2 = digitalRead(pin_2);
  delay(1);

  if (key_1 == HIGH) {
    Keyboard.press('x');
    LED.set_rgbw(0, rgbw_left);
  } else {
    Keyboard.release('x');
    LED.set_rgbw(0, rgbw_off);
  }

  if (key_2 == HIGH) {
    Keyboard.press('y');
    LED.set_rgbw(1, rgbw_right);
  } else {
    Keyboard.release('y');
    LED.set_rgbw(1, rgbw_off);
  }

  LED.sync(); // Sends the value to the LED
}
