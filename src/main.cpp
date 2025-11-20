#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include "Display/display.h"

TFT_eSPI tft = TFT_eSPI();
int headingSize = 3;
int regularSize = 2;
// put function declarations here:

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  initializeDisplay();
}

void loop()
{
  // put your main code here, to run repeatedly:
}

// put function definitions here:
