#include "Tower.h"

// Credit: Saul Merino& John Kim& Christian Hernandez - Tower Of Hanoi

// Pre-Condition: no parameters.
// Post-Condition: no return. Game start
void Tower::tower()
{
	clock_t start_time;
	clock_t	end_time;

	for (int i = 1; i <= max_discs; ++i)
	{
		fast_time[i] = INT_MAX;
		fastest_moves_each_game[i] = INT_MAX;
	}
	do
	{
		system("cls");
		cout << "\n\tThe Tower of Hanoi also called the Tower of Brahma or Lucas' Tower is a mathematical game.";
		cout << "\n\tIt consists of three pegs and a number of rings of different sizes, which can slide onto";
		cout << "\n\tany peg.The game starts with the rings in a neat stack in ascending order of size on one";
		cout << "\n\tpeg, the smallest at the top, thus making a conical shape.";
		cout << "\n\n\tThe objective of the game is to move the entire stack from the starting peg - A to ending peg - B,";
		cout << "\n\tobeying the following simple rules:";
		cout << "\n\n\t\t1. Only one disk can be moved at a time.";
		cout << "\n\t\t2. Each move consists of taking the upper disk from one of the stacks and";
		cout << "\n\t\t   placing it on top of another stack or on an empty peg.";
		cout << "\n\t\t3. No larger disk may be placed on top of a smaller disk.\n";

		// Clear the elements 
		A_Peg.clear();
		B_Peg.clear();
		C_Peg.clear();
		moves = 0;

		rings = inputInteger("\n\tEnter the number of rings (1..64) to begin: ", 1, max_discs);

		// Start the time
		start_time = clock();

		// Store the rings in descending order for the A Peg
		for (int i = rings; i >= 1; i--)
		{
			A_Peg.push_back(i);
		}

		updatePegs(A_Peg, B_Peg, C_Peg);

		// Flag to validate the move
		bool moved = false;

		do
		{
			Peg1_choice = inputChar("\n\tSelect the top disk from the start peg (A, B, C, or Q-quit): ", (static_cast<string>("ABCQ")));
			Peg2_choice = inputChar("\tSelect the end peg (A, B, C, or Q-quit) to move the selected disk: ", (static_cast<string>("ABCQ")));
			switch (toupper(Peg1_choice))
			{
			case 'A':
			{
				//check if A Peg is empty
				if (A_Peg.empty())
				{
					cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-A.\n";
					cout << "\t\tPlease choose again.";

					updatePegs(A_Peg, B_Peg, C_Peg);
					break;
				}
				if (toupper(Peg2_choice) == 'B')
				{
					if (B_Peg.empty() || A_Peg.back() < B_Peg.back())
					{
						// push elemnent from A peg to B peg
						B_Peg.push_back(A_Peg.back());

						// pop it from A peg  
						A_Peg.pop_back();
						cout << "\n\tTop disk from peg-A has moved to peg-B.";

						//display the Tower of Hanoi
						updatePegs(A_Peg, B_Peg, C_Peg);

						moved = true;
					}
					else
					{
						cout << "\n\tERROR: Cannot make the move. Top disk(" << A_Peg.back() << ") of peg-A, is larger than top disk(" << B_Peg.back() << ") of peg-B.\n";
						cout << "\t\tPlease choose again.\n";
						updatePegs(A_Peg, B_Peg, C_Peg);
					}
				}
				else if (toupper(Peg2_choice) == 'C')
				{
					if (C_Peg.empty() || A_Peg.back() < C_Peg.back())
					{
						// push elemnent from A peg to C peg
						C_Peg.push_back(A_Peg.back());
						A_Peg.pop_back();

						cout << "\n\tTop disk from peg-A has moved to peg-C.";

						// display the Tower of Hanoi
						updatePegs(A_Peg, B_Peg, C_Peg);
						moved = true;
					}
					else
					{
						cout << "\n\tERROR: Cannot make the move. Top disk(" << A_Peg.back() << ") of peg-A, is larger than top disk(" << C_Peg.back() << ") of peg-C.\n";
						cout << "\t\tPlease choose again.\n";
						updatePegs(A_Peg, B_Peg, C_Peg);
					}
				}
				else if (toupper(Peg2_choice) == 'Q')
				{
					return;
				}
			}
			break;
			case 'B':
			{
				// Validation of B peg
				if (B_Peg.empty())
				{
					cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-B.\n";
					cout << "\t\tPlease choose again.";

					updatePegs(A_Peg, B_Peg, C_Peg);
					break;
				}
				if (toupper(Peg2_choice) == 'A')
				{
					if (A_Peg.empty() || B_Peg.back() < A_Peg.back())
					{
						// push elemnent from B peg to A peg
						A_Peg.push_back(B_Peg.back());
						B_Peg.pop_back();

						cout << "\n\tTop disk from peg-B has moved to peg-A.";

						// display the Tower of Ha Noi
						updatePegs(A_Peg, B_Peg, C_Peg);
						moved = true;
					}
					else
					{
						cout << "\n\tERROR: Cannot make the move. Top disk(" << B_Peg.back() << ") of peg-B, is larger than top disk(" << A_Peg.back() << ") of peg-A.\n";
						cout << "\t\tPlease choose again.\n";
						updatePegs(A_Peg, B_Peg, C_Peg);
					}
				}
				else if (toupper(Peg2_choice) == 'C')
				{
					if (C_Peg.empty() || B_Peg.back() < C_Peg.back())
					{
						// push elemnent from B peg to C peg
						C_Peg.push_back(B_Peg.back());
						B_Peg.pop_back();

						cout << "\n\tTop disk from peg-B has moved to peg-C.";

						updatePegs(A_Peg, B_Peg, C_Peg);
						moved = true;
					}
					else
					{
						cout << "\n\tERROR: Cannot make the move. Top disk(" << B_Peg.back() << ") of peg-B, is larger than top disk(" << C_Peg.back() << ") of peg-C.\n";
						cout << "\t\tPlease choose again.\n";

						updatePegs(A_Peg, B_Peg, C_Peg);
					}
				}
				else if (toupper(Peg2_choice) == 'Q')
				{
					return;
				}

				break;
			}
			case 'C':
			{
				// Validation for C Peg
				if (C_Peg.empty())
				{
					cout << "\n\tERROR: Cannot make the move. There is no disk in the selected peg-C.\n";
					cout << "\t\tPlease choose again.";

					updatePegs(A_Peg, B_Peg, C_Peg);
					break;
				}
				if (toupper(Peg2_choice) == 'A')
				{
					if (A_Peg.empty() || C_Peg.back() < A_Peg.back())
					{
						// push elemnent from C peg to A peg
						A_Peg.push_back(C_Peg.back());
						C_Peg.pop_back();

						cout << "\n\tTop disk from peg-C has moved to peg-A.";

						// display the tower of Ha Noi
						updatePegs(A_Peg, B_Peg, C_Peg);
						moved = true;
					}
					else
					{
						cout << "\n\tERROR: Cannot make the move. Top disk(" << C_Peg.back() << ") of peg-C, is larger than top disk(" << A_Peg.back() << ") of peg-A.\n";
						cout << "\t\tPlease choose again.\n";
						updatePegs(A_Peg, B_Peg, C_Peg);
					}
				}
				else if (toupper(Peg2_choice) == 'B')
				{
					if (B_Peg.empty() || C_Peg.back() < B_Peg.back())
					{
						// push elemnent from B peg to C peg
						B_Peg.push_back(C_Peg.back());
						C_Peg.pop_back();

						cout << "\n\tTop disk from peg-C has moved to peg-B.";

						updatePegs(A_Peg, B_Peg, C_Peg);
						moved = true;
					}
					else
					{
						cout << "\n\tERROR: Cannot make the move. Top disk(" << C_Peg.back() << ") of peg-C, is larger than top disk(" << B_Peg.back() << ") of peg-B.\n";
						cout << "\t\tPlease choose again.\n";
						updatePegs(A_Peg, B_Peg, C_Peg);
					}
				}
				else if (toupper(Peg2_choice) == 'Q')
				{
					return;
				}
				break;
			}
			case 'Q':
			{
				if (toupper(Peg1_choice) == 'Q' || toupper(Peg2_choice) == 'Q')
				{
					system("pause");
					system("cls");
					mainMenu();
					return;
				}
			}
			}

			// Keep track of the moves
			if (moved != false)
			{
				moves++;
			}

			// Reset the flag
			moved = false;
		} while (C_Peg.size() < rings);

		// Stop the clock
		end_time = clock();

		// Calculating the time
		int game_time = (end_time - start_time) / CLOCKS_PER_SEC;

		// Get the fastest time
		fast_time[rings] = min(fast_time[rings], game_time);

		// Get the slowest time
		slow_time[rings] = max(slow_time[rings], game_time);

		// Increment how many games have been played with the discs numbers 
		total_games[rings]++;

		// Set the key to the value which is the moves now, we getting each move for each game we play
		fastest_moves_each_game[rings] = min(fastest_moves_each_game[rings], moves);
		slowest_moves_each_game[rings] = max(slowest_moves_each_game[rings], moves);

		cout << "\n\tCongratulation! You have solved the game in " << moves << " moves.\n";
		option = inputChar("\n\tPlay again? (Y-yes or N-no): ", 'y', 'n');

	} while (toupper(option) == 'Y');

	double average_seconds;

	cout << "\n\tGame statistics:\n\n";
	for (auto& i : total_games)
	{
		// The key and The value
		int discs_overall_used = i.first;
		int games = i.second;

		if (games == 1)
		{
			// The average seconds equals to them sum of fast time and slow time then divide by games played
			average_seconds = static_cast<double>(fast_time[discs_overall_used] + slow_time[discs_overall_used]) / 2.0;
			cout << "\t" << games << " game using " << discs_overall_used << " disks was played.\n";
		}
		else
		{
			// The average seconds equals to the sum of fast time and slow time then divide by games played
			average_seconds = static_cast<double>(fast_time[discs_overall_used] + slow_time[discs_overall_used]) / games;
			cout << "\t" << games << " games using " << discs_overall_used << " disks was played.\n";
		}
		cout << "\t\tThe fastest time was " << fast_time[discs_overall_used] << " seconds in " << fastest_moves_each_game[discs_overall_used] << " moves.\n";
		cout << "\t\tThe slowest time was " << slow_time[discs_overall_used] << " seconds in " << slowest_moves_each_game[discs_overall_used] << " moves.\n";
		cout << "\t\tThe average time was " << average_seconds << " second(s)\n";
	}

	system("pause");
}

