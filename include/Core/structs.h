#ifndef STRUCTS_H
#define STRUCTS_H

struct Word
{
    char letters[6]; // Assuming a maximum word length of 5 characters + null terminator. Duplicates are avoided in the creation of the word library.
    int frequency;   // Usage rate of the word in the dictionary. From common to rare rated 1-3. Purpose is to give more points for guessing rarer words.
};

// Player struct to hold player-specific information, and what game they are playing
struct Player
{
    char name[11];    // Player's name, considered unique identifier
    char currentGame; // Current game played is held here via gameID, but is empty before first game played.
    int score = 0;    // Player's score
};
// In this struct, we define the Game struct
// The differentiation between game over and win is due to the fact we can both win or lose, which both mean the game is over
// Each game is tied to a specific user via the Player struct, as any instance of Game is held within a Player instance
struct Game
{
    char targetWord[6];         // The word to be guessed
    char playerName[11];           // The player associated with this game
    char gameID[10];         // Unique identifier for the game session
    char wordAttempts[6][6]; // Store up to 6 attempts of 5-letter words + null terminator, which is for the end of the string
    int pointsToEarn;        // Points to earn in the game when won
    bool isGameOver;         // Flag to indicate if the game is over
    bool isWin;              // Flag to indicate if the player has won
};

#endif // STRUCTS_H