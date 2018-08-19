/**************************************************************************************************
** Author: Jose Garay
** Date: 8/11/2018
** Description: Implementation file for the GBoard Class. The GBoard Class simulates a game board
of tic tac toe on a board that is 15 by 15 spaces large. Players can place either an x or o in 
spaces on the board. If five in a row are placed diagonally or in a straight line, then they are
the winner. 
**************************************************************************************************/

#include "GBoard.hpp"

/**************************************************************************************************
** Description: The constructor for the GBoard Class. Sets the board up with blank characters and 
sets the stateOftheGame to UNFINISHED. 
**************************************************************************************************/

GBoard::GBoard()
{
	stateOfGame = UNFINISHED;
	for(int n = 0; n < 15; n++)
	{
		for(int m = 0; m < 15; m++)
		{
			board[n][m] = '.';
		}
	}
}
/**************************************************************************************************
** Description: Getter function to return the status of the game.
**************************************************************************************************/


gameState GBoard::getGameState()
{
	return stateOfGame;
}

/**************************************************************************************************
** Description: Takes in two integers and a character that is the player's move and return a 
boolean representing whether a move was valid or invalid. If the player tries to overlay their 
character on an occupied space or if the game status is anything other than unfinished, then the
method returns false. If the move is valid, it is set in the array and the board is checked to
update the status of the board.
**************************************************************************************************/


bool GBoard::makeMove(int row, int col, char ticTac)
{
	if(board[row][col] == 'x' || board[row][col] == 'o'|| stateOfGame != UNFINISHED)
		return false;
	else
	{
		board[row][col] = ticTac;
		if(isWinnerWinnerChickenDinner(ticTac))
		{
			if(ticTac == 'o')
				stateOfGame = O_WON;
			else
				stateOfGame = X_WON;
		}
		else if(isDraw() && stateOfGame == UNFINISHED)
			stateOfGame = DRAW;
		return true;
	}
	
}

/**************************************************************************************************
** Description: Takes in a character as an input and returns a boolean. The board is checked
to see if the last play is a winning move and updates the stateOfGame variable to X_WON or O_WON. 
Every space is checked to see if the player's character has five in a horizontal row, vertical 
column, or in a diagonal with either a positive or negative slope. If there are five in a row, then
this method returns true, else it returns false.
**************************************************************************************************/

bool GBoard::isWinnerWinnerChickenDinner(char player)
{
	//Counter to count the number of times that this method finds the player's chracter in a row.
	//Resets if another character is in the selected position, if the the lane that it is checking
	//changes, or if the method of checking changes.

	int counter = 0;

	//Check for a winner left to right horizontal row.

	for(int row = 0; row < 15; row++)
	{
		for (int col = 0; col < 15; col++)
		{
			if(counter == 5)
				return true;
			else if(board[row][col] == player)
				counter++;
			else
				counter = 0;
		}
		if(counter == 5)
			return true;
		counter = 0;
	}

	
	//Check for a winner diagonally with a positive slope for half of the board.
	//This half of board being diagonally cut in half with the larger half containing the diagonal
	//column and the area below that.

	for( int col = 0; col <15; col++)
	{
		for(int cCol = col, row = 0; cCol < 15; cCol++, row++)
		{
			if(counter == 5)
				return true;
			else if(board[row][cCol] == player)
				counter++;
			else
				counter = 0;
		}
		if(counter == 5)
			return true;
		counter = 0;
	}

	//Check the smaller half of the board for the winning move if it is diagonal wth a positive slope.
	//The half of the board being the the top portion of the board that wasn't included in the previous portion.

	for(int row = 1; row < 15; row++)
	{
		for(int col = 0, rRow = row; rRow < 15; col++, rRow++)
		{
			if(counter == 5)
				return true;
			else if(board[rRow][col] == player)
				counter++;
			else
				counter = 0;
		}
		if(counter == 5)
			return true;
		counter = 0;
	}

	//Check for the winning move if there are five of the player's character in a column.

	for(int col = 0; col < 15; col++)
	{
		for(int row = 0; row < 15; row++)
		{
			if(counter == 5)
				return true;
			else if(board[row][col] == player)
				counter++;
			else
				counter = 0;
		}
		if(counter == 5)
			return true;
		counter == 0;
	}

	//Check half the board to see if there are five of the player's character in diagonal with a 
	//negative slope. Checks slightly more than half of the board.

	for(int col = 0; col < 15; col++)
	{
		for(int row = 14, cCol = col; cCol< 15; cCol++, row--)
		{
			if(counter == 5)
				return true;
			else if(board[row][cCol] == player)
				counter++;
			else
				counter = 0;
		}
		if(counter == 5)
			return true;
		counter = 0;
	}	

	//Check for winning move diagonally with a negative slope in the smaller half of the board.

	for(int row = 13; row >= 0; row--)
	{
		for(int col = 0, rRow = row; rRow >= 0; rRow--, col++)
		{
			if(counter == 5)
				return true;
			else if(board[rRow][col] == player)
				counter++;
			else
				counter = 0;
		}
		if(counter == 5)
			return true;
		counter = 0;	
	}

	return false;
}

/**************************************************************************************************
** Description: Method isDraw() takes no input and returns a boolean. A flag for if the match is a 
draw. Counts the number of used spots. If the board is full, the method returns true and returns
false otherwise.
**************************************************************************************************/

bool GBoard::isDraw()
{	
	//This loop counts the number of open spaces on the board. If there are no spaces left on the 
	//board then this method returns true. Otherwise it returns false.
	int drawCounter = 0;
	for(int row = 0; row < 15; row++)
	{
		for(int col = 0; col < 15; col++)
		{
			if(board[row][col] == '.')
				drawCounter++;
		}
	}
	if(drawCounter == 0)
		return true;
	else
		return false;
}
