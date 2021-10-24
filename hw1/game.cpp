#include "game.h"
#include "person.h"

// Start Game
void Game::start_game() {
	// Prompt for number of Games, Player Names
	cout << "Number of games: " << flush;
	cin >> game_number;

	cout << "Player 1 Name: " << flush;
	cin.ignore(); getline(cin, Player1->player_name);

	cout << "Player 2 Name: " << flush;
	getline(cin, Player2->player_name);
}


// Display Board Function
void Game:: display_board() {

	cout << Player1->player_name << " (X) - "  << "Score: " << Player1->player_score << " | " << Player2->player_name << " (O) " << "Score: " << Player2->player_score << endl;
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
void Game::player_turn() {

	// Input from user and updating 
	if (turn == 'X') {
		cout << Player1->player_name << " [X]  turn: " << flush;
	}
	else if (turn == 'O') {
		cout << Player2->player_name << " [O] turn : " << flush;
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

	if (turn == 'X' && board[row][column] != 'X' && board[row][column] != 'O') {
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

bool Game::game_over() {
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
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++) {
			if (board[i][j] != 'X' && board[i][j] != 'O') {
				return true;
			}
		}

	draw = true;
	return false;
}

void Game::outcome_message() {
	if (turn == 'X' && draw == false) {
		cout << "Player with 'O' has won the game" << endl;
		Player2->player_score += 1;
	}
	else if (turn == 'O' && draw == false) {
		cout << "Player with 'X' has won the game" << endl;
		Player1->player_score += 1;
	}
	else {
		cout << "Game draw";
	}
}

void Game::create_person() {
	Player1= new Person();
	Player2 = new Person();
}

void Game::reset_board() {

	board = { "123","456","789" };

}

Game::~Game() {
	delete Player1;
	delete Player2;
}