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

#ifndef PA6HELP_H
#define PA6HELP_H

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//typedef struct player_one_carrier
//{
//	int size;
//	int direction;
//	char letter_represent;
//	int sunk;
//	int position_coordiates[5];
//
//} PlayerOneCarrier;
//
//typedef struct player_one_battleship
//{
//	int size;
//	int direction;
//	char letter_represent;
//	int sunk;
//	int position_coordiates[4];
//
//} PlayerOneBattleship;
//
//typedef struct player_one_cruiser
//{
//	int size;
//	int direction;
//	char letter_represent;
//	int sunk;
//	int position_coordiates[3];
//
//} PlayerOneCruiser;
//
//typedef struct player_one_submarine
//{
//	int size;
//	int direction;
//	char letter_represent;
//	int sunk;
//	int position_coordiates[3];
//
//} PlayerOneSubmarine;
//
//typedef struct player_one_destroyer
//{
//	int size;
//	int direction;
//	char letter_represent;
//	int sunk;
//	int position_coordiates[2];
//
//} PlayerOneDestroyer;
//
//typedef struct player_two_carrier
//{
//	int size;
//	int direction;
//	char letter_represent;
//	int sunk;
//	int position_coordiates[5];
//
//} PlayerTwoCarrier;
//
//typedef struct player_two_battleship
//{
//	int size;
//	int direction;
//	char letter_represent;
//	int sunk;
//	int position_coordiates[4];
//
//} PlayerTwoBattleship;
//
//typedef struct player_two_cruiser
//{
//	int size;
//	int direction;
//	char letter_represent;
//	int sunk;
//	int position_coordiates[3];
//
//} PlayerTwoCruiser;
//
//typedef struct player_two_submarine
//{
//	int size;
//	int direction;
//	char letter_represent;
//	int sunk;
//	int position_coordiates[3];
//
//} PlayerTwoSubmarine;
//
//typedef struct player_two_destroyer
//{
//	int size;
//	int direction;
//	char letter_represent;
//	int sunk;
//	int position_coordiates[2];

//} PlayerTwoDestroyer;

typedef struct player_one_specific_ship
{
	int size;
	int direction;
	char letter_represent;
	int sunk;
} PlayerOneSpecificShip;

typedef struct player_two_specific_ship
{
	int size;
	int direction;
	char letter_represent;
	int sunk;
} PlayerTwoSpecificShip;

//typedef struct player_one_ships
//{
//	PlayerOneCarrier p1_carrier;
//	PlayerOneBattleship p1_battleship;
//	PlayerOneCruiser p1_cruiser;
//	PlayerOneSubmarine p1_submarine;
//	PlayerOneDestroyer p1_destroyer;
//
//} PlayerOneShips;
//
//typedef struct player_two_ships
//{
//	PlayerOneCarrier p2_carrier;
//	PlayerOneBattleship p2_battleship;
//	PlayerOneCruiser p2_cruiser;
//	PlayerOneSubmarine p2_submarine;
//	PlayerOneDestroyer p2_destroyer;
//
//} PlayerTwoShips;

typedef struct player_one_ships
{
	PlayerOneSpecificShip p1_carrier;
	PlayerOneSpecificShip p1_battleship;
	PlayerOneSpecificShip p1_cruiser;
	PlayerOneSpecificShip p1_submarine;
	PlayerOneSpecificShip p1_destroyer;

} PlayerOneShips;

typedef struct player_two_ships
{
	PlayerTwoSpecificShip p2_carrier;
	PlayerTwoSpecificShip p2_battleship;
	PlayerTwoSpecificShip p2_cruiser;
	PlayerTwoSpecificShip p2_submarine;
	PlayerTwoSpecificShip p2_destroyer;

} PlayerTwoShips;

typedef struct stats
{
	int total_hits;
	int total_misses;
	int total_shots;
	double hits_to_misses_ratio_percentage;
	int won_game;
} Stats;

#define MAX_ROWS 10
#define MAX_COLS 10

#define NUMBER_OF_PLAYERS 2

