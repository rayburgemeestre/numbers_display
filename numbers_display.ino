#include <Wire.h>

#ifdef ARDUINO_AND_NOT_ESPDUINO
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>

// OLED display TWI address
#define OLED_ADDR   0x3C

Adafruit_SSD1306 display(-1);

#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

void setup() {
  // initialize and clear display
  display.begin(SSD1306_SWITCHCAPVCC, OLED_ADDR);
  display.clearDisplay();
  display.display();
}
#else

#include <Wire.h>  // Only needed for Arduino 1.6.5 and earlier
#include "SSD1306.h" // alias for `#include "SSD1306Wire.h"`
// Initialize the OLED display using Wire library
//SSD1306  display(0x3c, D3, D5);
//SSD1306  display(0x3c, D4, D6);
int ms = 0;


const int num_screens = 6;

int hour = 17;
int minute = 42;
int second = 20;
int H_digit_1 = 1;
int H_digit_2 = 1;
int M_digit_1 = 1;
int M_digit_2 = 1;
int S_digit_1 = 1;
int S_digit_2 = 1;

unsigned char one [] = {255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 212, 15, 43, 21, 38, 26, 38, 26, 38, 26, 38, 26, 38, 26, 38, 26, 38, 12, 5, 9, 22, 9, 7, 6, 11, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 9, 55, 9, 55, 9, 55, 9, 55, 9, 40, 39, 25, 39, 25, 39, 25, 39, 25, 39, 25, 39, 25, 39, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 219};

unsigned char two [] = {255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 82, 17, 43, 24, 37, 29, 32, 34, 28, 37, 27, 38, 26, 39, 25, 40, 24, 14, 12, 15, 23, 11, 17, 14, 22, 9, 21, 12, 9, 9, 4, 7, 24, 12, 8, 9, 4, 5, 27, 11, 8, 9, 4, 3, 30, 11, 7, 9, 4, 2, 31, 11, 7, 9, 38, 10, 7, 9, 38, 10, 7, 9, 38, 10, 7, 9, 38, 10, 7, 9, 38, 10, 7, 9, 38, 10, 7, 9, 38, 10, 7, 9, 38, 10, 54, 10, 54, 10, 53, 11, 53, 11, 52, 11, 53, 11, 52, 12, 51, 12, 52, 12, 51, 12, 51, 12, 51, 13, 50, 13, 50, 13, 51, 12, 51, 13, 50, 13, 50, 13, 50, 13, 50, 13, 50, 13, 50, 13, 50, 13, 50, 13, 50, 13, 23, 9, 18, 13, 24, 9, 17, 13, 25, 9, 16, 13, 26, 9, 15, 13, 27, 9, 14, 13, 28, 9, 13, 13, 29, 9, 12, 13, 30, 9, 11, 13, 31, 9, 10, 13, 32, 9, 9, 13, 33, 9, 8, 13, 34, 9, 7, 13, 50, 14, 49, 14, 50, 13, 50, 13, 51, 45, 19, 45, 19, 45, 19, 45, 19, 45, 19, 45, 19, 45, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 218};

unsigned char three [] = {255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 80, 20, 40, 27, 33, 33, 31, 35, 29, 36, 28, 37, 27, 38, 26, 39, 25, 10, 15, 15, 24, 6, 21, 14, 23, 3, 26, 12, 8, 9, 36, 11, 8, 9, 37, 11, 7, 9, 37, 11, 7, 9, 38, 10, 7, 9, 38, 10, 7, 9, 38, 10, 7, 9, 38, 10, 7, 9, 38, 10, 7, 9, 38, 10, 7, 9, 38, 10, 7, 9, 38, 10, 7, 9, 38, 10, 53, 11, 53, 10, 53, 11, 52, 11, 51, 13, 49, 14, 43, 20, 36, 27, 37, 25, 39, 23, 41, 23, 41, 25, 39, 27, 37, 28, 44, 21, 50, 15, 52, 13, 52, 13, 53, 11, 54, 11, 53, 11, 54, 11, 53, 11, 54, 10, 54, 10, 5, 9, 40, 10, 5, 9, 40, 10, 5, 9, 40, 10, 5, 9, 40, 10, 5, 9, 40, 10, 5, 9, 40, 10, 5, 9, 40, 10, 5, 9, 40, 10, 5, 9, 39, 11, 5, 9, 39, 11, 5, 9, 38, 11, 6, 9, 37, 12, 19, 2, 30, 12, 20, 4, 27, 13, 20, 7, 22, 14, 21, 10, 16, 17, 21, 42, 22, 41, 23, 40, 24, 38, 26, 37, 27, 35, 32, 29, 40, 21, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 170};

