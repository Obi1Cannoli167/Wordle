#ifndef TERMINALINTERFACE_H
#define TERMINALINTERFACE_H
#include <Arduino.h>
#include "Core/options.h"
void terminalInterfaceInit();
void makeFrame();
void instructResize();
void wordleTitle();
void mainMenu();
void playerSetup();
void chooseExistingPlayer();
void WritePlayerNameChar(char c, int letterPos);
void deletePlayerNameChar(int letterPos);
void selectionHandler(options option);
int textCenter(int textLength);
int textCenterEnd(int textLength);

#endif // TERMINALINTERFACE_H