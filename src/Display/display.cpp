#include <SPI.h>
#include <TFT_eSPI.h>
#include <Arduino.h>
#include "Core/accessibility.h"
extern TFT_eSPI tft;
extern int headingSize;
extern int regularSize;

void initializeDisplay()
{
    Serial.begin(115200);
    tft.init();
    // Write text
    tft.fillScreen(TFT_WHITE);
    tft.setTextSize(headingSize); // Text size in pixels: 3x the original size, which is 8x8 pixels
    tft.setTextColor(TFT_BLACK);  // Black text on no background
    // Center the text
    int16_t x = (tft.width() - (6 * headingSize * 6)) / 2; // 6 pixels per character, size is multiplicative, "Wordle" has 6 characters
    int16_t y = 5;

    tft.setCursor(x, y);
    tft.print("Wordle");
}

// Compartmentalizing commonly used statements
void clearDisplay()
{
    tft.fillScreen(TFT_WHITE);
}