unsigned char four [] = {255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 224, 13, 50, 14, 50, 14, 49, 15, 48, 16, 48, 16, 47, 17, 46, 18, 46, 18, 12, 9, 24, 19, 12, 9, 23, 10, 1, 9, 12, 9, 23, 10, 1, 9, 12, 9, 22, 10, 2, 9, 12, 9, 21, 10, 3, 9, 12, 9, 21, 10, 3, 9, 12, 9, 20, 10, 4, 9, 12, 9, 19, 10, 5, 9, 12, 9, 19, 10, 5, 9, 12, 9, 18, 10, 6, 9, 12, 9, 17, 10, 7, 9, 12, 9, 16, 11, 7, 9, 37, 10, 8, 9, 36, 10, 9, 9, 35, 11, 9, 9, 35, 10, 10, 9, 34, 10, 11, 9, 33, 11, 11, 9, 33, 10, 12, 9, 32, 10, 13, 9, 31, 11, 13, 9, 31, 10, 14, 9, 30, 10, 15, 9, 29, 11, 15, 9, 29, 10, 16, 9, 28, 10, 17, 9, 27, 11, 17, 9, 27, 10, 18, 9, 26, 10, 19, 9, 25, 11, 19, 9, 25, 10, 20, 9, 24, 10, 21, 9, 24, 10, 21, 9, 24, 9, 22, 9, 24, 9, 22, 9, 24, 8, 23, 9, 24, 48, 4, 9, 3, 48, 4, 9, 3, 48, 4, 9, 3, 48, 4, 9, 3, 48, 4, 9, 3, 48, 4, 9, 3, 48, 4, 9, 34, 9, 12, 9, 34, 9, 12, 9, 34, 9, 12, 9, 34, 9, 12, 9, 34, 9, 12, 9, 34, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 55, 9, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 224};

unsigned char five [] = {255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 201, 37, 27, 37, 27, 37, 27, 37, 27, 37, 27, 37, 27, 37, 27, 9, 55, 9, 39, 9, 7, 9, 39, 9, 7, 9, 39, 9, 7, 9, 39, 9, 7, 9, 39, 9, 7, 9, 39, 9, 7, 9, 39, 9, 7, 9, 39, 9, 7, 9, 39, 9, 7, 9, 39, 9, 7, 9, 39, 9, 7, 9, 39, 9, 7, 9, 55, 9, 55, 9, 55, 9, 1, 16, 38, 29, 35, 31, 33, 33, 31, 34, 30, 35, 29, 36, 28, 37, 27, 7, 15, 16, 26, 3, 21, 15, 51, 13, 52, 13, 52, 12, 53, 12, 53, 11, 54, 10, 54, 11, 53, 11, 54, 10, 54, 10, 54, 10, 54, 10, 54, 10, 6, 9, 39, 10, 6, 9, 39, 10, 6, 9, 39, 10, 6, 9, 39, 10, 6, 9, 39, 10, 6, 9, 39, 10, 6, 9, 38, 11, 6, 9, 38, 11, 6, 9, 38, 11, 6, 9, 37, 11, 7, 9, 36, 12, 7, 9, 35, 12, 21, 2, 28, 13, 21, 4, 25, 13, 22, 7, 20, 15, 22, 10, 15, 16, 23, 40, 24, 39, 25, 38, 26, 37, 27, 35, 29, 34, 33, 28, 41, 20, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 171};

