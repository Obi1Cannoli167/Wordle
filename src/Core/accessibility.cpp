#include <SPI.h>
#include <TFT_eSPI.h>
#include <Arduino.h>
#include "Core/accessibility.h"
#include "Display/terminalCommands.h"

#define sp(x) Serial.print(x)
#define spln(x) Serial.println(x)

extern const int maxNameLength; // Maximum length for player name input
extern char playerNameBuffer[]; // Buffer to hold player name input
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

void fetchVariables()
{
    setCursor(32, 42);
    sp(playerNameBuffer);
}

// The purpose is to make the application more convenient
