/********************************
* Name: Grace Brown             *
* Last Edited: 25 Jan 26        *
* Program: Rock Paper Scissors  *
********************************/

#include <iostream>
#include <algorithm>											// Added for transform function
#include <cstdlib>												// Added for rand() function
#include <thread>												// Added for sleep_for function
#include <chrono>												// Added for time duration (end of game)
using namespace std;

int choices(){													// 4 options for input
	
	int num;
	
	do{															// Only loops if invalid choice selected
		cout << "[1. Rock] [2. Paper] [3.Scissors] \n"; 
		cin >> num;
		cout << "\n";
			
		if(num == 1){
			cout << "You Chose ROCK! \n";
		}else if(num == 2){
			cout << "You Chose PAPER! \n";
		}else if(num == 3){
			cout << "You Chose SCISSORS! \n";
		}else{
			cout << "PLEASE SELECT A VALID OPTION! \n";
		}
	}
	while(!(num == 1 || num == 2 || num ==3));
	
	return num;													// Returns your choice to be compared to computer's choice
}

bool menu(){													// Returns T/F to determine if loop in main() plays
	string answer;
	bool result;
	
	do{
		cout << "\n -------Would you like to play Rock Paper Scissors?------- \n";
		cout << "[Please Type YES or NO] \n";
		cin >> answer;
		transform(answer.begin(), answer.end(), answer.begin(), ::toupper);
		
		if(answer == "YES"){
			result = true;
		} else if(answer == "NO"){
			result = false;
		}else{
			cout << "PLEASE SELECT A VALID CHOICE! \n";
		}
	}
	while( !(answer == "YES" || answer == "NO"));			// If answer is invalid, loop plays again
	
	return result;
}

void scoreboard(int result, int &wins, int &losses){								// Counts up wins/losses
	
	if(result == 2){																//Incrementally counts up by one
		wins++;
	}else if(result == 1){
		losses++;
	}
  
	cout << "\n -------- SCOREBOARD --------\n";									// Scoreboard 
	cout << "     YOU: " << wins  << endl;
	cout << "COMPUTER: " << losses << endl;
	cout << "---------------------------- \n";
}

void endscreen(int wins, int losses){												// Displays Win/Lose/Tie message

	if(wins > losses){
		cout << "CONGRATULATIONS!!! YOU WIN!" << endl;
	}else if(wins < losses){
		cout << "GAME OVER!!! YOU LOSE!" << endl;
	}else if(wins == losses){
		cout << "TIE!!!" << endl;
	}
}

void gameplay(){											// holds game loop

	cout << " \n Best of Three! \n";
	static int wins = 0;										// will be referenced!
	static int losses = 0;										// will be referenced!
		
	for(int i = 1; i < 4; i++){
		int randnum = rand() % 4;							// selects rand num between 1-3 (1 Rock, 2 Paper, 3 Scissor)
		int result;											// 0 TIE, 1 LOSE, 2 WIN			
		
		cout << "\n ----- ROUND " << i << "----- \n";
		
		int userchoice = choices();
		
		switch(userchoice){								// Switch for RESULTS 
		case 1:											// results for ROCK
			if(randnum == 1){
				cout << "COMPUTER CHOSE ROCK! \n";
				result = 0;
			}else if(randnum == 2){
				cout << "COMPUTER CHOSE PAPER! \n";
				result = 1;
			}else{
				cout << "COMPUTER CHOSE SCISSOR! \n";
				result = 2;
			}
			break;
			
		case 2:											// results for PAPER
			if(randnum == 1){
				cout << "COMPUTER CHOSE ROCK! \n";
				result = 2;
			}else if(randnum == 2){
				cout << "COMPUTER CHOSE PAPER! \n";
				result = 0;
			}else{
				cout << "COMPUTER CHOSE SCISSOR! \n";
				result = 1;
			}
			break;
			
		case 3:											// results SCISSOR
			if(randnum == 1){
				cout << "COMPUTER CHOSE ROCK! \n";
				result = 1;
			}else if(randnum == 2){
				cout << "COMPUTER CHOSE PAPER! \n";
				result = 2;
			}else{
				cout << "COMPUTER CHOSE SCISSOR! \n";
				result = 0;
			}
			break;
		}													// FIGURE OUT WAY TO OPIMIZE RESULTS
		scoreboard(result, wins, losses);
	}
	endscreen(wins, losses);								// Triggers endscreen
}

int main(){
	
	if(menu()){											// if you select YES in menu, game starts
		gameplay();
		cout << "\n";
	}
	
	return 0;
}
