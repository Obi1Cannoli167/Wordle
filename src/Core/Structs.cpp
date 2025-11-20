#include "Core/structs.h"
// This file is intended to define core data structures used throughout the project. This can include players, game states, configurations, words etc.

struct Word
{
    char letters[6]; // Assuming a maximum word length of 5 characters + null terminator
    int frequency;   // Usage rate of the word in the dictionary. From common to rare rated 1-3. Purpose is to give more points for guessing rarer words.
};

// In this struct, we clarify the state of the game, which can possibly hold different cases
// The differentiation between game over and win is due to the fact we can both win or lose, which mean the game is over
struct GameState
{
    Word targetWord;        // The word to be guessed
    char gameID[10];      // Unique identifier for the game session
    int attemptsLeft;      // Number of attempts remaining
    bool isGameOver;       // Flag to indicate if the game is over
    bool isWin;            // Flag to indicate if the player has won
};

// Player struct to hold player-specific information, and what game they are playing
struct Player
{
    char name[10];         // Player's name
    GameState currentGame; // Current game state for the player.
    int score;             // Player's score
    int totalGamesPlayed;  // Total number of games played
    int totalWins;         // Total number of wins
};