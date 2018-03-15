#include <iostream>
#include <vector>
#include <algorithm>

#include "util.h" 				// Header with useful things
#include "dice.h" 				// Header with all dice things
#include "chooser.h"			// IA Implement

using namespace std;

int main(int argc, char **argv){
	
	int wrong_inputs = 0;
	system("clear");
	
	prettyHeader();

	// Welcome text
	cout << "Seja bem vindo ao Pig Dice" << endl << endl;
	cout << "Por favor, digite seu nome: \n";

	// Allocating memory for NUM_PLAYERS boxes
	vector<PlayerBox> player (NUM_PLAYERS);	

	// Trying to implement IA
	//chooseRandom(&player[0]); 
	
	// This defines whos turn is
	int turn = 0;
	
	// Name of the human player
	cin >> player[turn].name;
	player[1].name = "Computer";
	//system("clear");

	int inside_play = 0;	

	// While game is not over, we keep going
	while(true){
		// A printing function to in each play, print everybody status
		if(!inside_play){
			for (int i = 0; i < NUM_PLAYERS; i++){
				minimalStats(&player[i]);
			}
		}

		// A condition to see if the player has won the game
		if(player[turn].hold_score + player[turn].score >= SCORE_LIMIT) break;

		// A simple highlight on user turn
		if(player[turn].name != "Computer"){
			cout << "\e[1m\x1b[36m" << player[turn].name;
		} else {
			cout << player[turn].name;
		}

		cout << ", Hold or roll? \e[0m\x1b[0m (or 'exit' to leave)" << endl;
		string decision;	

		// Conditional to see who's going to play and get the decision
		if(player[turn].name == "Computer"){
			decision = chooseRandom(&player[turn]);
		} else {
			cin >> decision;
		}


		//system("clear");
		prettyHeader();
	
		// If the answer is hold
		if(decision == "hold" or decision == "Hold" or decision == "h"){
			wrong_inputs = 0;
			// Will show only on user turn
			if(player[turn].name != "Computer")	cout << "You decided to hold" << endl;

			// updating stats
			player[turn].score += player[turn].hold_score;
			player[turn].hold_score = 0;
			player[turn].hold_plays = 0;
			player[turn].last_dice = 0;

			// Changing turn
			changeTurn(&turn, NUM_PLAYERS);

			cout << "Now it's " << player[turn].name << " turn!" << endl;
			inside_play = 0;

		// else, throw the dice and do the things	
		} else if(decision == "roll" or decision == "Roll" or decision == "r"){
			wrong_inputs = 0;	
			// Will show only on user turn
			if(player[turn].name != "Computer") cout << "You decided to roll" << endl;

			// Throw the dice
			int dice_result = dice(DICE_RANGE);
			cout << "\x1b[32mThrowing the dice....... " << "The dice returned " << dice_result << "\x1b[0m" << endl;
			separator('~');

			// updating stats
			player[turn].last_dice = dice_result;

			if(dice_result == 1){
				player[turn].hold_score = 0;
				// Changing turns
				changeTurn(&turn, NUM_PLAYERS);

				cout << "\x1b[31mOps! The dice returned 1, now it's ";
				cout << player[turn].name << " turn!\x1b[0m" << endl;

				// Updating stats
				player[turn].hold_plays = 0;
				player[turn].last_dice = 0;

				inside_play = 0;
			}
			else{
				// Updating stats
				player[turn].hold_score += dice_result;
				player[turn].hold_plays++;

				inside_play = 1;
			}

		} else {
			if (decision == "exit"){
				cout << "Bye friend! :D" << endl; 
				return 0;
			}
			cout << "Please, choose a valid option (hold/roll)" << endl;
			wrong_inputs++;
			if(wrong_inputs >= MAX_ERRORS_LIMIT){
				cout << "You failed with the force, leaving the program now!" << endl;
				return 1;
			}	
		}
	}
	cout << "Congratulations! Player " << player[turn].name << " has won the game!" << endl;
	
	return 0;
}
