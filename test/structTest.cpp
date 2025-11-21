// Testing struct definitions and functionalities
#include <Arduino.h>
#include "Core/structs.h"
void setup()
{
    Serial.begin(115200);

    // Create a Word instance
    Word testWord;
    strncpy(testWord.letters, "apple", sizeof(testWord.letters));
    testWord.frequency = 2;

    // Print Word details
    Serial.print("Word: ");
    Serial.println(testWord.letters);
    Serial.print("Frequency: ");
    Serial.println(testWord.frequency);

    // Create a Game instance
    Game game1;
    game1.targetWord = testWord;
    strncpy(game1.gameID, "GAME1234", sizeof(game1.gameID));
    game1.isGameOver = false;
    game1.isWin = false;

    // Print Game1 details
    Serial.print("Game ID: ");
    Serial.println(game1.gameID);
    Serial.print("Is Game Over: ");
    Serial.println(game1.isGameOver);
    Serial.print("Is Win: ");
    Serial.println(game1.isWin);

    // Create a Player instance
    Player player;
    strncpy(player.name, "Alice", sizeof(player.name));
    player.currentGame = game1;
    player.score = 0;
    player.totalGamesPlayed = 0;
    player.totalWins = 0;

    // Print Player details
    Serial.print("Player Name: ");
    Serial.println(player.name);
    Serial.print("Player Score: ");
    Serial.println(player.score);
    Serial.print("Total Games Played: ");
    Serial.println(player.totalGamesPlayed);
    Serial.print("Total Wins: ");
    Serial.println(player.totalWins);
}

void loop()
{
    // Empty loop
}