#include "chooser.h"
#include <thread>
std::string chooseRandom(PlayerBox *player){
	if(player->hold_score == 0) return "roll";
	std::mt19937 random (std::chrono::system_clock::now().time_since_epoch().count());

	std::cout << "Thinking in next move..." << std::endl;
		
	// waiter
	std::this_thread::sleep_for(std::chrono::milliseconds((random() % 1000) + 500));

	std::mt19937 random2 (std::chrono::system_clock::now().time_since_epoch().count());
	long int seed = (random2()+random()) % 100;

	if(player->hold_score > 25) return "hold";	

	std::mt19937 random3 (std::chrono::system_clock::now().time_since_epoch().count());
	int percent = 30;	
		
	if(seed >= percent + (random() % 5)){
	//if(player->last_dice >= 2){
		std::cout << "The computer decided to roll!" << std::endl;
		player->hold_plays++;
		return "roll";
	} else {
		std::cout << "The computer decided to hold!" << std::endl;
		player->hold_plays = 0;
		return "hold";
	}
}
// SFML lib to create games
