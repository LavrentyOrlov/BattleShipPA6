/*
Programmer: Lavrenty "Larry" Orlov
Class: CptS 121; Lab Section 10L
Programming Assignment: Programming Assignment 6 - Basic Game of Battleship
Date: 11/14/2025
Description: This is a text-based version of a board game called BattleShip, played between a player and
the computer. This program's features include processing user input in the terminal window,
random number generation, mathematical computations, and displaying output results both in the
terminal window and in an output stream file.
*/

#include "BattleShip.h"

// Preconditions: none
// Prints a welcome screen and instructions for the Battleship game to the console screen
void welcome_screen(void)
{
	printf("****Welcome to Battleship!****\n");
	printf("\n");
	printf("Rules of the Game:\n");
	printf("\n");
	printf("Battleship is a two-player game where players secretly place ships on a grid and take turns calling\n");
	printf("out target coordinates to sink the opponent's ships, one cell at a time.");
	printf("\n");
	printf("In this version of Battleship, the two players are you and the computer!\n");
	printf("\n");
	printf("Each player has their own 2-dimensonal board where they store 5 ships: a Carrier (5 cells), Battleship (4 cells),\n");
	printf("Cruiser (3 cells), Submarine (3 cells), and Destroyer (2 cells).\n");
	printf("At the start of the game, each player places the ships on their board, making sure that none of the ships\n");
	printf("intersect or go out of bounds. You can eitehr place your 5 ships manually, or have them placed randomly.\n");
	printf("Then, the computer will place each of its 5 ships randomly.\n");
	printf("\n");
	printf("Once all the ships are placed, the game begins! Players take turns selecting one grid cell on the opponent's\n");
	printf("grid to try to hit part of their ship. When every cell occupied by a ship has been hit, that ship has been sunk.\n");
	printf("\n");
	printf("This process repeats until one of the players sinks all the ships in the other player's fleet, in which case they win!\n");
	printf("\n");
	printf("Ready to begin ? :D\n");
	printf("\n");
	system("pause");
}

// Preconditions: None
// Sets all values in a 2D board to the default '~' value
void init_board(char board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	// Nest loops should be used to initialize a 2-D array
	for (; row_index < num_rows; ++row_index) // controls the row
	{
		for (col_index = 0; col_index < num_cols; ++col_index) // controls the column
		{
			board[row_index][col_index] = '~'; // '~' is the water symbols
		}
	}
}

// Preconditions: Board contains char values, with integers passed in
// for rows, columns, and player
// Prints 2D board for the current player to the console screen
void print_board(char board[][MAX_COLS], int num_rows, int num_cols, int player)
{
	int row_index = 0, col_index = 0;

	if (1 == player)
	{
		puts("Player 1");
	}
	else // computer's board
	{
		puts("Computer");
	}

	// Nested loops should be used to initialize a 2-D array
	// print the column number before entering the loops
	printf("%3d%2d%2d%2d%2d%2d%2d%2d%2d%2d\n", 0, 1, 2, 3, 4, 5, 6, 7, 8, 9);
	for (; row_index < num_rows; ++row_index) // controls the row
	{
		printf("%-2d", row_index); // print the current row number
		for (col_index = 0; col_index < num_cols; ++col_index) // controls the column
		{
			if (2 == player) // computer's board
			{
				// check to see if the current element we're visiting
				// is a ship symbol - if so, mask it with the water symbol
				if (board[row_index][col_index] != 'm' &&
					board[row_index][col_index] != '*' &&
					board[row_index][col_index] != '~')
				{
					printf("%-2c", '~'); // mask the ship symbol with a water symbol
				}
				else
				{
					printf("%-2c", board[row_index][col_index]); // print the actual symbols stored
				}
			}
			else // player 1
			{
				printf("%-2c", board[row_index][col_index]); // print the actual symbols stored
			}
		}
		putchar('\n'); // set the next symbols to print to the next line in the console
	}
	putchar('\n'); // helps to space out the boards
}