unsigned char six [] = {255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 90, 16, 45, 22, 39, 28, 35, 29, 33, 31, 32, 32, 31, 33, 30, 34, 29, 14, 13, 8, 28, 13, 17, 6, 27, 12, 21, 4, 9, 9, 9, 11, 24, 2, 9, 9, 8, 11, 36, 9, 8, 10, 37, 9, 7, 10, 38, 9, 6, 11, 38, 9, 6, 10, 39, 9, 6, 10, 39, 9, 5, 10, 40, 9, 5, 10, 40, 9, 5, 10, 40, 9, 4, 10, 41, 9, 4, 10, 54, 10, 54, 9, 8, 15, 31, 10, 6, 20, 28, 10, 4, 24, 26, 10, 2, 27, 25, 10, 1, 30, 23, 42, 22, 43, 21, 44, 20, 20, 10, 14, 20, 18, 14, 13, 19, 17, 16, 13, 18, 16, 18, 12, 18, 15, 20, 11, 18, 14, 22, 11, 17, 14, 22, 11, 17, 13, 24, 10, 17, 13, 24, 11, 16, 12, 26, 10, 16, 12, 26, 10, 16, 12, 26, 10, 16, 12, 26, 10, 16, 12, 26, 10, 16, 12, 26, 10, 16, 12, 26, 10, 4, 9, 3, 12, 26, 10, 4, 9, 4, 11, 26, 10, 4, 9, 4, 11, 26, 10, 4, 9, 4, 11, 26, 10, 4, 9, 4, 11, 26, 10, 4, 9, 5, 10, 26, 10, 4, 9, 5, 10, 26, 10, 4, 9, 5, 11, 24, 11, 4, 9, 6, 10, 24, 10, 5, 9, 6, 11, 22, 11, 5, 9, 6, 11, 22, 11, 5, 9, 7, 11, 20, 11, 22, 12, 18, 12, 23, 12, 16, 12, 24, 13, 14, 13, 25, 14, 10, 14, 27, 36, 29, 34, 31, 32, 33, 30, 35, 28, 38, 24, 42, 20, 46, 16, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 167};

unsigned char seven [] = {255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 198, 45, 19, 45, 19, 45, 19, 45, 19, 45, 19, 45, 19, 45, 52, 11, 52, 12, 7, 9, 36, 11, 8, 9, 36, 11, 8, 9, 35, 12, 8, 9, 35, 11, 9, 9, 35, 11, 9, 9, 34, 12, 9, 9, 34, 11, 10, 9, 33, 12, 10, 9, 33, 11, 11, 9, 33, 11, 11, 9, 32, 12, 11, 9, 32, 11, 53, 11, 52, 11, 53, 11, 52, 12, 52, 11, 53, 11, 52, 12, 52, 11, 52, 12, 52, 11, 53, 11, 52, 12, 52, 11, 53, 11, 52, 11, 53, 11, 52, 12, 52, 11, 53, 11, 52, 11, 53, 11, 52, 12, 52, 11, 53, 11, 52, 12, 21, 9, 22, 11, 22, 9, 22, 11, 22, 9, 21, 11, 23, 9, 21, 11, 23, 9, 20, 12, 23, 9, 20, 11, 24, 9, 20, 11, 24, 9, 19, 11, 25, 9, 19, 11, 25, 9, 19, 11, 25, 9, 18, 11, 26, 9, 18, 11, 52, 12, 52, 11, 53, 11, 52, 11, 53, 11, 52, 12, 52, 11, 53, 11, 52, 11, 53, 11, 53, 11, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 242};

