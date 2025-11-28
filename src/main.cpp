#include <Arduino.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <Preferences.h> // Storing struct instances in flash
#include "Display/display.h"
#include "Core/accessibility.h"
#include "Core/codeParsedWordLibrary.h"
#include "Core/terminalInterface.h"
#include "Core/options.h"
#include "Core/playerCreation.h"
#define sr Serial.read()

TFT_eSPI tft = TFT_eSPI();
int headingSize = 3;
int regularSize = 2;
const int maxNameLength = 10;
int letterPosition = 0;
char playerNameBuffer[maxNameLength + 1] = {0}; // Buffer to hold player name input

// Global interface state variable
// 0 - Resizing terminal
// 1 - Wordle title
// 2 - Main menu
// 3 - Player setup
// 4 - Player choice
// 5 - Game itself
int interfaceState = 0;
options option = NEW_PLAYER; // Default option
// put function definitions here:

void keyHandler(char key)
{
  switch (interfaceState)
  {
  case 0: // Resizing terminal
    if (key == 'x' || key == 'X')
    {
      wordleTitle();
      delay(2000);
      mainMenu();
    }
    break;
  case 2: // Main menu
    // W and S to navigate, Spacebar to select.
    // There are only two options, so direction will not matter.
    if (key == 'w' || key == 'W' || key == 's' || key == 'S')
    {
      // Move selection up
      if (option == NEW_PLAYER)
      {
        option = EXISTING_PLAYER;
      }
      else
      {
        option = NEW_PLAYER;
      }
      selectionHandler(option);
    }
    else if (key == ' ')
    {
      // Select current option
      if (option == NEW_PLAYER)
      {
        // New player selected
        playerSetup();
      }
      else if (option == EXISTING_PLAYER)
      {
        // Existing player selected
        chooseExistingPlayer();
        // Future implementation for existing player choice
      }
    }
    break;
  case 3:                       // Player setup
    if (key == 8 || key == 127) // Backspace key
    {
      deletePlayerNameChar(letterPosition);
    }
    if (key == 27) // ESC key
    {
      mainMenu();
      option = NEW_PLAYER;
      letterPosition = 0;
    }
    // Read into player name buffer
    if ((key >= 32 && key <= 122)) // Printable characters
    {
      if (letterPosition >= maxNameLength)
      {
        // Do nothing if max length reached
        break;
      }
      // Future implementation for adding character to player name
      WritePlayerNameChar(key, letterPosition);
    }
    if ((key == '\n' || key == '\r') && letterPosition > 0) // Enter key
    {
      createNewPlayer(); // Future implementation to pass actual name
    }
    break;
  case 4: // Player choice
    // Future implementation for handling player choice inputs
    if (key == 27) // ESC key
    {
      mainMenu();
      option = NEW_PLAYER;
    }
    break;
  case 5: // Game itself
    // Future implementation for handling game inputs
    break;
  default:
    break;
  }
}

void setup()
{
  // put your setup code here, to run once:
  Serial.begin(115200);
  initializeDisplay();
  terminalInterfaceInit();
  // use GPIO35 to flip the screen orientation
  pinMode(35, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
}

void loop()
{
  // put your main code here, to run repeatedly:
  if (digitalRead(35) == LOW)
  {
    // Through adding more object instances will take up more flash storage
    getFlashStorageInfo();
    delay(500); // Debounce delay
  }
  if (digitalRead(0) == LOW)
  {
    fetchVariables();
    delay(500); // Debounce delay
  }
  // When a key is pressed
  if (Serial.available())
  {
    char key = sr; // Read the key
    keyHandler(key);
  }
}
