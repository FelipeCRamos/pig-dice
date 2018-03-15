#include <iostream>
#include <iomanip>
#include "util.h"
#define WIDTH 60

using namespace std;

void prettyHeader(void){
	cout << endl << endl;
	cout << setfill ('~') << setw(WIDTH/2)<< right << "PIG GAME";
	cout << setfill ('~') << setw(WIDTH/2) << left << "" << endl;
}
void printStats(PlayerBox *player){
	separator('~');

	cout << "Player " << player->name << ":" << endl;

	separator('~');

	cout << "Total Score: " << player->score << " pontos." << endl;
	cout << "Temporary score: " << player->hold_score << " pontos." << endl;

	separator('~');
}
void minimalStats(PlayerBox *player){
	cout << player->name << ": " << player->hold_score << "/" << player->score << endl;
	separator('~');
}

void changeTurn(int *turn, int num_of_players){
	*turn = (*turn + 1) % num_of_players;
}

void separator(char sep){
	cout << setfill(sep) << setw(WIDTH) << "" << endl;
}
