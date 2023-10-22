#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

/*Prints Menu*/
void Menu();
/*Takes User Input*/
void input();
/*Process User Input*/
void Processinput(int x);
/*Generates Random Numbers*/
int randomnumber(int Upper,int Lower);
/*Higher or Lower Game*/
void game1();
/*Rock Paper Scissors Game*/
void game2();
/*Guess the numbers*/
void game3();

//Variable
int choice = 0;

int main()
{
	do
	{
		Menu();
		input();
		Processinput(choice);
	} while (choice != 4);
	return 0;
}

void Menu()
{
	cout << "\t\tMENU" << endl;
	cout << "1.	Play Higher or Lower" << endl;
	cout << "2.	Play Rock-Paper-Scissors" << endl;
	cout << "3.	Guess the numbers" << endl;
	cout << "4.	Quit" << endl;
}

void input()
{
	cout << "Enter Your Choice: ";
	cin >> choice;
}

void Processinput(int x)
{
	switch (x)
	{
	case 1:
	{
		cout << "You have opted to play Higher or Lower Game" << endl;
		cout << setw(44) << setfill('-') << "\n";
		game1();
		cout << setw(44) << setfill('-') << "\n";
		cout << endl;
		break;
	}
	case 2:
	{
		cout << "You have opted to play Rock-Paper-Scissor Game" << endl;
		cout << setw(44) << setfill('-') << "\n";
		game2();
		cout << setw(44) << setfill('-') << "\n";
		cout << endl;
		break;
	}
	case 3:
	{
		cout << "You have opted to Guess the numbers" << endl;
		cout << setw(44) << setfill('-') << "\n";
		game3();
		cout << setw(44) << setfill('-') << "\n";
		cout << endl;
		break;
	}
	case 4:
	{
		cout << "Thanks For Playing" << endl;
		cout << "Exitting the Game Library" << endl;
		break;
	}
	default:
	{
		cout << "!! Invalid Choice " << endl;
	}
	}
}

int randomnumber(int Upper,int Lower)
{
	srand(static_cast<unsigned int>(time(nullptr)));
	int randomnumber = rand() % (Upper - Lower + 1) + Lower;
	return randomnumber;
}

void game1()
{
	char guess;
	cout << "Generating two random numbers" << endl;
	int num1 = randomnumber(20, 1);
	int num2 = randomnumber(20, 0);
	cout << endl;
	cout << "One of the 2 random numbers is: " << num1 << endl;
	cout << "Guess if the other number is higher or lower than this" << endl;
	cout << endl;
	cout << "If you think other number is higher Enter 'H', otherwise Enter 'L' : ";
	cin >> guess;
	if (guess != 'H' && guess != 'L')
	{
		cout << "Please Enter a valid guess choice" << endl;
		do
		{
			cout << "Enter your Guess again : ";
			cin >> guess;
		} while (guess != 'H' && guess != 'L');
	}

	cout << "2nd number is: " << num2 << endl;

	if (guess == 'H')
	{
		if (num2 > num1)
		{
			cout << "Your Guess is Correct. You won" << endl;
		}
		else
		{
			cout << "Your Guess is incorrect. You Lost" << endl;
		}
	}
	else if(guess=='L')
	{
		if (num2 < num1)
		{
			cout << "Your Guess is Correct. You won" << endl;
		}
		else
		{
			cout << "Your Guess is incorrect. You Lost" << endl;
		}
	}
}

void game2()
{
	int num = randomnumber(3, 1);
	char move, usermove;
	if (num == 1)
	{
		move = 'P';
	}
	else if (num == 2)
	{
		move = 'S';
	}
	else
	{
		move = 'R';
	}
	cout << "I have decided my move. Now it's Your turn" << endl;
	cout << endl;
	cout << " |'P' for Paper | 'S' for Scissior | 'R' for Rock | " << endl;
	cout << "Enter your move: ";
	cin >> usermove;
	if (usermove != 'S' && usermove != 'R' && usermove != 'P')
	{
		cout << "Please Enter a valid move" << endl;
		do
		{
			cout << "Enter your move again: ";
			cin >> usermove;
		} while (usermove != 'S' && usermove != 'P' && usermove != 'R');
	}
	if (move == 'S')
	{
		cout << "I had chosen Scissors, ";
		if (usermove == 'P')
		{
			cout << "and you chose Paper. Scissors beat Paper" << endl;
			cout << "You Lost. Better Luck next time" << endl;
		}
		else if (usermove == 'R')
		{
			cout << "and you chose Rock. Rock beat Scissors" << endl;
			cout << "Congratulations. You Won" << endl;
		}
		else
		{
			cout << "you also chos Scissors." << endl;
			cout << "It's a tie" << endl;
		}
	}
	else if (move == 'R')
	{
		cout << "I had chosen Rock, ";
		if (usermove == 'S')
		{
			cout << "and you chose Scissors. Rock beat Scissors" << endl;
			cout << "You Lost. Better Luck next time" << endl;
		}
		else if (usermove == 'P')
		{
			cout << "and you chose Paper. Paper beat Rock" << endl;
			cout << "Congratulations. You Won" << endl;
		}
		else
		{
			cout << "you also chos Rock." << endl;
			cout << "It's a tie" << endl;
		}
	}
	else
	{
		cout << "I had chosen Paper, ";
		if (usermove == 'R')
		{
			cout << "and you chose Rock. Paper beat Rock" << endl;
			cout << "You Lost. Better Luck next time" << endl;
		}
		else if (usermove == 'S')
		{
			cout << "and you chose Scissors. Scissors beat Paper" << endl;
			cout << "Congratulations. You Won" << endl;
		}
		else
		{
			cout << "you also chos Paper." << endl;
			cout << "It's a tie" << endl;
		}
	}
}

void game3()
{
	int num1 = randomnumber(9, 0), num2 = randomnumber(8, 0), num3 = randomnumber(9, 1);
	int guess1 = 0, guess2 = 0, guess3 = 0;
	cout << "I have guessed 3 random numbers between 0 and 9" << endl;
	cout << "Now it's Your turn" << endl;
	cout << endl;
	cout << "Guess 3 numbers and enter them: ";
	cin >> guess1 >> guess2 >> guess3;
	do
	{
		if (guess1 > 9 || guess1 < 0)
		{
			cout << "Please enter valid 1st guess: ";
			cin >> guess1;
		}
		else if (guess2 > 9 || guess2 < 0)
		{
			cout << "Please enter valid 2nd guess: ";
			cin >> guess2;
		}
		else if (guess3 > 9 || guess3 < 0)
		{
			cout << "Please enter valid 3rd guess: ";
			cin >> guess3;
		}
	} while (guess1 > 9 || guess1 < 0 && guess2 > 9 || guess2 < 0 && guess3 > 9 || guess3 < 0);

	if (guess1 == num1 && guess2 == num2 && guess3 == num3)
	{
		cout << "Three matching, in order" << endl;
	}

	else if (guess1 == num1 || guess1 == num2 || guess1 == num3)
	{
		if (guess2 == num1 || guess2 == num2 || guess2 == num3)
		{
			if (guess3 == num1 || guess3 == num2 || guess3 == num3)
			{
				cout << "Three matching, not in order" << endl;
			}
			else
			{
				cout << "Two matching" << endl;
			}
		}
		else
		{
			cout << "One matching" << endl;
		}
	}
	else
	{
		cout << "No Matching" << endl;
	}
	cout << "I generated following 3 numbers: " << num1 << " " << num2 << " " << num3 << endl;
}