int random_player_start(void)
{
	return rand() % NUMBER_OF_PLAYERS + 1;
}

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player one's carrier has been hit
int p1_carrier_gone(char p1_board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	// Nest loops should be used to initialize a 2-D array
	for (; row_index < num_rows; ++row_index) // controls the row
	{
		for (col_index = 0; col_index < num_cols; ++col_index) // controls the column
		{
			if (p1_board[row_index][col_index] == 'c')
			{
				return 0;
			}
		}
	}
	return 1;
}

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player one's battleship has been hit
int p1_battleship_gone(char p1_board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	// Nest loops should be used to initialize a 2-D array
	for (; row_index < num_rows; ++row_index) // controls the row
	{
		for (col_index = 0; col_index < num_cols; ++col_index) // controls the column
		{
			if (p1_board[row_index][col_index] == 'b')
			{
				return 0;
			}
		}
	}
	return 1;
}

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player one's cruiser has been hit
int p1_cruiser_gone(char p1_board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	// Nest loops should be used to initialize a 2-D array
	for (; row_index < num_rows; ++row_index) // controls the row
	{
		for (col_index = 0; col_index < num_cols; ++col_index) // controls the column
		{
			if (p1_board[row_index][col_index] == 'r')
			{
				return 0;
			}
		}
	}
	return 1;
}

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player one's submarine has been hit
int p1_submarine_gone(char p1_board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	// Nest loops should be used to initialize a 2-D array
	for (; row_index < num_rows; ++row_index) // controls the row
	{
		for (col_index = 0; col_index < num_cols; ++col_index) // controls the column
		{
			if (p1_board[row_index][col_index] == 's')
			{
				return 0;
			}
		}
	}
	return 1;
}

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player one's destroyer has been hit
int p1_destroyer_gone(char p1_board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	// Nest loops should be used to initialize a 2-D array
	for (; row_index < num_rows; ++row_index) // controls the row
	{
		for (col_index = 0; col_index < num_cols; ++col_index) // controls the column
		{
			if (p1_board[row_index][col_index] == 'd')
			{
				return 0;
			}
		}
	}
	return 1;
}

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player two's carrier has been hit
int p2_carrier_gone(char p2_board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	// Nest loops should be used to initialize a 2-D array
	for (; row_index < num_rows; ++row_index) // controls the row
	{
		for (col_index = 0; col_index < num_cols; ++col_index) // controls the column
		{
			if (p2_board[row_index][col_index] == 'c')
			{
				return 0;
			}
		}
	}
	return 1;
}

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player two's battleship has been hit
int p2_battleship_gone(char p2_board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	// Nest loops should be used to initialize a 2-D array
	for (; row_index < num_rows; ++row_index) // controls the row
	{
		for (col_index = 0; col_index < num_cols; ++col_index) // controls the column
		{
			if (p2_board[row_index][col_index] == 'b')
			{
				return 0;
			}
		}
	}
	return 1;
}

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player two's cruiser has been hit
int p2_cruiser_gone(char p2_board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	// Nest loops should be used to initialize a 2-D array
	for (; row_index < num_rows; ++row_index) // controls the row
	{
		for (col_index = 0; col_index < num_cols; ++col_index) // controls the column
		{
			if (p2_board[row_index][col_index] == 'r')
			{
				return 0;
			}
		}
	}
	return 1;
}

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player two's submarine has been hit
int p2_submarine_gone(char p2_board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	// Nest loops should be used to initialize a 2-D array
	for (; row_index < num_rows; ++row_index) // controls the row
	{
		for (col_index = 0; col_index < num_cols; ++col_index) // controls the column
		{
			if (p2_board[row_index][col_index] == 's')
			{
				return 0;
			}
		}
	}
	return 1;
}

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player two's destroyer has been hit
int p2_destroyer_gone(char p2_board[][MAX_COLS], int num_rows, int num_cols)
{
	int row_index = 0, col_index = 0;

	// Nest loops should be used to initialize a 2-D array
	for (; row_index < num_rows; ++row_index) // controls the row
	{
		for (col_index = 0; col_index < num_cols; ++col_index) // controls the column
		{
			if (p2_board[row_index][col_index] == 'd')
			{
				return 0;
			}
		}
	}
	return 1;
}

// Preconditions: output file is open
// Prints statistics for players to an output stream file after the game is over
void write_stats_to_log(FILE *output_log, Stats player_one_stats, Stats computer_stats)
{
	fprintf(output_log, "\n");
	fprintf(output_log, "\nPlayer 1 stats: \n");
	fprintf(output_log, "\n");
	fprintf(output_log, "Total hits: %d\n", player_one_stats.total_hits);
	fprintf(output_log, "Total misses: %d\n", player_one_stats.total_misses);
	fprintf(output_log, "Total shots: %d\n", player_one_stats.total_shots);
	fprintf(output_log, "Hits-to-misses ratio (as a percentage): %.2lf\n", player_one_stats.hits_to_misses_ratio_percentage);
	fprintf(output_log, "Win or lost the game: %d", player_one_stats.won_game);
	if (player_one_stats.won_game)
	{
		fprintf(output_log, ", which means you won!\n");
	}
	else
	{
		fprintf(output_log, ", which means you lost...\n");
	}

	fprintf(output_log, "\n");
	fprintf(output_log, "Computer stats: \n");
	fprintf(output_log, "\n");
	fprintf(output_log, "Total hits: %d\n", computer_stats.total_hits);
	fprintf(output_log, "Total misses: %d\n", computer_stats.total_misses);
	fprintf(output_log, "Total shots: %d\n", computer_stats.total_shots);
	fprintf(output_log, "Hits-to-misses ratio (as a percentage): %.2lf\n", computer_stats.hits_to_misses_ratio_percentage);
	fprintf(output_log, "Win or lost the game: %d", computer_stats.won_game);
	if (computer_stats.won_game)
	{
		fprintf(output_log, ", which means the computer won...\n");
	}
	else
	{
		fprintf(output_log, ", which means the computer lost!\n");
	}
}

