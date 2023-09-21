#include "N_Queens.h"

// Credit: Otoniel Torres Bernal& Thanh Tran: n - Queens

//************************************** Constructor **********************************//

// Arg-constructor
//Precondition: a positive int size value
//Postcondtion: sets the size value to the attributes of the objects 
N_Queens::N_Queens()
{
	size = 0;
	board = std::vector<std::vector<char>>(size, std::vector<char>(size, '.'));
}

// Arg-constructor
//Precondition: a positive int size value
//Postcondtion: sets the size value to the attributes of the objects 
N_Queens::N_Queens(int new_size)
{
    size = new_size;
    board = std::vector<std::vector<char>>(new_size, std::vector<char>(new_size, '.'));
}

//************************************** Public Function ********************************//

//Precondition: positive int row and column parameters
//Postcondtion: return true if there is no Queens at the current coordinates otherwise return false
bool N_Queens::is_safe(int row, int column) const
{
    // Check row and column
    for (int i = 0; i < size; ++i)
    {
        if (board[row][i] == 'Q' || board[i][column] == 'Q')
        {
            return false;
        }
    }

    // Check diagonals
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (board[i][j] == 'Q' && abs(i - row) == abs(j - column))
            {
                return false;
            }
        }
    }

    return true;
}

//Precondition: positive int row and column parameters
//Postcondtion: return true and set the Queen into the coordinate if its satisfy all conditions otherwise return false
bool N_Queens::place_queen(int row, int column)
{
    if (row < 0 || row >= size || column < 0 || column >= size || !is_safe(row, column))
    {
        return false;
    }

    board[row][column] = 'Q';
    return true;
}

//Precondition: positive int row and column parameters
//Postcondtion: return true and remove the Queen into the coordinate if its satisfy all conditions otherwise return false
bool N_Queens::remove_queen(int row, int column)
{
    if (row < 0 || row >= size || column < 0 || column >= size || board[row][column] != 'Q')
    {
        return false;
    }

    board[row][column] = '.';
    return true;
}

//Precondition: NA
//Postcondtion: return true if the puzzle is solved otherwise return false 
bool N_Queens::is_solved() const
{
    // Check if all queens have been placed
    int queens_placed = 0;
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (board[i][j] == 'Q')
            {
                queens_placed++;
            }
        }
    }

    // Check if all queens are safe
    if (queens_placed == size)
    {
        return true;
    }
    else
        return false;
}

//Precondition: NA
//Postcondtion: reset the board value 
void N_Queens::reset_board()
{
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            board[i][j] = '.';
        }
    }
}

//Precondition: NA
//Postcondtion: display the board
void N_Queens::displayBoard() const
{
	std::cout << "\n";
    for (int i = 0; i < size; ++i)
    {
		std::cout << "\t";
        for (int j = 0; j < size; ++j)
        {
			std::cout << board[i][j] << ' ';
        }
		std::cout << '\n';
    }
}