unsigned char eight [] = {255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 84, 18, 43, 24, 38, 28, 35, 30, 32, 34, 29, 36, 27, 38, 26, 38, 25, 14, 12, 14, 23, 13, 16, 13, 22, 12, 18, 12, 7, 9, 6, 11, 20, 11, 7, 9, 5, 11, 22, 11, 6, 9, 5, 11, 22, 11, 6, 9, 5, 10, 24, 10, 6, 9, 5, 10, 24, 10, 6, 9, 5, 10, 24, 10, 6, 9, 5, 10, 24, 10, 6, 9, 5, 10, 24, 10, 6, 9, 5, 10, 24, 10, 6, 9, 5, 10, 24, 10, 6, 9, 5, 10, 24, 10, 6, 9, 5, 10, 24, 10, 20, 10, 24, 10, 20, 11, 22, 11, 21, 10, 22, 10, 22, 11, 20, 11, 23, 11, 18, 11, 25, 11, 16, 11, 26, 13, 12, 13, 27, 36, 29, 34, 32, 30, 36, 26, 39, 24, 37, 30, 32, 34, 29, 36, 27, 38, 25, 14, 12, 14, 23, 13, 16, 13, 21, 12, 20, 12, 20, 11, 22, 11, 19, 11, 24, 11, 18, 10, 26, 10, 17, 11, 26, 11, 16, 10, 28, 10, 16, 10, 28, 10, 4, 9, 3, 10, 28, 10, 4, 9, 3, 10, 28, 10, 4, 9, 3, 10, 28, 10, 4, 9, 3, 10, 28, 10, 4, 9, 3, 10, 28, 10, 4, 9, 3, 10, 28, 10, 4, 9, 3, 10, 28, 10, 4, 9, 3, 10, 28, 10, 4, 9, 3, 10, 28, 10, 4, 9, 3, 11, 26, 11, 4, 9, 3, 11, 26, 11, 4, 9, 4, 11, 24, 11, 18, 12, 22, 12, 18, 13, 20, 13, 19, 14, 16, 14, 21, 15, 12, 15, 22, 42, 23, 40, 25, 38, 27, 36, 30, 32, 33, 30, 36, 26, 42, 18, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 167};

unsigned char nine [] = {255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 84, 16, 46, 20, 42, 24, 38, 28, 35, 30, 33, 32, 31, 34, 29, 36, 27, 14, 10, 14, 25, 13, 14, 13, 24, 12, 16, 12, 9, 9, 5, 12, 18, 12, 8, 9, 5, 11, 20, 11, 8, 9, 4, 11, 22, 11, 7, 9, 4, 11, 22, 11, 7, 9, 4, 10, 24, 10, 7, 9, 3, 11, 24, 11, 6, 9, 3, 10, 26, 10, 6, 9, 3, 10, 26, 10, 6, 9, 3, 10, 26, 11, 5, 9, 3, 10, 26, 11, 5, 9, 3, 10, 26, 11, 5, 9, 3, 10, 26, 11, 17, 10, 26, 12, 16, 10, 26, 12, 16, 10, 26, 12, 16, 10, 26, 12, 16, 10, 26, 12, 16, 10, 26, 12, 16, 10, 26, 12, 16, 10, 26, 12, 16, 11, 24, 13, 16, 11, 24, 13, 17, 11, 22, 14, 17, 11, 22, 14, 17, 12, 20, 15, 18, 12, 18, 16, 18, 13, 16, 17, 19, 13, 14, 18, 20, 14, 10, 20, 20, 44, 21, 43, 22, 42, 23, 30, 1, 10, 25, 27, 2, 10, 26, 24, 4, 10, 28, 20, 6, 10, 31, 15, 7, 10, 5, 9, 40, 10, 5, 9, 40, 10, 5, 9, 40, 10, 5, 9, 39, 10, 6, 9, 39, 10, 6, 9, 39, 10, 6, 9, 38, 10, 7, 9, 38, 10, 7, 9, 37, 10, 8, 9, 36, 11, 8, 9, 36, 10, 9, 9, 35, 11, 25, 2, 25, 11, 26, 4, 21, 12, 27, 6, 18, 13, 27, 9, 12, 15, 28, 35, 29, 34, 30, 33, 31, 32, 32, 30, 34, 28, 39, 23, 44, 17, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 173};

