#include <iostream>
#include <iomanip>
using namespace std;

// Declared functions.
bool writeMove(char grid[][3], int, int, char turn);
void resetGrid(char grid[][3]);
bool victory(char grid[][3]);
void printGrid();
void play();

// Some global vars.
int attempts = 0;
char grid[3][3];
char winner;

int main() {
	resetGrid(grid);
	play();

	cin.get();
	return 0;
}

// Initialized functions

// Resets the grid values to 0. Pretty useless as I have not implemented a way to continue the game.
void resetGrid(char grid[][3]) {
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			grid[i][j] = ' ';
		}
	}
	
}

// Prints a really shitty grid.
void printGrid() {
	cout << "     1     2     3   " << endl << "                     " << endl;
	for (int i = 0; i < 3; i++) {
		cout << i + 1<<"  ";
		for (int j = 0; j < 3; j++) {
			cout<< setw(3) << grid[i][j] << setw(3)<<"|";
		}
		cout << endl << "    ----|-----|-----|" << endl;
	}
}

// This handles the actual playing.
void play()
{
	char turn = 'X';
	int row, column;
	do {
		printGrid();
		if (turn == 'X') {
			do {
				cout << "-= Xs turn =- " << endl;
				do {
					cout << "Line: ";
					cin >> row;
					cout << endl;
					cout << "Column: ";
					cin >> column;
					cout << endl;
				} while ((row > 3 || row<1) || (column > 3 || column<1));
			} while (writeMove(grid, row, column, turn));
			turn = 'O';
			system("CLS");
		}
		else {
			do {
				cout << "-= Os turn =- " << endl;
				do {
					cout << "Line: ";
					cin >> row;
					cout << endl;
					cout << "Column: ";
					cin >> column;
					cout << endl;
				} while ((row > 3 || row < 1) || (column > 3 || column < 1));
			} while (writeMove(grid, row, column, turn));
			turn = 'X';
			system("CLS");
		}
		attempts++;
	} while (victory(grid)==0);
	
}

// Writes the move, or returns a message if you can't input your turn on pre-existing coordinates.
bool writeMove(char grid[][3], int row, int column, char turn) {
	if (grid[row-1][column-1]==' '){
		grid[row-1][column-1] = turn;
		printGrid();
		return 0;
	}
	else {
		cout << row-1 << ", " << column-1 << " is already taken."<<endl;
		return 1;
	}
}

// Checks for victory. There's probably an easier way to check all 8 possibilities, I can't be arsed. 
bool victory(char grid[][3])
{
	char testingInput = 'X';
	if (attempts == 9) {
		system("CLS");
		cout << "IT'S A TIE!";
		return true;
	}
	for (int i = 0; i < 2; i++) {
		if (i == 1) {
			testingInput = 'O';
		}

		// This looks like a CPU heatsink. lol.
		if (grid[0][0] == testingInput && grid[0][1] == testingInput && grid[0][2] == testingInput ||
			grid[1][0] == testingInput && grid[1][1] == testingInput && grid[1][2] == testingInput ||
			grid[2][0] == testingInput && grid[2][1] == testingInput && grid[2][2] == testingInput ||
			grid[0][0] == testingInput && grid[1][0] == testingInput && grid[2][0] == testingInput ||
			grid[0][1] == testingInput && grid[1][1] == testingInput && grid[2][1] == testingInput ||
			grid[0][2] == testingInput && grid[1][2] == testingInput && grid[2][2] == testingInput ||
			grid[0][0] == testingInput && grid[1][1] == testingInput && grid[2][2] == testingInput ||
			grid[2][0] == testingInput && grid[1][1] == testingInput && grid[0][2] == testingInput) {
			system("CLS");
			cout << "THE WINNER IS " << testingInput;
			return true;
		}
	}
	testingInput = 'X';
	return false;
	}
