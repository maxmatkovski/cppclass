#include <iostream>
#include <string>
#include "game.h"
#include "person.h"
using namespace std;



/*
PIC 10B, LEC 2, Homework 1
Purpose: Tic-tac-toe game
Author: Max Matkovski
Date: 10/18/2021
*/



// Declare Classes



int main() {

	Game myGame;
	myGame.create_person();
	myGame.start_game();

	for (int i = 0; i < myGame.game_number; i++) {

		// Display board originally
		myGame.display_board();

		// Loop to play Game until Game is over
		while (myGame.game_over()) {
			myGame.player_turn();
			myGame.game_over();
		}

		// Show outcome message
		myGame.outcome_message();


		// Reset Board

		myGame.reset_board();
	}
	return 0;
}