// Pre-Condition: parameters: const vector<int>& A_Peg, const vector<int>& B_Peg, const vector<int>& C_Peg
// Post-Condition: no return. This function updates the pegs
void Tower::updatePegs(const vector<int>& A_Peg, const vector<int>& B_Peg, const vector<int>& C_Peg)
{
	cout << "\n\n\tTower of Hanoi\n\n"; // Title

	int discLimit = max(A_Peg.size(), max(B_Peg.size(), C_Peg.size())); // Largest size out of the pegs

	for (int i = discLimit; i >= 0; i--) // Switch biggest to smallest
	{
		cout << "\t"; // Tab over

		if (i < A_Peg.size()) // discLimit < size of A_Peg
		{
			int discSize = A_Peg[i];   //sets discSize to discLimit

			string discString = to_string(discSize); // Convert to string

			for (int j = 0; j < discString.size(); j++) // loop through discString[j]
			{
				cout << discString[j] << "";
			}
		}
		else
		{
			cout << string(1, char(186)) << ""; // display empty peg
		}

		cout << "\t"; // tab over

		if (i < B_Peg.size()) // discLimit < size of B_Peg
		{
			int ringSize = B_Peg[i]; // initialize with index

			string ringString = to_string(ringSize); // Convert to string

			for (int j = 0; j < ringString.size(); j++)
			{
				cout << ringString[j] << "";
			}
		}
		else
		{
			cout << string(1, char(186)) << ""; // display empty peg
		}

		cout << "\t"; // tab over

		if (i < C_Peg.size()) // discLimit < size of C_Peg
		{
			int ringSize = C_Peg[i];

			string ringString = to_string(ringSize); // Convert to string

			for (int j = 0; j < ringString.size(); j++)
			{
				cout << ringString[j] << "";
			}
		}
		else
		{
			cout << "" << string(1, char(186)) << ""; // display empty peg
		}
		cout << endl;
	}

	cout << "\t" << string(1, char(186)) << "\t" << string(1, char(186)) << "\t" << string(1, char(186)) << endl; //prints out bar for each peg

	cout << "     " << string(7, char(205)) << " " << string(7, char(205)) << " " << string(7, char(205)); //prints out bottom of the peg

	cout << endl << "\tA\tB\tC" << endl << endl; //displays peg letter
}