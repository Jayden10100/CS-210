//Jay'Den Embrey 
// March 29, 2024 
// CS-210 
// Project 1 submission 

#include "Clock.h"

int main() {
	// declaring variables 
	int userInput = 0;
	int setHour = 0;
	int setMinute = 0;
	int setSecond = 0;

	//Get initial time from user 
	initialTimefrmUser(setHour, setMinute, setSecond);

	//will enter the program's while loop. 
	while (userInput != 4) {
		// calling functions from header file 
		clockBorderScreen();  // calling the clock's border screen 
		displayClocks(setHour, setMinute, setSecond); // prints the clocks to screen 
		clockBorderScreen(); // calling the bottom of the border screen 
		PrintMenu(); // prints the menu that allows user to change the clocks 
		processUserChoice(userInput, setHour, setMinute, setSecond); //modifies clocks based on user input  
	}
	return 0;
}