void N_Queens::N_queens()
{
	int row = 0;
	int column = 0;
	int moves = 0;
	int size = 0;

	char choice = ' ';
	char option = 'Y';

	double gameDuration = 0;
	double fastTime = 0;
	double longTime = 0;

	int longTimeMoves = 0;
	int fastTimeMoves = 0;
	int total_games = 0;

	double sum = 0;

	std::vector<std::vector<double>> game_stats;
	std::vector <double> columns;

	// timer
	std::chrono::steady_clock::time_point start;
	std::chrono::steady_clock::time_point end;

	std::cout << "\n\tThe n - queens puzzle is the problem of placing n chess queens on a nxn chessboard";
	std::cout << "\n\tso that no two queens threaten each other; thus, a solution requires that no two";
	std::cout << "\n\tqueens share the same row, column, or diagonal.Solutions exist for all natural";
	std::cout << "\n\tnumbers n with the exception of n = 2 and n = 3.";

	do
	{
		size = inputInteger("\n\n\tEnter the board dimension nxn: ", 1, 64);

		N_Queens game(size);
		std::cout << "\n\t" << size << "-Queens";

		start = std::chrono::steady_clock::now();

		while (true)
		{
			game.displayBoard();

			std::cout << "\n\tGame Options";
			std::cout << "\n\t" + std::string(50, char(205));
			std::cout << "\n\tA> Place a queen";
			std::cout << "\n\tB> Remove an existing queen";
			std::cout << "\n\t" + std::string(50, char(196));
			std::cout << "\n\t0> return";
			std::cout << "\n\t" + std::string(50, char(205));

			choice = toupper(inputChar("\n\tOption: ", static_cast<std::string>("AB0)")));

			if (choice == 'A')
			{
				row = inputInteger("\n\tPosition a queen in the row (1.." + std::to_string(size) + "): ", 1, size);
				column = inputInteger("\tPosition a queen in the column (1.." + std::to_string(size) + "): ", 1, size);

				if (game.place_queen(row - 1, column - 1))
				{
					std::cout << "\n\tQueen placed successfully!\n\n";

					moves++;

					if (game.is_solved())
					{
						std::cout << "\n\tCongratulation!You have solved " + std::to_string(size) + "-Queens in " + std::to_string(moves) + " moves\n";
						game.displayBoard();

						total_games++;
						break;
					}
				}
				else
				{
					std::cout << "\n\tERROR: Invalid move.Try again.\n\n";
				}
			}
			else if (choice == 'B')
			{
				row = inputInteger("\n\tEnter an existing queen from the row(1.." + std::to_string(size) + "): ", 1, size);
				column = inputInteger("\tEnter an existing queen from the column (1.." + std::to_string(size) + "): ", 1, size);

				if (game.remove_queen(row - 1, column - 1))
				{
					std::cout << "\n\tQueen removed successfully!\n\n";
				}
				else
				{
					std::cout << "\n\tERROR: No such queen existed.\n";
				}
			}
			else if (choice == '0')
			{
				break;
			}
			else
			{
				std::cout << "Invalid choice. Please try again." << "\n";
			}
		}

		end = std::chrono::steady_clock::now();

		std::chrono::duration<double> duration = std::chrono::duration_cast<std::chrono::duration<double>>(end - start);
		gameDuration = duration.count();

		sum += gameDuration;

		if (total_games == 1)
		{
			fastTime = gameDuration;
			longTime = gameDuration;
			fastTimeMoves = moves;
			longTimeMoves = moves;
		}
		else if (gameDuration < fastTime)
		{
			fastTime = gameDuration;
			fastTimeMoves = moves;

		}
		else if (gameDuration > longTime)
		{
			longTime = gameDuration;
			longTimeMoves = moves;
		}

		option = toupper(inputChar("\n\tPlay again ? (Y - yes or N - no) ", 'Y', 'N'));

		game.reset_board();

	} while (option == 'Y');

	game_statistics_queens(total_games, fastTime, fastTimeMoves, longTime, longTimeMoves, sum, size);
}


//Precondition: game statistic variables
//Postcondtion: display the game stats
void N_Queens::game_statistics_queens(int total_games, double fastTime, int fastTimeMoves, double longTime, int longTimeMoves, double sum, int size)
{
	double mean = 0;

	if (total_games != 0)
	{
		mean = sum / (double)total_games;
	}

	if (total_games == 0)
	{
		std::cout << "\n\tNo game statistic collected.\n";
	}
	else
	{
		// Print the number of games played
		std::cout << "\n\tGame statistics: \n\n\t";
		std::cout << total_games << " game(s) N-queens were played.\n";
		std::cout << std::fixed << std::setprecision(0) << "\n\t\tThe fastest time was " << fastTime << " seconds in " << fastTimeMoves << " moves.";
		std::cout << std::fixed << std::setprecision(0) << "\n\t\tThe slowest time was " << longTime << " seconds in " << longTimeMoves << " moves.";
		std::cout << std::fixed << std::setprecision(0) << "\n\t\tThe average time was " << mean << " second(s).\n\n";
	}
}