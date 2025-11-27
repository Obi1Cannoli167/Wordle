#ifndef TERMINALCOMMANDS_H
#define TERMINALCOMMANDS_H

void setCursor(int x, int y);
void eraseCh(int x, int y);
void saveCursor();
void restoreCursor();
void cursorOff();
void cursorOn();
void clrScreen();
void screenWonB();
void eraseToEOL();
void eraseLine();
void doGameEngine();
void handleUser();


#endif // TERMINALCOMMANDS_H