// Preconditions: player to start is zero or one; player one and player two arrays store characters;
// output log file is already open
// Controls the process for running the gameflow of the battleship game including back-and-forth actions
// between players, determining when one of the players won, and adding results to a log output fil
void game_play(int player_to_start, char player_one_array[][MAX_COLS], PlayerOneShips player_one_ships_collection,
	           char player_two_array[][MAX_COLS], PlayerTwoShips player_two_ships_collection, Stats player_one_stats,
			   Stats computer_stats, FILE *output_log)
{
	int current_player = 0, target_row = 0, target_column = 0, all_p1_ships_hit = 0, all_p2_ships_hit = 0,
	p1_carrier_checked = 0, p1_battleship_checked = 0, p1_cruiser_checked = 0, p1_submarine_checked = 0,
	p1_destroyer_checked = 0, p2_carrier_checked = 0, p2_battleship_checked = 0, p2_cruiser_checked = 0, 
	p2_submarine_checked = 0, p2_destroyer_checked = 0;

	current_player = player_to_start;

	system("pause");

	while (!all_p1_ships_hit && !all_p2_ships_hit)
	{
		if (current_player == 1)
		{
			system("cls");
			printf("Your turn!\n");

			do
			{
				printf("\n");
				printf("Please type a target position as two numbers separated by a space, then\n");
				printf("press enter! If you provide values outside the range of 0-9, or a cell you've\n");
				printf("already targeted, you'll be asked to enter the two numbers again :)\n");

				scanf("%d %d", &target_row, &target_column);

			} while ((target_row < 0 || target_row > MAX_ROWS - 1) || (target_column < 0 || target_column > MAX_COLS) || (player_two_array[target_row][target_column] == '*' || player_two_array[target_row][target_column] == 'm'));

			player_one_stats.total_shots += 1;
			printf("Your total number of shots changed to: %d\n", player_one_stats.total_shots);

			fprintf(output_log, "\nYour targeted position: (%d, %d)", target_row, target_column);

			if (player_two_array[target_row][target_column] == '~')
			{
				printf("\n");
				printf("(%d, %d) is a miss!\n", target_row, target_column);
				fprintf(output_log, " \"miss\"");
				player_two_array[target_row][target_column] = 'm';
				player_one_stats.total_misses += 1;
				printf("Your total misses changed to: %d\n", player_one_stats.total_misses);
			}
			else
			{
				printf("\n");
				printf("(%d, %d) is a hit!\n", target_row, target_column);
				fprintf(output_log, " \"hit\"");
				player_two_array[target_row][target_column] = '*';
				player_one_stats.total_hits += 1;
				printf("Your total hits changed to: %d\n", player_one_stats.total_hits);
			}

			player_one_stats.hits_to_misses_ratio_percentage = ((double)player_one_stats.total_hits / player_one_stats.total_misses) * 100;
			printf("Your hits-to-misses ratio (expressed as a percentage) changed to: %.2lf percent!\n", player_one_stats.hits_to_misses_ratio_percentage);

			if (p2_carrier_gone(player_two_array, MAX_ROWS, MAX_COLS) && !p2_carrier_checked)
			{
				fprintf(output_log, " Sunk Carrier!");
				p2_carrier_checked = 1;
			}

			if (p2_battleship_gone(player_two_array, MAX_ROWS, MAX_COLS) && !p2_battleship_checked)
			{
				fprintf(output_log, " Sunk Battleship!");
				p2_battleship_checked = 1;
			}

			if (p2_cruiser_gone(player_two_array, MAX_ROWS, MAX_COLS) && !p2_cruiser_checked)
			{
				fprintf(output_log, " Sunk Cruiser!");
				p2_cruiser_checked = 1;
			}

			if (p2_submarine_gone(player_two_array, MAX_ROWS, MAX_COLS) && !p2_submarine_checked)
			{
				fprintf(output_log, " Sunk Submarine!");
				p2_submarine_checked = 1;
			}

			if (p2_destroyer_gone(player_two_array, MAX_ROWS, MAX_COLS) && !p2_destroyer_checked)
			{
				fprintf(output_log, " Sunk Destroyer!");
				p2_destroyer_checked = 1;
			}

			printf("\n");
			printf("Here's what we now know about the computer's board:\n");
			printf("\n");

			print_board(player_two_array, MAX_ROWS, MAX_COLS, 2);

			system("pause");

			current_player = 0;
		}
		else
		{
			system("cls");
			printf("Computer's turn!\n");
			system("pause");

			do
			{
				target_row = rand() % MAX_ROWS;
				target_column = rand() % MAX_COLS;
			} while (player_one_array[target_row][target_column] == '*' || player_one_array[target_row][target_column] == 'm');

			computer_stats.total_shots += 1;
			printf("Computer's total number of shots changed to: %d\n", computer_stats.total_shots);
			
			fprintf(output_log, "\nComputer's targeted position: (%d, %d)", target_row, target_column);

			if (player_one_array[target_row][target_column] == '~')
			{
				printf("\n");
				printf("Computer missed at (%d, %d)!\n", target_row, target_column);
				fprintf(output_log, " \"miss\"");
				player_one_array[target_row][target_column] = 'm';
				computer_stats.total_misses += 1;
				printf("Computer total misses changed to: %d\n", computer_stats.total_misses);
			}
			else
			{
				printf("\n");
				printf("Computer hit at (%d, %d)!\n", target_row, target_column);
				fprintf(output_log, " \"hit\"");
				player_one_array[target_row][target_column] = '*';
				computer_stats.total_hits += 1;
				printf("Computer total hits changed to: %d\n", computer_stats.total_hits);
			}
			
			computer_stats.hits_to_misses_ratio_percentage = ((double)computer_stats.total_hits / computer_stats.total_misses) * 100;
			printf("Computer's hits-to-misses ratio (expressed as a percentage) changed to: %.2lf percent!\n", computer_stats.hits_to_misses_ratio_percentage);
			
			if (p1_carrier_gone(player_one_array, MAX_ROWS, MAX_COLS) && !p1_carrier_checked)
			{
				fprintf(output_log, " Sunk Carrier!");
				p1_carrier_checked = 1;
			}

			if (p1_battleship_gone(player_one_array, MAX_ROWS, MAX_COLS) && !p1_battleship_checked)
			{
				fprintf(output_log, " Sunk Battleship!");
				p1_battleship_checked = 1;
			}

			if (p1_cruiser_gone(player_one_array, MAX_ROWS, MAX_COLS) && !p1_cruiser_checked)
			{
				fprintf(output_log, " Sunk Cruiser!");
				p1_cruiser_checked = 1;
			}

			if (p1_submarine_gone(player_one_array, MAX_ROWS, MAX_COLS) && !p1_submarine_checked)
			{
				fprintf(output_log, " Sunk Submarine!");
				p1_submarine_checked = 1;
			}

			if (p1_destroyer_gone(player_one_array, MAX_ROWS, MAX_COLS) && !p1_destroyer_checked)
			{
				fprintf(output_log, " Sunk Destroyer!");
				p1_destroyer_checked = 1;
			}
			
			printf("\n");
			printf("Here's what your board now looks like:\n");
			printf("\n");

			print_board(player_one_array, MAX_ROWS, MAX_COLS, 1);

			system("pause");

			current_player = 1;
		}

		if (p1_carrier_gone(player_one_array, MAX_ROWS, MAX_COLS) && p1_battleship_gone(player_one_array, MAX_ROWS, MAX_COLS) && p1_cruiser_gone(player_one_array, MAX_ROWS, MAX_COLS) && p1_submarine_gone(player_one_array, MAX_ROWS, MAX_COLS) && p1_destroyer_gone(player_one_array, MAX_ROWS, MAX_COLS))
		{
			all_p1_ships_hit = 1;
		}

		if (p2_carrier_gone(player_two_array, MAX_ROWS, MAX_COLS) && p2_battleship_gone(player_two_array, MAX_ROWS, MAX_COLS) && p2_cruiser_gone(player_two_array, MAX_ROWS, MAX_COLS) && p2_submarine_gone(player_two_array, MAX_ROWS, MAX_COLS) && p2_destroyer_gone(player_two_array, MAX_ROWS, MAX_COLS))
		{
			all_p2_ships_hit = 1;
		}
	}

	printf("And that's a wrap!\n");

	if (all_p1_ships_hit)
	{
		player_one_stats.won_game = 0;
		computer_stats.won_game = 1;
		printf("\n");
		printf("Computer wins the game!\n");
	}
	else if (all_p2_ships_hit)
	{
		player_one_stats.won_game = 1;
		computer_stats.won_game = 0;
		printf("\n");
		printf("You win the game!! :D\n");
	}

	write_stats_to_log(output_log, player_one_stats, computer_stats);
	
	printf("\n");
	printf("That was fun! Ready to return to the main menu?\n");
	system("pause");
}

