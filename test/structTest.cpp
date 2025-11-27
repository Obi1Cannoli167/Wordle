// Testing struct definitions and functionalities
#include <Arduino.h>
#include "Core/structs.h"
#include "Core/codeParsedWordLibrary.h"
void setup()
{
    Serial.begin(115200);

    // Create a Word instance and make it the first word in the wordLibrary
    Word testWord;
    strncpy(testWord.letters, wordLibrary[0].letters, sizeof(testWord.letters));
    testWord.frequency = wordLibrary[0].frequency;

    // Print Word details
    Serial.print("Word: ");
    Serial.println(testWord.letters);
    Serial.print("Frequency: ");
    Serial.println(testWord.frequency);

    // Create a Player instance
    Player player;
    strncpy(player.name, "Alice", sizeof(player.name));
    player.score = 0;

    // Print Player details
    Serial.print("Player Name: ");
    Serial.println(player.name);
    Serial.print("Player Score: ");
    Serial.println(player.score);
    Serial.print("Total Score: ");
    Serial.println(player.score);


    // Create a Game instance
    Game game1;
    strncpy(game1.gameID, "GAME1234", sizeof(game1.gameID));
    strncpy(game1.targetWord, testWord.letters, sizeof(game1.targetWord));
    strncpy(game1.playerName, player.name, sizeof(game1.playerName));
    game1.pointsToEarn = 0; // Initialize and compute later
    game1.isGameOver = false;
    game1.isWin = false;
    game1.wordAttempts[0][0] = '\0'; // Initialize first attempt as empty
    strncpy(game1.wordAttempts[1], "snake", sizeof(game1.wordAttempts[1])); // Example attempt
    strncpy(game1.wordAttempts[2], "abuse", sizeof(game1.wordAttempts[2])); // A successful attempt
    game1.pointsToEarn = (50*testWord.frequency)/(2); // Example points to earn

    // Print Game1 details
    Serial.print("Game ID: ");
    Serial.println(game1.gameID);
    Serial.print("Target Word: ");
    Serial.println(game1.targetWord);
    Serial.print("Player in Game: ");
    Serial.println(game1.playerName);
    Serial.print("First Attempt: ");
    Serial.println(game1.wordAttempts[1]);
    Serial.print("Second Attempt: ");
    Serial.println(game1.wordAttempts[2]);
    Serial.print("Points to Earn: ");
    Serial.println(game1.pointsToEarn);
    Serial.print("Is Game Over: ");
    Serial.println(game1.isGameOver);
    Serial.print("Is Win: ");
    Serial.println(game1.isWin);
}

void loop()
{
    // Empty loop
}