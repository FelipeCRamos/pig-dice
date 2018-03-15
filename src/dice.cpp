#include "dice.h"

int dice(int range){
	std::mt19937 random (std::chrono::system_clock::now().time_since_epoch().count());
	return random() % range + 1;
}