unsigned char zero [] = {255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 86, 14, 47, 20, 42, 24, 39, 26, 36, 30, 33, 32, 31, 34, 30, 34, 29, 13, 10, 13, 27, 13, 12, 13, 26, 11, 16, 11, 9, 9, 7, 11, 18, 11, 8, 9, 7, 11, 18, 11, 8, 9, 6, 11, 20, 11, 7, 9, 6, 10, 22, 10, 7, 9, 5, 11, 22, 11, 6, 9, 5, 10, 24, 10, 6, 9, 5, 10, 24, 10, 6, 9, 4, 11, 24, 10, 6, 9, 4, 10, 26, 10, 5, 9, 4, 10, 26, 10, 5, 9, 4, 10, 26, 10, 5, 9, 4, 10, 26, 10, 17, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 16, 10, 28, 10, 4, 9, 3, 10, 28, 10, 4, 9, 4, 10, 26, 10, 5, 9, 4, 10, 26, 10, 5, 9, 4, 10, 26, 10, 5, 9, 4, 10, 26, 10, 5, 9, 4, 11, 24, 10, 6, 9, 5, 10, 24, 10, 6, 9, 5, 10, 24, 10, 6, 9, 5, 11, 22, 11, 6, 9, 6, 10, 22, 10, 7, 9, 6, 11, 20, 11, 7, 9, 7, 11, 18, 11, 24, 11, 18, 11, 25, 11, 16, 11, 26, 13, 12, 13, 27, 13, 10, 13, 29, 34, 30, 34, 31, 32, 33, 30, 36, 26, 39, 24, 42, 20, 47, 14, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 255, 0, 169};

unsigned char *characters [] = {
  //one, one, one, one, one, one, one, one, one, one
  zero, one, two, three, four, five, six, seven, eight, nine
};


bool colons = false;

// time stuff
#include <ESP8266WiFi.h>
const char* ssid = "NETGEAR805GX";//"Pfff alweer vertraging";
const char* password = "slowbolt948";


#include <time.h>                       // time() ctime()
#include <sys/time.h>                   // struct timeval
#include <coredecls.h>                  // settimeofday_cb()
#define TZ              0       // (utc+) TZ in hours
#define DST_MN          60      // use 60mn for summer time in some countries
#define TZ_MN           ((TZ)*60)
#define TZ_SEC          ((TZ)*3600)
#define DST_SEC         ((DST_MN)*60)
timeval cbtime;      // time set in callback
bool cbtime_set = false;
void time_is_set (void)
{
  gettimeofday(&cbtime, NULL);
  cbtime_set = true;
}
timeval tv;
timespec tp;
time_t now;
uint32_t now_ms, now_us;



extern "C" int clock_gettime(clockid_t unused, struct timespec *tp);

void printTm (const char* what, const tm* tm) {
  Serial.print(what);
  Serial.print(tm->tm_hour);
  Serial.print(tm->tm_min);
  Serial.print(tm->tm_sec);\
}

//D1
//int LED_SCK[] = { D0 , D3 , D5 , D7 , D11 , D14 };
//int LED_SDA[] = { D1 , D4 , D6 , D8 , D12 , D15 };
// D1 mini (Lite)
//int LED_SCK[] = { D8 , D6 , D0 , D4 , D2 , RX };
//int LED_SDA[] = { D7 , D5 , A0 , D3 , D1 , TX };


int LED_SCK[] = { D7 , D7,  D7,  D7,  D7,  D7 };
int LED_SDA[] = { D1 , D2 , D3 , D4 , D5 , D6 };

void update_time()
{
    gettimeofday(&tv, nullptr);
    clock_gettime(0, &tp);
    now = time(nullptr);

    //printTm("localtime", localtime(&now));
    //printTm("gmtime   ", gmtime(&now));

    struct tm *tmp = localtime(&now);

    if (tmp->tm_hour != hour || tmp->tm_min != minute) {
       hour = tmp->tm_hour;
       minute = tmp->tm_min;
       second = tmp->tm_sec;
    }
}

int lcd_initialized = -1;
SSD1306 *display = NULL;

