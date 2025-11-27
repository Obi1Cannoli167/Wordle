#ifndef TERMINALINTERFACE_H
#define TERMINALINTERFACE_H
#include <Arduino.h>
#include "Core/options.h"
void terminalInterfaceInit();
void makeFrame();
void instructResize();
void wordleTitle();
void mainMenu();
void selectionHandler(options option);

#endif // TERMINALINTERFACE_H