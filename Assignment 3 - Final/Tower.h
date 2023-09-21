#pragma once
#include <iostream>
#include <chrono>
#include <iomanip>
#include <vector>
#include <map>
#include <string>

// Credit: Saul Merino& John Kim& Christian Hernandez - Tower Of Hanoi

using namespace std;

int inputInteger(string prompt, int start, bool greater);
char inputChar(string prompt, string options);
char inputChar(string prompt, char yes, char no);
void mainMenu();

class Tower
{
private:
	char option = 0;
	int rings = 0;
	int moves = 0;
	int max_discs = 64;

	vector<int> A_Peg;
	vector<int> B_Peg;
	vector<int> C_Peg;

	char Peg1_choice;
	char Peg2_choice;

	// Maps to keep track of the game stats
	map<int, int> fast_time;
	map<int, int> slow_time;
	map<int, int> total_games;
	map<int, int> fastest_moves_each_game;
	map<int, int> slowest_moves_each_game;

public:

	// Pre-Condition: no parameters.
	// Post-Condition: no return. Game start
	void tower();

	// Pre-Condition: parameters: const vector<int>& A_Peg, const vector<int>& B_Peg, const vector<int>& C_Peg
	// Post-Condition: no return. This function updates the pegs
	void updatePegs(const vector<int>& A_Peg, const vector<int>& B_Peg, const vector<int>& C_Peg);
};

