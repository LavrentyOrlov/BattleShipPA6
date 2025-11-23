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

int main(void)
{
	int player_to_start = 0;
	
	srand(time(NULL));
	
	char p1_board[MAX_ROWS][MAX_COLS] = { {'\0'} },
		comp_board[MAX_ROWS][MAX_COLS] = { {'\0'} };

	FILE* output_log = fopen("battleship.log", "w");

	PlayerOneShips p1_ships_collection = { {0, 0, '\0', 0}, {0, 0, '\0', 0}, {0, 0, '\0', 0}, {0, 0, '\0', 0}, {0, 0, '\0', 0} };;
	PlayerTwoShips p2_ships_collection = { {0, 0, '\0', 0}, {0, 0, '\0', 0}, {0, 0, '\0', 0}, {0, 0, '\0', 0}, {0, 0, '\0', 0} };;

	Stats player_one_stats = { 0, 0, 0, 0.0, 0 };
	Stats computer_stats = { 0, 0, 0, 0.0, 0 };

	// size direction letter_reprsent sunk

	welcome_screen();

	init_board(p1_board, MAX_ROWS, MAX_COLS); // initialize the board with all water symbols
	init_board(comp_board, MAX_ROWS, MAX_COLS);

	print_board(p1_board, MAX_ROWS, MAX_COLS, 1);
	print_board(comp_board, MAX_ROWS, MAX_COLS, 2); // this will hide the ship symbols

	set_up_player_one_ships(p1_board, p1_ships_collection);
	
	randomly_place_player_two_ships_on_board(comp_board, p2_ships_collection);
	
	printf("\n");
	printf("Woo hoo, it's time to start the game! Generating random player to start...\n");
	printf("\n");
	system("pause");

	player_to_start = random_player_start();
	
	// test code!
	// player_to_start = 1;

	//rintf("Our random starting player is: %d\n", player_to_start);

	printf("\n");
	if (player_to_start == 1)
	{
		printf("You start the game!\n");
	}
	else
	{
		printf("The computer starts the game!\n");
	}

	printf("\n");
	printf("Here's your board:\n");
	printf("\n");
	print_board(p1_board, MAX_ROWS, MAX_COLS, 1);

	printf("\n");
	printf("Here's the computer's board (ships hidden from view):\n");
	printf("\n");
	print_board(comp_board, MAX_ROWS, MAX_COLS, 2);

	game_play(player_to_start, p1_board, p1_ships_collection, comp_board, p2_ships_collection, player_one_stats, computer_stats, output_log);

	fclose(output_log);

	return 0;
}