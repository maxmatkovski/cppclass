#include <iostream>
#include <string>
using namespace std;


/*
PIC 10B, LEC 2, Homework 1
Purpose: Tic-tac-toe game
Author: Max Matkovski
Date: 10/18/2021

*/

// Array for the board
char board[3][3] = { {'1','2','3'},{'4','5','6'},{'7','8','9'} };

// Declare Variables
int selection;
int row, column;
int game_number;
char turn = 'X';
bool draw = false;
string player1, player2;

// Declare Classes
class Game {
	public:

};

class Person {

};

// Start Game
void start_game() {
	// Prompt for number of Games, Player Names
	cout << "Number of games: " << flush;
	cin >> game_number;

	cout << "Player 1 Name: " << flush;
	cin.ignore(); getline(cin, player1);

	cout << "Player 2 Name: " << flush;
	getline(cin, player2);
}


// Display Board Function
void display_board() {

	cout << player1 << " (X) - " << player2 << " (O)" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[0][0] << "  |  " << board[0][1] << "  |  " << board[0][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[1][0] << "  | " << board[1][1] << "   |  " << board[1][2] << endl;
	cout << "_____|_____|_____" << endl;
	cout << "     |     |     " << endl;
	cout << "  " << board[2][0] << "  | " << board[2][1] << "   |  " << board[2][2] << endl;
	cout << "     |     |     " << endl;
}

// Function to make each move in tic-tac-toe
void player_turn() {

	// Input from user and updating 
	if (turn == 'X') {
		cout << player1 << " [X]  turn: " << flush;
	}
	else if (turn == 'O') {
		cout << player2 << " [O] turn : " << flush;
	}

	cin >> selection;

	// switch statement to know where to update
	switch (selection) {
		case 1: row = 0; column = 0; break;
		case 2: row = 0; column = 1; break;
		case 3: row = 0; column = 2; break;
		case 4: row = 1; column = 0; break;
		case 5: row = 1; column = 1; break;
		case 6: row = 1; column = 2; break;
		case 7: row = 2; column = 0; break;
		case 8: row = 2; column = 1; break;
		case 9: row = 2; column = 2; break;
		default:
			cout << "Invalid Choice";
	}

	if(turn == 'X' && board[row][column] != 'X' && board[row][column]!='O'){
		// update 'X' position if square is not already open

		board[row][column] = 'X';
		turn = 'O';
	}
	else if (turn == 'O' && board[row][column] != 'X' && board[row][column] != 'O') {
		// update 'O' position if square is not already open

		board[row][column] = 'O';
		turn = 'X';
	}
	else {
	// if input already filed
		cout << "Box filled. Please make another selection" << endl;
		player_turn();
	}
	/*Ends*/
	display_board();
}

bool game_over() {
	// check for win on simple row and column
	for (int i = 0; i < 3; i++) {
		if (board[i][0] == board[i][1] && board[i][0] == board[i][2] || board[0][i] == board[1][i] && board[0][i] == board[2][i]) 
			return false;
		}

	//check for win on diagnol

	if (board[0][0] == board[1][1] && board[0][0] == board[2][2] || board[0][2] == board[1][1] && board[0][2] == board[2][0]) {
		return false;
	}


	// checking whether game is in "continue mode" or not 
	for (int i = 0; i<3;i++)
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != 'X' && board[i][j] != 'O') {
				return true;
			}
		}
	
	draw = true;
	return false;
	}

void outcome_message() {
	if (turn == 'X' && draw == false) {
		cout << "Player with 'O' has won the game";
	}
	else if (turn == 'O' && draw == false) {
		cout << "Player with 'X' has won the game";
	}
	else {
		cout << "Game draw";
	}

}

int main() {

	// Display board originally
	display_board();
	
	// Loop to play Game until Game is over
	while (game_over()) {
		player_turn();
		game_over();
	}
	
	// Show outcome message
	outcome_message();

	return 0;
}
