#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "Display/display.h"
#include "Core/accessibility.h"
#include "Core/codeParsedWordLibrary.h"

TFT_eSPI tft = TFT_eSPI();
int headingSize = 3;
int regularSize = 2;
// put function declarations here:

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  initializeDisplay();
  // use GPIO35 to flip the screen orientation
  pinMode(35, INPUT_PULLUP);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (digitalRead(35) == LOW) {
    // Through adding more object instances will take up more flash storage
    getFlashStorageInfo();
    delay(500); // Debounce delay
  }
}

// put function definitions here:
