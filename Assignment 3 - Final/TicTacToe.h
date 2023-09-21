#pragma once
#include <iostream>
#include <iomanip>
#include <chrono>

// Credit: Joe Bryant & Erik Santana - TicTacToe

static const int ROW_SIZE = 3;
static const int COL_SIZE = 3;

int inputInteger(std::string prompt, int startRange, int endRange); // Gets user input. Uuser inputs the row and column number.
void mainMenu(); // Main Menu 
char inputChar(std::string prompt, std::string options); // Gets user choice, if the user wants to play again.

class TicTacToe
{
private:

	char boardUpdate[ROW_SIZE][COL_SIZE] = { {' ', ' ', ' '}, {' ', ' ', ' '}, {' ', ' ', ' '} };
	int row;
	int column;
	int gamesPlayed;

public:

	// Pre-Condition: no parameters
	// Post-Condition: no return. Initializer Constructor.
	TicTacToe();

	// Pre-Condition: no parameters
	// Post-Condition: returns row. Gets the rows
	int getRow() const;

	// Pre-Condition: parameters: int newRow
	// Post-Condition: no return. Sets the rows
	void setRow(int newRow);

	// Pre-Condition: no parameters.
	// Post-Condition: no return. Gets the columns.
	int getColumn() const;

	// Pre-Condition: parameters: int newColumn
	// Post-Condition: no return. Sets the Column
	void setColumn(int newColumn);

	// Pre-Condition: no parameters
	// Post-Condition: no return. This is the main function of the game engine tic-tac-toe
	void ticTacToe();

	// Pre-Condition: parameters: char playerSymbol &  int& moves used for the current player and keeping track of # of moves
	// Post-Condition: no return. This is for the human to input their move.
	const void makeMove(char playerSymbol, int& moves);

	// Pre-Condition: no parameters
	// Post-Condition: no return. Updates the board
	void updateBoard();

	// Pre-Condition: parameters: char playerSymbol
	// Post-Condition: returns a boolean. Checks for winner
	const bool checkWin(char playerSymbol);

	// Pre-Condition: no parameters
	// Post-Condition: returns a boolean. Checks for draw
	bool checkDraw();

	// Pre-Condition: no parameters
	// Post-Condition: no return. Initializes the random number generator with a seed.
	void initRandom();

	// Pre-Condition: parameters: char playerSymbol. Takes in the computer move and randomizes the position.
	// Post-Condition: no return
	const void computerMove(char playerSymbol);

	// Pre-Condition: no parameters
	// Post-Condition: no return. Resets the board to empty spaces.
	void resetBoard();

	// Pre-Condition: parameters: double fastTime, int fastTimeMoves, double longTime, int longTimeMoves, double sum
	// Post-Condition: no return. Provides game statistics.
	const void gameStatistics(double fastTime, int fastTimeMoves, double longTime, int longTimeMoves, double sum);
};
