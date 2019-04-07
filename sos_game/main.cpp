#include <iostream>
#include <time.h>

using std::cout;
using std::cin;

bool isOccupied[3][3] = { 0 };
char moved[3][3];

void drawBoard();
bool isNextMoveCanLose(int row, int col, char input);
bool simulateIsWon(int row, int col, char input);
void aiMoves();
bool isWin(char modelMoved[3][3]);

int main()
{
	int row, col;
	char input;
	int numMoved = 0;
	while (true) {
		system("cls");
		drawBoard();
		if (isWin(moved)) {
			cout << "AI Win (-_-).\n";
			return 0;
		}

		do
		{
			cout << "Enter Row: "; cin >> row;
			cout << "Enter Col: "; cin >> col;
			cout << "Enter Char: "; cin >> input;
		} while (row < 0 || row > 2 || col < 0 || col > 2
			|| isOccupied[row][col] || (input != 's' && input != 'o'));

		isOccupied[row][col] = true;
		moved[row][col] = tolower(input);
		++numMoved;

		if (isWin(moved)) {
			system("cls");
			drawBoard();
			cout << "You Wins!!!\n";
			return 0;
		}
		else if (numMoved == 9) {
			system("cls");
			drawBoard();
			cout << "DRAW.\n";
			return 0;
		}

		aiMoves();
		++numMoved;
	} //end while

	return 0;
}

bool isNextMoveCanLose(int row, int col, char input)
{
	//Check if want to put "o" in Middle Of the Board
	if (row == 1 && col == 1) {
		if (input != 'o')
			return false;

		for (int r = 0; r < 3; r++)
			for (int c = 0; c < 3; c++)
				if (isOccupied[r][c] && moved[r][c] == 's')
					return true;
	}

	//Check 3 times
	if ((row + col) % 2 == 0) {
		if (input == 'o')
			return false;

		//Verical, Horiziontal and Dia CHECK
		for (int i = 0; i < 3; i++) {
			char check = (i == 1 ? 'o' : 's');
			if (isOccupied[i][col] && moved[i][col] == check)
				return true;

			if (isOccupied[row][i] && moved[row][i] == check)
				return true;

			if (isOccupied[i][i] && moved[i][i] == check)
				return true;
		}
	}
	//Check 2 times
	else {
		for (int i = 0; i < 3; i++) {
			char check = (i == 1 ? 'o' : 's');
			if (isOccupied[i][col] && moved[i][col] == check)
				if (!isOccupied[(i == 0 ? 2 : 0)][col])
					return true;

			if (isOccupied[row][i] && moved[row][i] == check)
				if (!isOccupied[row][(i == 0 ? 2 : 0)])
					return true;
		}
	}

	return false;
}


bool simulateIsWon(int row, int col, char input)
{
    //If row and col is already occupied simply return false
	if (isOccupied[row][col])
		return false;

	//Copy moved to tmp to make an experiment
	char tmp[3][3];
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			tmp[i][j] = moved[i][j];

	tmp[row][col] = input;
	if (isWin(tmp))
		return true;
	else
		return false;
}


void aiMoves()
{
	int row, col;
	char input;

	for (int r = 0; r < 3; r++)
		for (int c = 0; c < 3; c++)
			for (int i = 0; i < 2; i++)
			{
				input = (i ? 's' : 'o');
				if (simulateIsWon(r, c, input)) {
					moved[r][c] = input;
					isOccupied[r][c] = true;
					return;
				}
			}

	srand(time(NULL));
	do {
		row = rand() % 3;
		col = rand() % 3;
		input = rand() % 2 ? 's' : 'o';
	} while (isOccupied[row][col] || isNextMoveCanLose(row, col, input));

	if (!isOccupied[row][col]) {
		moved[row][col] = input;
		isOccupied[row][col] = true;
	}
}


bool isWin(char modelMoved[3][3])
{
	for (int i = 0; i < 3; i++) {
		if (modelMoved[1][i] == 'o') {
			//Vertical
			if (modelMoved[0][i] == 's' && modelMoved[2][i] == 's')
				return true;
			if (i == 1) {
				//Horiziontal
				if (modelMoved[1][i - 1] == 's' && modelMoved[1][i + 1] == 's')
					return true;
				//Dia
				if (modelMoved[0][0] == 's' && modelMoved[2][2] == 's')
					return true;
				if (modelMoved[0][2] == 's' && modelMoved[2][0] == 's')
					return true;
			}
		}
	}

	//Check 1st Row Horiziontal
	if (modelMoved[0][1] == 'o') {
		if (modelMoved[0][0] == 's' && modelMoved[0][2] == 's')
			return true;
	}

	//Check 3rd Row Horiziontal
	if (modelMoved[2][1] == 'o') {
		if (modelMoved[2][0] == 's' && modelMoved[2][2] == 's')
			return true;
	}

	return false;
}

void drawBoard()
{
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			if (isOccupied[i][j])
				cout << moved[i][j];
			else
				cout << '_';

			if (j < 2)
				cout << '|';
		}
		cout << '\n';
	}
}
