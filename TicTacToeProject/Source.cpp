/*
TIC TAC TOE PROJECT
*/

#include <iostream>
#include <string>
using namespace std; 

const int ROWS = 3; 
const int COL = 3; 

void runGame(); 
void intializeGameBoard(string gameBoard[ROWS][COL]);
void printCurrentBoard(string gameBoard[ROWS][COL]);
void getUserInput(bool xTurn, string gameBaord[ROWS][COL]);
bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COL]);
string getWinner(string gameBoard[ROWS][COL]);
bool isBoardFull(string gameBoard[ROWS][COL]);

int main()
{
	runGame();

	return 0; 
}//end main

//THE GAME LOOP

void runGame() //*****LAUNCHES GAME*****
{
	string winner = "";
	bool xTurn = true; //start with X's turn
	int theRow = 0;
	int theCol = 0;
	string gameBoard[ROWS][COL];

	intializeGameBoard(gameBoard);

	//initial print
	printCurrentBoard(gameBoard);

	while (winner == "")
	{
		if (xTurn)
		{
			cout << "It is X's turn" << endl;
		}
		else
		{
			cout << "it is O's turn" << endl;
		}//end if-else
		getUserInput(xTurn, gameBoard);
		cout << endl; //extra spacing
		printCurrentBoard(gameBoard); //reprint the board
		winner = getWinner(gameBoard); //check for a winner
		xTurn = !xTurn; //flip it

		if (winner == " " && isBoardFull(gameBoard))
		{
			winner = "'Err 1'"; //Cat's game...no winner!
		}
	}//end while-loop

	//cat's game? 
	cout << endl; //extra space before
	if (winner == "c")
	{
		cout << "'Err 2'" << endl;
	}
	else
	{
		cout << "The winner is " << winner << endl; //prints X or O
	}
	cout << endl; //extra space


}//end runGame

void intializeGameBoard(string gameBoard[ROWS][COL]) //*****CREATES THE GAMEBOARD*****
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			gameBoard[i][j] == " ";//empty space

		}//end for-loop2
	}//end for-loop 1
}//end initialize gameboard

void printCurrentBoard(string gameBoard[ROWS][COL]) //*****SHOWS THE BOARD*****
{
	for (int i = 0; i < ROWS; i++)
	{
		for (int j = 0; j < COL; j++)
		{
			cout << gameBoard[i][j];
			if (j < 2)
			{
				cout << " | ";
			}
		}
		cout << endl;
		if (i < 2)
		{
			cout << "- - - - -" << endl;
		}
}

	cout << endl; //extra spacing
}//end printCurrentBoard

void getUserInput(bool xTurn, string gameBoard[ROWS][COL])//*****CAPTURES USER INPUT*****
{
	int row = -1; 
	int col = -1; 
	bool keepAsking = true; 
	while (keepAsking)
	{
		cout << "Please enter the row THEN the colum each from 0,1, or 2, separated by a space" << endl;
		cin >> row; 
		cin >> col; 
		if (row >= 0 && col >= 0 && row <= 2 && col <= 2)
		{
			//valid/in-range selection
			//but it STILL could be occupied by an X or O already...
			if (!cellAlreadyOccupied(row, col, gameBoard))
			{
				//only set the cell if the row/col is valid AND not occupied
				keepAsking = false;
			}
			else
			{
				cout<<"That cell is already occupied!"<<endl;
			}
		}
	}//end while-loop
	if (xTurn)
	{
		gameBoard[row][col] = "X";
	}
	else
	{
		gameBoard[row][col] = "O";
	}//end else-if
}//end getUserInput

bool cellAlreadyOccupied(int row, int col, string gameBoard[ROWS][COL])//*****CHECKS FOR OCCUPIED SPACE ON BOARD*****
{
	return gameBoard[row][col] != ""; //if not a space, then it's occupied
}//end cellAlreadyOccupied

string getWinner(string gameBoard[ROWS][COL]) //*****WINNING CONDITION*****
{
	//check rows
	for (int i = 0; i < ROWS; i++)
	{
		if (gameBoard[i][0] != " " && gameBoard[i][0] == gameBoard[i][1] && gameBoard[i][1] == gameBoard[i][2])
		{
			return gameBoard[i][0]; //we have a horizontal match
		}
	}//end for-loop
	//check columns
	for (int i = 0; i < COL; i++)
	{
		if (gameBoard[0][i] != " " && gameBoard[0][i] == gameBoard[1][i] && gameBoard[1][i] == gameBoard[2][i])
		{
			return gameBoard[0][i]; //we have a vertical match
		}
	}//end for-loop

	//check diagonals
	//there are two diagnols, which can test manually / no-loop

	//upper-left to bottom right diagonal
	if (gameBoard[0][0] != " " && gameBoard[0][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[2][2])
	{
		return gameBoard[0][0]; //we have a diagnol match
	}

	//lower-left to upper fight diagonal 
	if (gameBoard[2][0] != " " && gameBoard[2][0] == gameBoard[1][1] && gameBoard[1][1] == gameBoard[0][2])
	{
		return gameBoard[2][0];
	}

	//if we get to here...
	return ""; //no winner yet
}//end getWinner

//test if board is full
bool isBoardFull(string gameBoard[ROWS][COL]) //*****CHECKS TO SEE IF THE BOARD IS FULL*****
{
	int countFill = 0; 

	for (int i = 0; i < ROWS; i++)
	{
		for (int j =0; j<COL; j++)
		{
			if (gameBoard[i][j] != " ")
			{
				countFill++;
			}
		
			
		}
	}
	return countFill == 9; //all 9 cells are full, then board is full
}//end isBoardFull

