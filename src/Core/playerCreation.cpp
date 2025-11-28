#include "Core/playerCreation.h"
#include "Core/terminalInterface.h"
#include "Display/terminalCommands.h"
#include "Core/structs.h"
#include "Core/options.h"
#include <Arduino.h>

#define sp(x) Serial.print(x)
#define spln(x) Serial.println(x)
#define sw(x) Serial.write(x)
#define esc() sw(0x1b)
#define spEsc(x) esc(), sp(x)
#define width 40
#define height 30

extern int letterPosition;
extern const int maxNameLength;
extern char playerNameBuffer[];

// API to handle new player creation by reading from the input buffer
void createNewPlayer()
{
    // Test implementation: Just display the name entered
    clrScreen();
    screenWonB();
    makeFrame();
    setCursor(5, textCenter(20));
    sp("New Player Created:");
    setCursor(7, textCenter(strlen(playerNameBuffer)));
    sp(playerNameBuffer);
    // Create player struct and store in flash (future implementation)
    Player newPlayer;
    strncpy(newPlayer.name, playerNameBuffer, sizeof(newPlayer.name));
    newPlayer.currentGame = '\0'; // No current game
    newPlayer.score = 0;
}