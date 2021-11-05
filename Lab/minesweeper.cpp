#include "minesweeper.h"

void minesweeper( string input, string output )
{
	char board[SIZE][SIZE];
	bool touchedBoard[SIZE][SIZE], gameOver = false;
	initTouched(touchedBoard);

	int x, y, touched = 0;
	string line, file, _x, _y;
	ifstream fin(input);
	ofstream fout(output);
	if(!fin || !fout)
	{
		cout << "Not found file" << endl;
		exit(100);
	}

	
	while(!gameOver && fin >> line)
	{
		cout << line << endl;
		if(line == "load")
		{
			fin >> file;
			initBoard(board, file);
			fout << "Command: load " << file << endl;
		}
		else if(line == "touch")
		{
			fin >> _x;
			fin >> _y;
			x = stoi(_x) - 1;
			y = stoi(_y) - 1;
			touchBoard(touchedBoard, x, y);
			if(board[x][y] == '*')
				gameOver = true;
			fout << "Command: touch " << _x << " " << _y << endl;
			touched++;
		}
		else if(line == "display")
		{
			fout << "Command: display" << endl;
			displayBoard(fout, board, touchedBoard, gameOver);
		}

	}

	fout << "Game Over\n~~~~~~~~~\nFinal Board\n";
	displayBoard(fout, board, touchedBoard, gameOver=true);
	fout << "Spaces touched: " << touched;

	fin.close();
	fout.close();
}

void initBoard( char board[][SIZE], string file )
{
	string line;
	ifstream fin(file);
	if(!fin)
	{
		cout << "Not load file" << endl;
		exit(100);
	}

	for(int i = 0; i < SIZE; i++)
	{
		fin >> line;
		for(int j = 0; j < SIZE; j++)
		{
			board[i][j] = line.at(j);
		}
	}
}

void displayBoard( ostream& out, char board[][SIZE], bool touchedBoard[][SIZE], bool gameOver )
{
	for(int i = 0; i < SIZE; i++)
	{
		for(int j = 0; j < SIZE; j++)
		{
			if(touchedBoard[i][j] && board[i][j] == '.')
			{
				int count = 0;
				if(i != 0 && board[i - 1][j] == '*')
					count++;
				if(i != SIZE - 1 && board[i + 1][j] == '*')
					count++;
				if(j != 0 && board[i][j - 1] == '*')
					count++;
				if(j != SIZE - 1 && board[i][j + 1] == '*')
					count++;
				if(i != 0 && j != 0 && board[i - 1][j - 1] == '*')
					count++;
				if(i != 0 && j != SIZE - 1 && board[i - 1][j + 1] == '*')
					count++;
				if(i != SIZE - 1 && j != 0 && board[i + 1][j - 1] == '*')
					count++;
				if(i != SIZE - 1 && j != SIZE - 1 && board[i + 1][j + 1] == '*')
					count++;
				out << count;
			}
			else if(!touchedBoard[i][j] && board[i][j] == '.')
			{
				out << '.';
			}
			else if(touchedBoard[i][j] && gameOver)
			{
				out << '*';
			}
			else if(!touchedBoard[i][j] && gameOver)
			{
				out << '@';
			}
			else
			{
				out << '.';
			}
		}
		out << endl;
	}
	out << endl;
}

void initTouched( bool touchedBoard[][SIZE] )
{
	for(int i = 0; i < SIZE; i++)
		for(int j = 0; j < SIZE; j++)
			touchedBoard[i][j] = 0;
}

void touchBoard( bool board[][SIZE], int x, int y )
{
	board[x][y] = 1;
}

int main(){
    minesweeper("input.txt", "output.txt");
	
	return 0;
}