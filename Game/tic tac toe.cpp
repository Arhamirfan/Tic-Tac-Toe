#include <iostream>
#include <string>
using namespace std;
class tictactoegame
{
private:
	char board[3][3];
public:
	tictactoegame() {}
	void Setboard()
	{
		int n = 1;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				board[i][j] = '0' + n;
				n++;
			}
		}
	}
	void Printboard()
	{
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (j < 2)
				{
					cout << "  " << board[i][j] << "  |  ";
				}
				else
				{
					cout << board[i][j] << endl;
				}
			}
		}
	}
	void PlayerMove(char num, char Player)
	{
		bool WrongMove = true;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == num)
				{
					board[i][j] = Player;
					WrongMove = false;
				}
			}
		}
		if (WrongMove == true)
		{
			cout << "Wrong move!\n";
		}

	} bool winning(char Player, bool endgame)
	{
		for (int i = 0; i < 3; i++)
		{
			if (board[i][0] == board[i][1] && board[i][1] == board[i][2])
			{
				endgame = true;
			}
		}
		for (int i = 0; i < 3; i++)
		{
			if (board[0][i] == board[1][i] && board[1][i] == board[2][i])
			{
				endgame = true;
			}
		}
		if (board[0][0] == board[1][1] && board[1][1] == board[2][2])
		{
			endgame = true;
		}
		if (board[0][2] == board[1][1] && board[1][1] == board[2][0])
		{
			endgame = true;
		}
		if (endgame == true)
		{
			cout << "Player " << Player << " wins!\n\n";
		}
		return endgame;
	}

	bool CheckDraw(bool endgame)
	{
		int n = 1;
		int counter = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == '0' + n)
				{
					counter++;
				}
				n++;
			}
		}
		if (counter < 1)
		{
			cout << "game is a draw .. " << endl;
			endgame = true;
		}
		return endgame;
	}
};

int main()
{
	bool done = false, endgame = false;
	char Player = 'O', num;
	tictactoegame tictactoe;
	tictactoe.Setboard();

	do
	{
		if (Player == 'X')
		{
			Player = 'O';
		}
		else
		{
			Player = 'X';
		}
		tictactoe.Printboard();
		cout << " Enter Player " << Player << ": number :  ";
		cin >> num;
		cout << "\n";
		if (num == 'q' || num == 'Q')
		{
			cout << "go to hell";
			exit(0);
		}
		tictactoe.PlayerMove(num, Player);
		endgame = tictactoe.winning(Player, endgame);
		endgame = tictactoe.CheckDraw(endgame);
		if (endgame == true)
		{
			tictactoe.Setboard();
			endgame = false;
		}
	} while (!done);
	system("pause");
}