// Preconditions: 2D array stores character values; user only enters integer values
// Controls the process of deciding whether the player wants to manually or randomly place their ships
void set_up_player_one_ships(char* player_one_array, PlayerOneShips player_one_ships_collection)
{
	int user_choice = 0;
	do
	{
		printf("\n");
		printf("Would you like to manually place your ships on the board, or\n");
		printf("place your ships randomly? 1 means manually, 2 means randomly :D\n");
		scanf("%d", &user_choice);
	} while (user_choice < 1 || user_choice > 2);

	if (user_choice == 1)
	{
		printf("Let's place your ships manually!\n");
		manually_place_ships_on_board(player_one_array, player_one_ships_collection);
	}
	else
	{
		printf("Let's place your ships randomly!\n");
		randomly_place_player_one_ships_on_board(player_one_array, player_one_ships_collection);
	}
}

// Preconditions: 2D array stores character values
// Controls the process of randomly placing each of 5 ships on the second player's board
void randomly_place_player_two_ships_on_board(char player_two_array[][MAX_COLS], PlayerTwoShips player_two_ships_collection)
{
	int ship_count = 0, placement_direction = 0, properly_placed = 0,
		rows_and_cols[2][10] = { {0} }, user_input_values[10] = { 0 },
		row = 0, column = 0, direction = 0, working_cells_count = 0,
		all_cells_work = 0, starting_row = 0, starting_column = 0;
	PlayerTwoSpecificShip current_ship = { 0 };

	printf("\n");
	printf("Generating random positions for computer's board...\n");
	printf("\n");
	system("pause");

	while (ship_count < 5)
	{
		switch (ship_count)
		{
		case 0:
			current_ship = player_two_ships_collection.p2_carrier;
			current_ship.size = 5;
			current_ship.letter_represent = 'c';
			current_ship.sunk = 0;
			printf("\n");
			printf("Placing Carrier!\n");
			break;
		case 1:
			current_ship = player_two_ships_collection.p2_battleship;
			current_ship.size = 4;
			current_ship.letter_represent = 'b';
			current_ship.sunk = 0;
			printf("\n");
			printf("Placing Battleship!\n");
			break;
		case 2:
			current_ship = player_two_ships_collection.p2_cruiser;
			current_ship.size = 3;
			current_ship.letter_represent = 'r';
			current_ship.sunk = 0;
			printf("\n");
			printf("Placing Cruiser!\n");
			break;
		case 3:
			current_ship = player_two_ships_collection.p2_submarine;
			current_ship.size = 3;
			current_ship.letter_represent = 's';
			current_ship.sunk = 0;
			printf("\n");
			printf("Placing Submarine!\n");
			break;
		case 4:
			current_ship = player_two_ships_collection.p2_destroyer;
			current_ship.size = 2;
			current_ship.letter_represent = 'd';
			current_ship.sunk = 0;
			printf("\n");
			printf("Placing Destroyer!\n");
			break;
		}

		working_cells_count = 0;
		all_cells_work = 0;

		direction = gen_dir();
		//direction = 1; // test code! 
					   // --> When I set direction to zero (horizontal only), there were no issues with collision!

		/*printf("\n");
		printf("Direction: %d\n", direction);*/

		if (direction == 0) // horizontal; going to the right!
		{
			//printf("Confirmation: direction is zero!\n");
			do
			{
				gen_start_pt(current_ship.size, direction, &starting_row, &starting_column);
				/*printf("Starting row: %d\n", starting_row);
				printf("Starting column: %d\n", starting_column);
				printf("\n");*/

				row = starting_row;
				column = starting_column;

				working_cells_count = 0;
				//column = starting_column;

				for (int current_cell = 0; current_cell < current_ship.size; current_cell++)
				{
					if (player_two_array[row][column] == '~')
					{
						working_cells_count++;
					}
					column++;
				}

				if (working_cells_count == current_ship.size)
				{
					all_cells_work = 1;
				}
			} while (!all_cells_work);

			row = starting_row;
			column = starting_column;

			for (int current_cell = 0; current_cell < current_ship.size; current_cell++)
			{
				player_two_array[row][column] = current_ship.letter_represent;
				column++;
			}

		}
		else // 1; vertical; going down!
		{
			//printf("Confirmation: direction is one!\n");
			do
			{
				gen_start_pt(current_ship.size, direction, &starting_row, &starting_column);
				/*printf("Starting row: %d\n", starting_row);
				printf("Starting column: %d\n", starting_column);
				printf("\n");*/

				row = starting_row;
				column = starting_column;

				working_cells_count = 0;
				//row = starting_row;

				for (int current_cell = 0; current_cell < current_ship.size; current_cell++)
				{
					if (player_two_array[row][column] == '~')
					{
						working_cells_count++;
					}
					row++;
				}

				if (working_cells_count == current_ship.size)
				{
					all_cells_work = 1;
				}
			} while (!all_cells_work);

			row = starting_row;
			column = starting_column;

			for (int current_cell = 0; current_cell < current_ship.size; current_cell++)
			{
				player_two_array[row][column] = current_ship.letter_represent;
				row++;
			}
		}
		ship_count++;
	}
	printf("\n");
	printf("Computer's board is ready!\n");
	//print_board(player_two_array, MAX_ROWS, MAX_COLS, 2);
}

