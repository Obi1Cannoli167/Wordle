#include <Arduino.h>
#include "Core/terminalInterface.h"
#include "Display/terminalCommands.h"
#include "Core/options.h"
#define sp(x) Serial.print(x)
#define spln(x) Serial.println(x)
#define sw(x) Serial.write(x)
#define esc() sw(0x1b)
#define spEsc(x) esc(), sp(x)
#define width 40
#define height 30

// Interfasestate used here for the functions that change the value
extern int interfaceState;
// To be considered if needed:
// extern options option;

// Alias for workable int values
int workableWidth = width - 2;   // 2 for the sides
int workableHeight = height - 2; // 2 for the top and bottom

// About the interface states:
// 0 - Instructing user to resize terminal
// 1 - Displaying Wordle title
// 2 - Main menu - Set up a player or choose existing player
// 3 - Player setup - Input player name
// 4 - Game itself

// Initializing the terminal means setting up the interface. This is used as the initial state of our game
void terminalInterfaceInit()
{
    // In a PuTTY terminal, the x and y are inverted
    // This means the x is vertical and y is horizontal
    setCursor(1, 1);
    clrScreen();
    screenWonB();
    cursorOff();
    instructResize();
}

void makeFrame()
{
    // Bar at the top
    for (int i = 0; i < height; i++)
    {
        setCursor(1 + i, 1);
        sp("|");
    }
    // At this point, we are at y=2, so we can draw the sides
    for (int i = 2; i < width; i++)
    {
        setCursor(1, i);
        sp("=");
        setCursor(height, i);
        sp("=");
    }
    // Bar at the bottom
    for (int i = 0; i < height; i++)
    {
        setCursor(1 + i, width);
        sp("|");
    }
}

// To facilitate centering text in respect to text length
int textCenter(int length)
{
    // From MATLAB: width / 2 + (x-2) == 20
    // Subtract 2 due to even width of viewport.
    return (width / 2) - (length / 2) + 1;
}

// Get the right side of centered text. textCenter gets the left side.
int textCenterEnd(int length)
{
    return textCenter(length) + length;
}

// Optimal PuTTY size is 40x30, so we want to instruct the user to resize before proceeding
void instructResize()
{
    // Modify the original interfaceState to be 0
    interfaceState = 0;

    clrScreen();
    screenWonB();
    sp("Resize your terminal to ");
    sp(width);
    sp("x");
    sp(height);
    sp(".");
    setCursor(3, 1);
    sp("Terminal size can be seen on the ");
    setCursor(4, 1);
    sp("top-right corner of the PuTTY window.");
    setCursor(6, 1);
    sp("When resized, press 'x' to proceed...");
}

// Writing WORDLE in large letters and black on white background
void wordleTitle()
{
    interfaceState = 1;
    clrScreen();
    screenWonB();
    makeFrame();

    // Welcome to
    // Wordle

    setCursor(6, textCenter(10));
    sp("Welcome to");
    // Wordle logo length is 38
    setCursor(8, textCenter(38));
    sp("__    __    __              | ||");
    setCursor(9, textCenter(38));
    sp("\\ \\  /  \\  / /  __   __   __| ||   __");
    setCursor(10, textCenter(38));
    sp(" \\ \\/ /\\ \\/ /  /  \\ |  / /  | ||  /__>");
    setCursor(11, textCenter(38));
    sp("  \\__/  \\__/   \\__/ |_|  \\__| |_| \\__");
}

void mainMenu()
{
    clrScreen();
    screenWonB();
    interfaceState = 2;
    makeFrame();
    setCursor(5, textCenter(22));
    sp(" _   _                ");
    setCursor(6, textCenter(22));
    sp("| \\ / |  __   __      ");
    setCursor(7, textCenter(22));
    sp("|  V  | /__> |  \\ |  |");
    setCursor(8, textCenter(22));
    sp("|_\\_/_| \\__  |  | \\__/");
    setCursor(10, textCenter(22));
    sp("______________________");
    setCursor(13, textCenter(10));
    sp("New player");
    setCursor(15, textCenter(22));
    sp("Choose existing player");

    setCursor(height-2, 2);
    sp("Change options: W, S");
    setCursor(height-1, 2);
    sp("Select option: Spacebar");

    selectionHandler(NEW_PLAYER);
}

void playerSetup()
{
    clrScreen();
    screenWonB();
    interfaceState = 3;
    makeFrame();
    setCursor(5, textCenter(12));
    sp("Player Setup");
    setCursor(7, textCenter(30));
    sp("Enter your name (max 10 characters): ");
    setCursor(9, textCenter(10));
    sp("> ");
}

void selectionHandler(options option)
{
    // The functions below declare where we are under conditions
    switch (interfaceState)
    {
    case 2:
        if (option == NEW_PLAYER)
        {
            // Delete any other arrow
            setCursor(13, textCenterEnd(10) + 1);
            sp("<--");
            setCursor(15, textCenterEnd(22) + 1);
            sp("   ");
        }
        else
        {
            // Delete any other arrow
            setCursor(13, textCenterEnd(10) + 1);
            sp("   ");
            setCursor(15, textCenterEnd(22) + 1);
            sp("<--");
        }
    }
}

// The functions below declare where we are under conditions