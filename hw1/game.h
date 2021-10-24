#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Person;

class Game {
public:

	void start_game();
	void player_turn();
	bool game_over();
	void display_board();
	void outcome_message();
	void create_person();
	void reset_board();
	~Game();


	// Vectors for the board
	vector<string> board = { "123","456","789"};

	// Declare Variables
	int selection;
	int row, column;
	int game_number;
	char turn = 'X';
	bool draw = false;
	Person *Player1, *Player2;



};


#endif