// Preconditions: 2D array stores character values; user only enters integer values
// Controls the process of randomly placing each of 5 ships on the first player's board
void randomly_place_player_one_ships_on_board(char player_one_array[][MAX_COLS], PlayerOneShips player_one_ships_collection)
{
	int ship_count = 0, placement_direction = 0, properly_placed = 0,
		rows_and_cols[2][10] = { {0} }, user_input_values[10] = { 0 },
		row = 0, column = 0, direction = 0, working_cells_count = 0,
		all_cells_work = 0, starting_row = 0, starting_column = 0;
	PlayerOneSpecificShip current_ship = { 0 };

	printf("\n");
	printf("Generating random positions...\n");
	printf("\n");
	system("pause");
	
	while (ship_count < 5)
	{
		switch (ship_count)
		{
		case 0:
			current_ship = player_one_ships_collection.p1_carrier;
			current_ship.size = 5;
			current_ship.letter_represent = 'c';
			current_ship.sunk = 0;
			printf("\n");
			printf("Placing Carrier!\n");
			break;
		case 1:
			current_ship = player_one_ships_collection.p1_battleship;
			current_ship.size = 4;
			current_ship.letter_represent = 'b';
			current_ship.sunk = 0;
			printf("\n");
			printf("Placing Battleship!\n");
			break;
		case 2:
			current_ship = player_one_ships_collection.p1_cruiser;
			current_ship.size = 3;
			current_ship.letter_represent = 'r';
			current_ship.sunk = 0;
			printf("\n");
			printf("Placing Cruiser!\n");
			break;
		case 3:
			current_ship = player_one_ships_collection.p1_submarine;
			current_ship.size = 3;
			current_ship.letter_represent = 's';
			current_ship.sunk = 0;
			printf("\n");
			printf("Placing Submarine!\n");
			break;
		case 4:
			current_ship = player_one_ships_collection.p1_destroyer;
			current_ship.size = 2;
			current_ship.letter_represent = 'd';
			current_ship.sunk = 0;
			printf("\n");
			printf("Placing Destroyer!\n");
			break;
		}

		working_cells_count = 0;
		all_cells_work = 0;
		
		direction = gen_dir();
		//direction = 1; // test code! 
					   // --> When I set direction to zero (horizontal only), there were no issues with collision!
		
		printf("\n");
		printf("Direction: %d\n", direction);

		if (direction == 0) // horizontal; going to the right!
		{
			//printf("Confirmation: direction is zero!\n");
			do
			{
				gen_start_pt(current_ship.size, direction, &starting_row, &starting_column);
				printf("Starting row: %d\n", starting_row);
				printf("Starting column: %d\n", starting_column);
				printf("\n");

				row = starting_row;
				column = starting_column;

				working_cells_count = 0;
				//column = starting_column;

				for (int current_cell = 0; current_cell < current_ship.size; current_cell++)
				{
					if (player_one_array[row][column] == '~')
					{
						working_cells_count++;
					}
					column++;
				}

				if (working_cells_count == current_ship.size) // MOST RECENT FIX: account for one extra value added to working cells count during for-loop's last iteration!
				{
					all_cells_work = 1;
				}
			} while (!all_cells_work);
			
			row = starting_row;
			column = starting_column;

			for (int current_cell = 0; current_cell < current_ship.size; current_cell++)
			{
				player_one_array[row][column] = current_ship.letter_represent;
				column++;
			}

		}
		else // 1; vertical; going down!
		{
			//printf("Confirmation: direction is one!\n");
			do
			{
				gen_start_pt(current_ship.size, direction, &starting_row, &starting_column);
				printf("Starting row: %d\n", starting_row);
				printf("Starting column: %d\n", starting_column);
				printf("\n");

				row = starting_row;
				column = starting_column;
				
				working_cells_count = 0;
				//row = starting_row;

				for (int current_cell = 0; current_cell < current_ship.size; current_cell++)
				{
					if (player_one_array[row][column] == '~')
					{
						working_cells_count++;
					}
					row++;
				}

				if (working_cells_count == current_ship.size)
				{
					all_cells_work = 1;
				}
			} while (!all_cells_work);
			
			row = starting_row;
			column = starting_column;

			for (int current_cell = 0; current_cell < current_ship.size; current_cell++)
			{
				player_one_array[row][column] = current_ship.letter_represent;
				row++;
			}
		}

		printf("\n");
		printf("Here's your next ship on the board:\n");
		printf("\n");
		print_board(player_one_array, MAX_ROWS, MAX_COLS, 1);
		ship_count++;
	}
	system("pause");
}

