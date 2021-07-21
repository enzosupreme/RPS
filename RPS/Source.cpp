#include<iostream>
#include<fstream>
#include<iomanip>
#include<string>
#include<time.h>
#include<cctype>
using namespace std;

string getMove(int);
int PlayerMove(string);
char match(int, int);
string fCookie(int);

const int SIZE = 358;


int main()
{
	srand(time(NULL));
		
	string p_move;
	string c_move;
	char response;
	int win = 0, lose = 0, draw = 0;

	int p = 0;
	
	cout << "Would you like to play rock, paper, scissors?('y' or 'n'): ";
	cin >> response;
	
	while (response == 'y' || response == 'Y')
	{
		int fortune = rand() % SIZE;
		int  comp = rand() % 3 + 1;
		c_move = getMove(comp);
		cout << "ROCK...PAPER...SCISSORS...GO!(Type 'score' to check your score!): \n";
		cin >> p_move;
		p = PlayerMove(p_move);		

		if (match(p, comp) == 'w')
		{
			cout << endl;
			cout << p_move << " vs. " << c_move << "!" << endl;
			cout << "Congratulations! You have won!" << endl;
			win++;
		}
		else if (match(p, comp) == 'l')
		{
			cout << endl;
			cout << p_move << " vs. " << c_move << "!" << endl;
			cout << "You lose! Try again!" << endl;
			lose++;
		}
		else if (match(p, comp) == 'd')
		{
			cout << endl;
			cout << p_move << " vs. " << c_move << "!" << endl;
			cout << "It is a draw!" << endl;
			draw++;
		}
		else if (match(p, comp) == 'y')
		{
			cout << "You rolled a nat 20. You win!" << endl;
			win++;
		}
		else if (match(p, comp) == 's')
		{
			cout << "\n\t Score:\n-----------------------------\n";
			cout << endl << setw(5) << "Wins: " << win << " Losses: " << lose << " Draws: " << draw << endl;
		}
		else if (match(p, comp) == 'f')
		{
			cout << "\t   Fortune: \n" <<"' " << fCookie(fortune) <<"'"<< endl;
		}

		else
		{
			cout << "Error: invalid selection! Try again!" << endl;
		}


		cout << endl << "Would you like to play rock, paper, scissors?('y' or 'n'): ";
		cin >> response;
	}
	

	cout << "Thanks for playing!" << endl;

	system("pause");
	return 0;

	
}

string getMove(int roll)
{
	string move;

	switch (roll)
	{
	case 1: move = "rock";
		break;
	case 2: move = "paper";
		break;
	case 3: move = "scissors";
		break;
	}
	return move;

}

int PlayerMove(string player)
{
	int p = 0;
	if (player == "rock" || player == "Rock")
		p = 1;
	else if (player == "Paper" || player == "paper")
		p = 2;
	else if (player == "scissors" || player == "Scissors")
		p = 3;
	else if (player == "score" || player == "Score")
		p = 69;
	else if (player == "d20")
		p = 420;
	else if (player == "fortune" || player == "Fortune")
		p = 7;

	return p;
}

char match(int player, int comp)
{
	char l = 'l';
	char e = 'e';
	char w = 'w';
	char d = 'd';
	char s = 's';
	char y = 'y';
	char f = 'f';

	switch (player)
	{
	case 1:
		switch (comp) {
		case 1: 
			return d;
			break;
		case 2: 
			return l;
			break;
		case 3: 
			return w;
			break;
		}
		break;
	case 2:
		switch (comp) {
		case 1: 
			return w;
			break;
		case 2: 
			return d;
			break;
		case 3: 
			return l;
			break;
		}
		break;
	case 3:
		switch (comp) {
		case 1: 
			return l;
			break;
		case 2: 
			return w;
			break;
		case 3: 
			return d;
			break;
		}
		break;


	case 69:
		return s;
		break;
	case 420:
		return y;
		break;
	case 7:
		return f;
		break;
	default:
		return e;
		
	}

}

string fCookie(int number)
{
	string line;
	fstream fortuneFile("fortune.txt",ios::in);
	getline(fortuneFile, line);
	for (int x = 0; x < number; x++)
	{
		getline(fortuneFile, line);
	}
	fortuneFile.close();
	
	
	return line;

}



