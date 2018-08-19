/**************************************************************************************************
** Author: Jose Garay
** Date: 8/11/2018
** Description: The interface file for the GBoard Class. Simulates the board game of tic tac toe 
that is 15 by 15 spaces large. Players can make moves using the makeMove function and check the 
game status using the getGameState function. 
**************************************************************************************************/

#ifndef GBOARD_HPP
#define GBOARD_HPP

enum gameState {X_WON, O_WON, DRAW, UNFINISHED};

class GBoard
{
private:
	char board[15][15];
	gameState stateOfGame;
	bool isWinnerWinnerChickenDinner(char);
	bool isDraw();
public:
	GBoard();
	gameState getGameState();
	bool makeMove(int, int, char);

};
#endif