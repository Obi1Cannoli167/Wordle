#include <SPI.h>
#include <TFT_eSPI.h>
#include <Arduino.h>
#include "Core/accessibility.h"
extern TFT_eSPI tft;

void getFlashStorageInfo()
{
    // Retrieve and print flash storage information
    uint32_t flashSize = ESP.getFlashChipSize();
    // Check remaining storage space
    uint32_t freeSketchSpace = ESP.getFreeSketchSpace();
    Serial.print("Flash Chip Size: ");
    Serial.print(flashSize);
    Serial.println(" bytes");
    Serial.print("Free Sketch Space: ");
    Serial.print(freeSketchSpace);
    Serial.println(" bytes");
}

// The purpose is to make the application more convenient
