#include <iostream>
using namespace std;

char board[3][3] = { { '1', '2', '3' }, { '4', '5', '6' }, {'7', '8', '9' } }; // this variable creates a board by assigning a 3 x 3 grid.

char currentMarker;
int currentPlayer;


void drawBoard() // this function draws the board by using columns and rows, the first number decides which row, the second number decides which column
{
	cout << "" << board[0][0] << " | " << board[0][1] << " | " << board[0][2] << endl;
	cout << "----------" "\n";
	cout << "" << board[1][0] << " | " << board[1][1] << " | " << board[1][2] << endl;
	cout << "----------" "\n";
	cout << "" << board[2][0] << " | " << board[2][1] << " | " << board[2][2] << endl;
}

bool placeMarker(int slot)   //here it decides where to put the marker by using math
{
	int row = slot / 3;
	int col;

	if (slot % 3 == 0)
	{
		row = row - 1;
		col = 2;
	}
	// to find the columns it checks if the slot modulus 3 has a remainder of 0, if it does it knows that it must be in the 3rd column, 
	else col = (slot % 3) - 1;						// if it doesnt have a remainder of 0, then it devides the slot number by 3 then subtracts by 1 to get the col

	if (board[row][col] != 'X' && board[row][col] != 'O') // if statement checks if a slot has been filled, and places a marker if its empty
	{
		board[row][col] = currentMarker;
		return true;
	}
	else return false;
}

int winner()
{
	
	for (int i = 0; i < 3; i++)
	{	
		//row check
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2]) return currentPlayer;

		//column check
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i]) return currentPlayer;
	}
	// diagonal check
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2]) return currentPlayer;
	if (board[0][2] == board[1][1] && board[1][1] == board[2][0]) return currentPlayer;

	return 0; 

}

void swap_player_and_marker()  // decides active player.
{
	if (currentMarker == 'X') currentMarker = 'O';
	else currentMarker = 'X';

	if (currentPlayer == 1) currentPlayer = 2;
	else currentPlayer = 1;

}



void game()
{
	cout << "Player 1, choose your marker plz: ";	//Player 1 selects a custum marker
	char markerP1;
	cin >> markerP1;

	currentPlayer = 1;
	currentMarker = markerP1; //from here player 1's custum marker are displayed



	drawBoard();

	int playerWon;
		

	for (int i = 0; i < 9; i++) // a game that ends in a tie has a total of 9 moves, which means that somebodey either wins, or the board gets filled.
	{
		cout << "its player " << currentPlayer << "'s turn, choose a slot";
		int slot;
		cin >> slot;


		if (slot < 1 || slot > 9)
		{
			cout << "not a valid slot!" << "\n";
			i--;
			continue;
		}
		if(!placeMarker(slot)) 
		{
			cout << "that slot has allready been taken!" << "\n";
			i--;
			continue;										// makes the turn not count towards the 9 moves.
		}

		drawBoard(); 

		playerWon = winner(); // checks if somebody has won or not

		if (playerWon == 1)
		{
			cout << "player 1 won!"; 
			break; 
		}
		if (playerWon == 2)
		{
			cout << "player 2 won!"; 
			break;
		}

		
		swap_player_and_marker();

	
	}

	if (playerWon == 0) cout << "thats a tie, nobody wins!"; // none of the winning conditions has been filled, game ends in a tie.
}

int main() // runs the game
{
	game();
	
}