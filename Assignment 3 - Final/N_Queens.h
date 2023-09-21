#pragma once
#include <vector>
#include <iostream>
#include <chrono>
#include <string>
#include <iomanip>

// Credit: Otoniel Torres Bernal& Thanh Tran: n - Queens

int inputInteger(std::string prompt, int start, bool greater);
char inputChar(std::string prompt, std::string options);
char inputChar(std::string prompt, char yes, char no);
void mainMenu();

class N_Queens
{
private:
	int size;
	std::vector<std::vector<char>> board;
public:
	N_Queens();
	N_Queens(int new_size);

	bool is_safe(int row, int col) const;
	bool place_queen(int row, int col);

	bool remove_queen(int row, int col);
	bool is_solved() const;

	void reset_board();
	void displayBoard() const;

	void N_queens();
	void game_statistics_queens(int total_games, double fastTime, int fastTimeMoves, double longTime, int longTimeMoves, double sum, int size);
};