void setup() {
   lcd_initialized = 10;
   display = NULL;

  // D1
/*  
    //GPIO 1 (TX) swap the pin to a GPIO.
    //GPIO 3 (RX) swap the pin to a GPIO.
    pinMode(D0, FUNCTION_3);
    pinMode(D1, FUNCTION_3);
    // Swap some more pins
    pinMode(D14, FUNCTION_3);
    pinMode(D15, FUNCTION_3);
    pinMode(D11, FUNCTION_3);
    pinMode(D12, FUNCTION_3);
  */
   // D1 mini (Lite), use all the pins!
   for (int i=0; i<num_screens; i++) {
    pinMode(LED_SCK[i], FUNCTION_3);
    pinMode(LED_SDA[i], FUNCTION_3);
   }

    for (int i=0; i<num_screens; i++) {
        clear(i);
    }
    for (int i=0; i<num_screens; i++) {
        //animate_fill(i, true);
    }
    //delay(1000);

    int duration = 10;
    for (int i=0; i<num_screens; i++) {
        do_it(i, characters[1], characters[1], duration);
    }

    Serial.begin(115200);
    Serial.setDebugOutput(true);

    WiFi.mode(WIFI_STA);
    WiFi.begin(ssid, password);
    while (WiFi.status() != WL_CONNECTED) {
        delay(1000);
    }

   lcd_initialized = 10;
   lcd_initialized = 10;

    settimeofday_cb(time_is_set);
    configTime(TZ_SEC, DST_SEC, "pool.ntp.org", "time.nist.gov");
    
    // some issue with the client version I am using, see
    // https://github.com/stelgenhof/NTPClient/issues/5
    while (time(nullptr) < 30000) {
        Serial.println(time(nullptr));
        delay(1000);
    }

    update_time();

    Serial.println(hour);
    Serial.println(minute);
    Serial.println(second);

    ms = millis();
    Serial.print("WTF:"); Serial.println(lcd_initialized);
}
#endif

double radius = 0.0;
void show_display(SSD1306 &display, unsigned char *character, int shift) {
    bool pixel = false;
    int i=0;
    int num = character[i];

    if (shift == -1){
        for (int x=0; x<127; x++) {
            for (int y=0; y<64; y++) {

                bool value = pixel && (colons || y < 64-16) && (y % shift == 0 && x % shift == 0) && (/*scanline*/y%2 == 0);
                
                if (num_screens == 4) {
                    // extra effect for seconds
                    float fill_pixels = float(second) * 2.1166666666666667;
                    if (y >= 64 - 16 + 6 /*&& y <= 64 - 6*/ && x > (127 - fill_pixels)) {
                        if (value) {
                            value = !value;
                        } else {
                            value = (/*scanline*/y%2 == 0);
                        }
                    }
                }

                display.setColor(value ? WHITE : BLACK);
                display.setPixel(127 - x, y);

                num--;
                while (num == 0) {
                    i++;
                    pixel = !pixel;
                    num = character[i];
                }
            }
        }
        display.display();
        return;
    }

    for (int x=0; x<127; x++) {
        for (int y=0; y<64; y++) {

#ifdef ARDUINO_AND_NOT_ESPDUINO
            display.drawPixel(
                    x,
                    63 - y,
                    pixel && (colons || y < 64-16) && (y % shift == 0 && x % shift == 0) && (/*scanline*/y%shift == 0) ? WHITE : BLACK
                    );
#else
            display.setColor(pixel && (colons || y < 64-16) && (y % shift == 0 && x % shift == 0) && (/*scanline*/y%2 == 0)? WHITE : BLACK);
            display.setPixel(127 - x, y);

            // display2.setColor(pixel && (colons || y < 64-16) && (y % shift == 0 && x % shift == 0) ? WHITE : BLACK);
            // display2.setPixel(127 - x, y);
#endif


            num--;
            while (num == 0) {
                i++;
                pixel = !pixel;
                num = character[i];
            }
        }
    }
    display.display();
    //display2.display();
}

void fade_in(SSD1306 &display, unsigned char *character, int duration) {
    if (duration == 0) {
        show_display(display, character, -1);
        return;
    }
    for (int shift=duration; shift>=1; shift--)
        show_display(display, character, shift);
}

void fade_out(SSD1306 &display, unsigned char *character, int duration) {
    for (int shift=1; shift<=duration; shift++)
        show_display(display, character, shift);
}


void animate_fill(int lcd_index, bool flag) {
    SSD1306  display(0x3c, LED_SDA[lcd_index], LED_SCK[lcd_index]); // we cannot have more than two(!) in total on our stack.
                                                                        // or a linker error will occur..
    display.init();
    display.setContrast(255);
    display.clear();
    if (flag) {
        for (int shift=88; shift>20; shift--) {
            for (int x=0; x<127; x++) {
                for (int y = 0; y < 64; y++) {
                    display.setColor((y % shift == 0 && x % shift == 0) ? WHITE : BLACK);
                    display.setPixel(127 - x, y);
                }
            }
            display.display();
        }
    } else {
        display.display();
    }
    display.end();
}
void clear(int lcd_index) {
    animate_fill(lcd_index, false);
}