// Preconditions: 2D array stores character values; user only enters integer values
// Controls the process of manually placing each of 5 ships on the player's board
void manually_place_ships_on_board(char player_one_array[][MAX_COLS], PlayerOneShips player_one_ships_collection)
{
	int ship_count = 0, current_row = 0, current_column = 0,
		placement_direction = 0, properly_placed = 0,
		rows_and_cols[2][10] = { {0} }, user_input_values[10] = { 0 }, 
		proper_values = 0, free_cells = 0, rows_in_order = 0,
		repeat_current_ship = 0, columns_in_order = 0, staying_in_same_row = 0,
		staying_in_same_column = 0, ship_in_a_row = 0, ship_in_a_column = 0;
	PlayerOneSpecificShip current_ship = { 0 }, input_values[10] = { 0 };
	char enteredCoordinates[10] = { '\0' }, previous_cell_values[10] = { '\0'};

	printf("\n");
	printf("Your board currently looks like this:\n");
	printf("\n");
	print_board(player_one_array, MAX_ROWS, MAX_COLS, 1);


	//// Update user instructions later! :D
	//printf("\n");
	//printf("You'll now be asked to place your ships in the following order:\n");
	//printf("(1)Carrier (2)Battleship (3)Cruiser (4)Submarine (5)Destroyer\n");
	//printf("For each of the five ships, pick the top-left corner of your ship,\n");
	//printf("then choose whether to place it downwards or to the right.\n");
	//printf("If your ship goes outside the bounds of your 10x10 grid, and/or\n");
	//printf("your ship overlaps with ships you've already placed, you'll be\n");
	//printf("asked to place that ship again :)\n");
	
	while (ship_count < 5)
	{
		printf("Ship count: %d\n", ship_count);

		proper_values = 0;
		printf("\n");

		switch (ship_count)
		{
		case 0:
			current_ship = player_one_ships_collection.p1_carrier;
			current_ship.size = 5;
			current_ship.letter_represent = 'c';
			current_ship.sunk = 0;
			printf("\n");
			printf("Let's place your Carrier!\n");
			break;
		case 1:
			current_ship = player_one_ships_collection.p1_battleship;
			current_ship.size = 4;
			current_ship.letter_represent = 'b';
			current_ship.sunk = 0;
			printf("\n");
			printf("Let's place your Battleship!\n");
			break;
		case 2:
			current_ship = player_one_ships_collection.p1_cruiser;
			current_ship.size = 3;
			current_ship.letter_represent = 'r';
			current_ship.sunk = 0;
			printf("\n");
			printf("Let's place your Cruiser!\n");
			break;
		case 3:
			current_ship = player_one_ships_collection.p1_submarine;
			current_ship.size = 3;
			current_ship.letter_represent = 's';
			current_ship.sunk = 0;
			printf("\n");
			printf("Let's place your Submarine!\n");
			break;
		case 4:
			current_ship = player_one_ships_collection.p1_destroyer;
			current_ship.size = 2;
			current_ship.letter_represent = 'd';
			current_ship.sunk = 0;
			printf("\n");
			printf("Let's place your Destroyer!\n");
			break;
		}
		
		repeat_current_ship = 1;
		do
		{
			proper_values = 0;
			free_cells = 0;
			rows_in_order = 0;
			columns_in_order = 0;
			staying_in_same_row = 0;
			staying_in_same_column = 0;
			ship_in_a_row = 0;
			ship_in_a_column = 0;

			printf("Ship count: %d\n", ship_count);
			printf("\n");
			printf("Please enter %d numbers one after another, separated by spaces (%d pairs of values,\n", current_ship.size * 2, current_ship.size);
			printf("where each pair represents one cell: a row number followed by a column number).\n");
			printf("Enter all %d numbers, then press enter when you're done.\n", current_ship.size * 2);
			printf("\n");
			printf("If you enter a value outside the range of 0-9 for row or column,\n");
			printf("values that are occupied by other ships, or values that don't go in order\n");
			printf("either horizontally or vertically, you'll be asked to enter your list of coordinates again :)\n");

			switch (current_ship.size)
			{
			case 5:
				scanf("%d %d %d %d %d %d %d %d %d %d", &user_input_values[0], &user_input_values[1], &user_input_values[2], &user_input_values[3], &user_input_values[4], &user_input_values[5], &user_input_values[6], &user_input_values[7], &user_input_values[8], &user_input_values[9]);
				break;
			case 4:
				scanf("%d %d %d %d %d %d %d %d", &user_input_values[0], &user_input_values[1], &user_input_values[2], &user_input_values[3], &user_input_values[4], &user_input_values[5], &user_input_values[6], &user_input_values[7]);
				break;
			case 3:
				scanf("%d %d %d %d %d %d", &user_input_values[0], &user_input_values[1], &user_input_values[2], &user_input_values[3], &user_input_values[4], &user_input_values[5]);
				break;
			case 2:
				scanf("%d %d %d %d", &user_input_values[0], &user_input_values[1], &user_input_values[2], &user_input_values[3]);
				break;
			}

			//// Display the user's entered values back to them!
			//printf("Values that will be used for your current ship:\n");
			//for (int i = 0; i < current_ship.size * 2; i++)
			//{
			//	printf("%d", user_input_values[i]);
			//}
			//printf("\n");

			// Check that every value entered by the user is within 0-9 range!

			int correct_value_count = 0;
			proper_values = 0;

			for (int row_input_count = 0; row_input_count < current_ship.size * 2; row_input_count += 2)
			{
				previous_cell_values[row_input_count] = '\0';
			}

			for (int i = 0; i < current_ship.size * 2; i++)
			{
				if (user_input_values[i] < 0 || user_input_values[i] > MAX_ROWS - 1)
				{
					printf("%d as input #%d does not work!\n", user_input_values[i], i + 1);
				}
				else
				{
					printf("%d as input #%d works!\n", user_input_values[i], i + 1);
					correct_value_count++;
				}
			}
			if (correct_value_count == current_ship.size * 2)
			{
				proper_values = 1;
			}
			else
			{
				continue;
			}

			system("pause");

			int correct_cells = 0, free_cells = 0;


			for (int row_input_count = 0; row_input_count < current_ship.size * 2; row_input_count += 2)
			{
				printf("\n");
				printf("Row in question: %d\n", user_input_values[row_input_count]);
				printf("Column in question: %d\n", user_input_values[row_input_count + 1]);
				printf("\n");

				if (player_one_array[user_input_values[row_input_count]][user_input_values[row_input_count + 1]] != '~')
				{
					//previous_cell_values[row_input_count] = player_one_array[user_input_values[row_input_count]][user_input_values[row_input_count + 1]];
					printf("Cell at row %d and column %d already taken!\n", user_input_values[row_input_count], user_input_values[row_input_count + 1]);
				}
				else
				{
					printf("We might place part of ship at row %d and column %d!\n", user_input_values[row_input_count], user_input_values[row_input_count + 1]);

					previous_cell_values[row_input_count] = player_one_array[user_input_values[row_input_count]][user_input_values[row_input_count + 1]];
					player_one_array[user_input_values[row_input_count]][user_input_values[row_input_count + 1]] = current_ship.letter_represent;

					correct_cells++;
				}
			}

			printf("\n");
			printf("Previous values array:\n");
			printf("\n");

			for (int row_input_count = 0; row_input_count < current_ship.size * 2; row_input_count += 2)
			{
				printf("%c", previous_cell_values[row_input_count]);
			}
			printf("\n");

			if (correct_cells == current_ship.size)
			{
				free_cells = 1;
			}

			int entered_rows[5] = { 0 };
			int entered_row_index = 0;
			for (int row_input_count = 0; row_input_count < current_ship.size * 2; row_input_count += 2)
			{
				entered_rows[entered_row_index] = user_input_values[row_input_count];
				entered_row_index++;
			}

			int row_difference_counter = 0;
			int correct_row_difference_count = 0;
			int same_row_difference_count = 0;

			for (int current_row_consideration = 0; current_row_consideration < current_ship.size - 1; current_row_consideration++)
			{
				row_difference_counter = entered_rows[current_row_consideration + 1] - entered_rows[current_row_consideration];
				
				if (row_difference_counter == 1)
				{
					correct_row_difference_count++;
				}
				else if (row_difference_counter == 0)
				{
					same_row_difference_count++;
				}
			}

			/*printf("\n");
			printf("Correct number of row differences: %d\n", correct_row_difference_count);
			printf("\n");*/
			
			if (correct_row_difference_count == current_ship.size - 1)
			{
				rows_in_order = 1;
			}

			if (same_row_difference_count == current_ship.size - 1)
			{
				staying_in_same_row = 1;
			}

			int entered_columns[5] = { 0 };
			int entered_column_index = 0;
			for (int column_input_count = 1; column_input_count < current_ship.size * 2; column_input_count += 2)
			{
				entered_columns[entered_column_index] = user_input_values[column_input_count];
				entered_column_index++;
			}

			/*printf("Entered columns:\n");
			for (int i = 0; i < current_ship.size; i++)
			{
				printf("%d ", entered_columns[i]);
			}
			printf("\n");*/

			int column_difference_counter = 0;
			int correct_column_difference_count = 0;
			int same_column_difference_count = 0;

			for (int current_column_consideration = 0; current_column_consideration < current_ship.size - 1; current_column_consideration++)
			{
				printf("\n");
				printf("Right column: %d\n", entered_columns[current_column_consideration + 1]);
				printf("Left column: %d\n", entered_columns[current_column_consideration]);
				printf("\n");
				
				column_difference_counter = entered_columns[current_column_consideration + 1] - entered_columns[current_column_consideration];
				
				printf("\n");
				printf("Difference between current two columns: %d\n", column_difference_counter);
				printf("\n");
				
				if (column_difference_counter == 1)
				{
					correct_column_difference_count++;
				}
				else if (column_difference_counter == 0)
				{
					same_column_difference_count++;
				}
			}

			

			if (correct_column_difference_count == current_ship.size - 1)
			{
				columns_in_order = 1;
			}

			if (same_column_difference_count == current_ship.size - 1)
			{
				staying_in_same_column = 1;
			}

			if (staying_in_same_row && columns_in_order)
			{
				ship_in_a_row = 1;
			}

			if (staying_in_same_column && rows_in_order)
			{
				ship_in_a_column = 1;
			}
			
			printf("Proper values: %d\n", proper_values);
			printf("Free cells: %d\n", free_cells);
			printf("Rows in order: %d\n", rows_in_order);
			printf("Columns in order: %d\n", columns_in_order);
			printf("Staying in same row: %d\n", staying_in_same_row);
			printf("Staying in same column: %d\n", staying_in_same_column);
			printf("Ship in a row: %d\n", ship_in_a_row);
			printf("Ship in a column: %d\n", ship_in_a_column);

			if (!proper_values || !free_cells || (!ship_in_a_row && !ship_in_a_column))
			{
				for (int row_input_count = 0; row_input_count < current_ship.size * 2; row_input_count += 2)
				{
					if (previous_cell_values[row_input_count] != '\0')
					{
						player_one_array[user_input_values[row_input_count]][user_input_values[row_input_count + 1]] = previous_cell_values[row_input_count];
						//previous_cell_values = { '\0' };
					}
				}
			}
			
			printf("\n");
			printf("Your board currently looks like this:\n");
			printf("\n");
			print_board(player_one_array, MAX_ROWS, MAX_COLS, 1);

			printf("Staying with current ship: %d\n", !proper_values || !free_cells || (!ship_in_a_row && !ship_in_a_column));

			if (proper_values && free_cells && (ship_in_a_row || ship_in_a_column))
			{
				printf("Ready to move on to next ship!\n");
				repeat_current_ship = 0;
			}

		} while (repeat_current_ship);
		printf("Exited the do-while loop!\n");
		// ------------------------
		// test code! :) :D
		system("pause");
		ship_count++;
		//continue;

		//// ------------------------
		//
		//for (int i = 0; i < current_ship.size * 2; i++)
		//{
		//	if (i % 1 == 0) // Odd iteration; entering next cell's row!
		//	{
		//		// Add do-while loop to check proper row later! :D
		//		// Assuming user entered 0-9 for now :)
		//		scanf("%d", current_row);
		//		
		//		// Add do-while loop to check if user entered proper input 
		//	}
		//	else // Even iteration; entering next cell's column!
		//	{
		//		// Add do-while loop to check proper column later! :D
		//		// Assuming user entered 0-9 for now :)
		//		scanf("%d", current_column);
		//	}
		//	
		//}
		//
		//// Idea!
		//scanf("%d%d%d%d%d%d%d%d%d%d", &input_values[0], &input_values[1], &input_values[2], &input_values[3], &input_values[4], &input_values[5], &input_values[6], &input_values[7], &input_values[8], &input_values[9]);

		//// Idea!
		//// Loop through each value in the input_values 1D array to confirm that each value is within the 0-9 range (otherwise, ask user to enter new values)!






		////// Note: Implement do-while loop for repeated user prompting later! :D
		////printf("\n");
		////printf("In what column? ");
		////scanf("%d", &column_choice);

		////// Note: Implement do-while loop for repeated user prompting later! :D
		////printf("\n");
		////printf("Would you like to place your ship downwards or to the right?\n");
		////printf("1 means down; 2 means right!\n");
		////scanf("%d", &placement_direction);

		//do
		//{

		//} while (!properly_placed);

		//ship_count++;
	}
}

//int check_proper_ship_placement(char player_one_array[][MAX_COLS], int num_rows, int num_cols, int row_choice, int column_choice, int ship_size)
//{
//	int row_index = 0, col_index = 0;
//
//	for(; row_index < num_rows; ++row_index)
//	{
//		for (; col_index < num_cols; )
//	}
//
//	int col = 0;
//}

// Preconditions: None
// Generates random direction as 0 (horizontal) or 1 (vertical) for placing a ship on a 2D grid
int gen_dir(void)
{
	return rand() % 2; // 0 - horizontal, 1 - vertical
}

// Preconditions: ship length is greater than zero; direction is 0 or 1; all parameters
// are of integer data type
// Generates random starting point with row and column for placing a ship on a 2D grid
void gen_start_pt(int ship_len, int dir, int* start_row, int* start_col)
{
	if (dir == 0) // horizontal - we'll place ships from point generated and to the right only
	{
		*start_row = rand() % MAX_ROWS;
		*start_col = rand() % (MAX_COLS - ship_len + 1);
	}
	else // vertical - we'll place ships from point generated and down only
	{
		*start_row = rand() % (MAX_ROWS - ship_len + 1);
		*start_col = rand() % MAX_COLS;
	}
}