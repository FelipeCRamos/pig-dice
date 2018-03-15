#ifndef UTIL_H
#define UTIL_H

#define DICE_RANGE 6
#define NUM_PLAYERS 2	
#define SCORE_LIMIT 100	
#define MAX_ERRORS_LIMIT 10

#include <iostream>
#include <iomanip>

// User box, that contains all the informations about the player when passed PlayerBox *
class PlayerBox{
	public:
	std::string name;
	int hold_plays = 0;
	int hold_score = 0;
	int score = 0;
	int last_dice = 0;
};

// A cool pretty header for the Pig Game
void prettyHeader(void);

// A detailed stats show
void printStats(PlayerBox *player);

// A minimal stats show
void minimalStats(PlayerBox *player);

// Just a function to change turns
void changeTurn(int *turn, int num_of_players);

// A simple separator, just to make things equal
void separator(char sep);

#endif