void do_it(int lcd_index, unsigned char *character, unsigned char *prev, int duration) {
    if (lcd_initialized != lcd_index) {
        if (lcd_initialized != 10) {
            display->end();
            delete(display);
        }
        lcd_initialized = lcd_index;
        display = new SSD1306(0x3c, LED_SDA[lcd_index], LED_SCK[lcd_index]);
        display->init();
    }
    if (duration != 0) {
      fade_out(*display, prev, duration);
    }
    fade_in(*display, character, duration);
}

//unsigned char *previous_character = characters[0];
//unsigned char *previous_character_minute = characters[0];

bool first = true;

void loop() {
   /*Serial.print("WTFLOOP:"); Serial.println(lcd_initialized);

    Serial.print(hour);
    Serial.print(":");
    Serial.print(minute);
    Serial.print(":");
    Serial.println(second);
    */
  
    int now = millis();

    /*
    Serial.print(now);
    Serial.print(" - ");
    Serial.print(ms);
    Serial.println("");
     */

    int duration = num_screens == 6 ? 10 : 20;
    int digits_changed = 0;
   // unsigned char *character = characters[second];

    if (now - ms> 1000) {
        ms += 1000;
        second++;
        if (second == 60) {
            second = 0;
            minute++;
            if (minute == 60) {
                minute = 0;
                hour++;
                if (hour == 24) {
                    hour = 0;
                }
            }
        }

        int s1 = second / 10.0;
        int s2 = second - s1 * 10;
        if (num_screens == 6) {
            // seconds
            if (s2 != S_digit_2){
                digits_changed++;
            }
            if (s1 != S_digit_1) {
                digits_changed++;
            }
        }

        // minutes
        int m1 = minute / 10.0;
        int m2 = minute - m1 * 10;
        if (m2 != M_digit_2){
            digits_changed++;
        }
        if (m1 != M_digit_1) {
            digits_changed++;
        }

        // hours
        int h1 = hour / 10.0;
        int h2 = hour - h1 * 10;
        if (h2 != H_digit_2){
            digits_changed++;
        }
        if (h1 != H_digit_1) {
            digits_changed++;
        }

        if (first) digits_changed = 6;

        duration -= digits_changed; // otherwise the total animation will take too long
        // do the changes
        if (num_screens == 6) {
            if (s2 != S_digit_2 || first){
                //d11
                do_it(5, characters[s2], characters[S_digit_2], duration);
            }
            if (s1 != S_digit_1 || first) {
                //d14
                do_it(4, characters[s1], characters[S_digit_1], duration);
            }
        }
        if (m2 != M_digit_2 || first){
            // d7
            colons = num_screens == 6;
            do_it(3, characters[m2], characters[M_digit_2], duration);
            colons = false;
        }
        if (m1 != M_digit_1 || first) {
            //d1
            do_it(2, characters[m1], characters[M_digit_1], duration);
        }
        if (h2 != H_digit_2 || first){
            //d3
            colons = true;
            do_it(1, characters[h2], characters[H_digit_2], duration);
            colons = false;
        }
        if (h1 != H_digit_1 || first) {
            //d4
            do_it(0, characters[h1], characters[H_digit_1], duration);
        }

        S_digit_1 = s1;
        S_digit_2 = s2;
        M_digit_1 = m1;
        M_digit_2 = m2;
        H_digit_1 = h1;
        H_digit_2 = h2;

        first = false;
    } else {
        if (num_screens == 4) {
            do_it(3, characters[M_digit_2], characters[M_digit_2], 0);
            delay(1000);
        }
    }

    //do_it(D0, D1, character, previous_character, duration);
    //do_it(D0, D1, character, previous_character, duration);

    /*
       do_it(D14, D15, character, previous_character, duration);
       do_it(D7, D8, character, previous_character, duration);
       do_it(D3, D5, character, previous_character, duration);
       do_it(D12, D11, character, previous_character, duration);
       do_it(D4, D6, character, previous_character, duration);
     */
}