// Preconditions: Board contains char values, with integers passed in
// for rows and columns
// Sets all values in a 2D board to the default '~' value
void init_board(char board[][MAX_COLS], int num_rows, int num_cols);

// Preconditions: Board contains char values, with integers passed in
// for rows, columns, and player
// Prints 2D board for the current player to the console screen
void print_board(char board[][MAX_COLS], int num_rows, int num_cols, int player);

// Preconditions: 2D array stores character values; user only enters integer values
// Controls the process of deciding whether the player wants to manually or randomly place their ships
void set_up_player_one_ships(char* player_one_array, PlayerOneShips player_one_ships_collection);

// Preconditions: 2D array stores character values; user only enters integer values
// Controls the process of manually placing each of 5 ships on the player's board
void manually_place_ships_on_board(char player_one_array[][MAX_COLS], PlayerOneShips player_one_ships_collection);

// Preconditions: 2D array stores character values; user only enters integer values
// Controls the process of randomly placing each of 5 ships on the first player's board
void randomly_place_player_one_ships_on_board(char player_one_array[][MAX_COLS], PlayerOneShips player_one_ships_collection);

// Preconditions: 2D array stores character values
// Controls the process of randomly placing each of 5 ships on the second player's board
void randomly_place_player_two_ships_on_board(char player_two_array[][MAX_COLS], PlayerTwoShips player_two_ships_collection);

// Preconditions: ship length is greater than zero; direction is 0 or 1; all parameters
// are of integer data type
// Generates random starting point with row and column for placing a ship on a 2D grid
void gen_start_pt(int ship_len, int dir, int* start_row, int* start_col);

// Preconditions: None
// Generates random direction as 0 (horizontal) or 1 (vertical) for placing a ship on a 2D grid
int gen_dir(void);

// Preconditions: player to start is zero or one; player one and player two arrays store characters;
// output log file is already open
// Controls the process for running the gameflow of the battleship game including back-and-forth actions
// between players, determining when one of the players won, and adding results to a log output file
void game_play(int player_to_start, char player_one_array[][MAX_COLS], PlayerOneShips player_one_ships_collection,
			   char player_two_array[][MAX_COLS], PlayerTwoShips player_two_ships_collection, Stats player_one_stats,
			   Stats computer_stats, FILE *output_log);

// Preconditions: output file is open
// Prints statistics for players to an output stream file after the game is over
void write_stats_to_log(FILE *output_log, Stats player_one_stats, Stats computer_stats);

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player one's carrier has been hit
int p1_carrier_gone(char p1_board[][MAX_COLS], int num_rows, int num_cols);

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player one's battleship has been hit
int p1_battleship_gone(char p1_board[][MAX_COLS], int num_rows, int num_cols);

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player one's cruiser has been hit
int p1_cruiser_gone(char p1_board[][MAX_COLS], int num_rows, int num_cols);

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player one's submarine has been hit
int p1_submarine_gone(char p1_board[][MAX_COLS], int num_rows, int num_cols);

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player one's destroyer has been hit
int p1_destroyer_gone(char p1_board[][MAX_COLS], int num_rows, int num_cols);

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player two's carrier has been hit
int p2_carrier_gone(char p2_board[][MAX_COLS], int num_rows, int num_cols);

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player two's battleship has been hit
int p2_battleship_gone(char p2_board[][MAX_COLS], int num_rows, int num_cols);

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player two's cruiser has been hit
int p2_cruiser_gone(char p2_board[][MAX_COLS], int num_rows, int num_cols);

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player two's submarine has been hit
int p2_submarine_gone(char p2_board[][MAX_COLS], int num_rows, int num_cols);

// Preconditions: player's board stores characters; rows and columns are
// integers greater than 0
// Checks whether each cell occupied by player two's destroyer has been hit
int p2_destroyer_gone(char p2_board[][MAX_COLS], int num_rows, int num_cols);

// Preconditions: none
// Prints a welcome screen and instructions for the Battleship game to the console screen
void welcome_screen(void);

#endif