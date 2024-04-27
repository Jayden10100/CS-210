#pragma once
#include <iostream> 
#include <iomanip>  
#include <string>

using namespace std; 

// Will declare a function for the 12 and 24 hour clocks. 
void clockBorderScreen() {
	for (int i = 0; i < 16; ++i) {
		cout << " "; 
	}
	for (int i = 0; i < 27; ++i) { //12-hour clock border. 
		cout << "*";
	}
	for (int i = 0; i < 5; ++i) { // for the space between the clocks 
		cout << " "; 
	}
	for (int i = 0; i < 27; ++i) {//24-hour clock border 
		cout << "*"; 
	}
	cout << endl; 
}

//This function will output both clocks and convert the 24-hour clock to 12hr format with AM/PM paramaters. 
void displayClocks(int hours, int minutes, int seconds) {
	// declaring variables 
	int hourConv; //variable for hour conversion 
	int minConv;  //variable for min conversion
	int secConv;  //variable for sec conversion 
	string meridian = "AM"; //AM/PM determinant 

	//Conversion from 24-hr clock to a 12-hr clock format. 
	if (hours == 0) {
		hourConv = 12;
	} 
	else if (hours == 12) {
		hourConv = hours; 
		meridian = "PM"; 
	}
	else if (hours > 12) {
		hourConv = hours - 12;
		meridian = "PM"; 
	}
	else {
		hourConv = hours;
	}

	// will display clock titles 
	cout << "\t\t*\t" << "12-Hour Clock";
	cout << "\t  *";
	cout << "\t*"     << "\t 24-Hour Clock";
	cout << "\t  *"   << endl;

	//sets time on 12-hr clock 
	cout << "\t\t* \t "; 
	cout << setw(2)  << setfill('0') << hourConv << ":"; //12 hour format display
	cout << setw(2)  << minutes << ":"; 
	cout << setw(2)  << seconds; 
	cout << " " << meridian; 
	cout << "\t  *";

	//sets time on 24-hour clock 
	cout << "\t*"   << "\t   "; 
	cout << setw(2) << setfill('0') << hours << ":"; // 24 hour format display
	cout << setw(2) << minutes << ":";
	cout << setw(2) << seconds;
	cout << " " << meridian;
	cout << "\t  *" << endl;
}

// function to get input from user for initial time. 
void initialTimefrmUser(int& setHour, int& setMinute, int& setSecond) {
	//declaring and validating variables 
	string userString; //Gets user input 
	string checkString; // verifies user input is correct 
	bool correctTime = false; //will verify valid time input during while loop 
	int firstColonPlacement; //checks for accurate placement of colon 
	int secondColonPlacement; //checks for accurate placement of second colon 

	while (!correctTime) {
		cout << "Enter time as HH:MM:SS in 24-Hour format: "; //gets user input for the 24-hour clock 
		getline(cin, userString);
		// will check for proper colon placement from user 
		firstColonPlacement = userString.find(':');
		secondColonPlacement = userString.find(':', firstColonPlacement + 1);

		// will convert and display 24-Hour clock, unless error is caught. 
		try
		{
			setHour = stoi(userString.substr(0, firstColonPlacement));
			setMinute = stoi(userString.substr(firstColonPlacement + 1, secondColonPlacement));
			setSecond = stoi(userString.substr(secondColonPlacement + 1, userString.size() - 1));
		}
		catch (const std::exception&)
		{
			// added for try parameter. Technically isn't needed at this time.
		} // checking for correct formatting paramters from user. 
		if (userString.size() != 8) { //checking for proper input length
			cout << "The time you entered is invalid. Try again." << endl;
			!correctTime;
		}
		else if (setHour < 0 || setHour > 23) { // checking for valid hour input 
			cout << "The time you entered is invalid. Check the hours, and try again." << endl;
			!correctTime;
		}
		else if (setMinute < 0 || setMinute > 59) { // checking for valid minute input 
			cout << "The time you entered is invalid. Check the minutes, and try again." << endl; 
			!correctTime; 
		}
		else if (setSecond < 0 || setSecond > 59) { //checking for valid second input 
			cout << "The time you entered is invalid. Check the seconds, and try again." << endl; 
			!correctTime; 
		}
		else {
			correctTime = true; 
		}
	}
}
// this is the main menu function. 
void PrintMenu() {
	cout << endl; 
	cout << "*********************************" << endl; 
	cout << "* 1- Add One Hour\t\t*" << endl; 
	cout << "* 2- Add One Minute\t\t*" << endl;
	cout << "* 3- Add One Second\t\t*" << endl;
	cout << "* 4- Exit\t\t\t*" << endl;
	cout << "*********************************" << endl;
	cout << endl; 
}

//function to take in user input, validate it and change clock. 
void processUserChoice(int& userInput, int& setHour, int& setMinute, int& setSecond) {
	cout << "Select an option, 1-4: "; //gets user input for menu choice 

	//verifying user input is valid 
	if (!(cin >> userInput)) { // if user input is invalid, the cin function will ignore and reset. 
		cin.clear(); 
		cin.ignore(numeric_limits<streamsize>::max(), '\n');
		userInput = 0;
	}
	// switch statement to gather user input and function based on user input 
	switch (userInput) {
	case 1: 
		cout << "1 hour added." << endl; 
		if (setHour < 23) {
			++setHour; // to increment until 24 is reached. 
		}
		else {
			setHour = 00; // to reset to 00 once 24 has been reached. 
		}
		break;
	case 2: 
		cout << "1 minute added." << endl; 
		if (setMinute < 59) {
			++setMinute; // to increment until 60 is reached.  
		}
		else {
			setMinute = 00; //resets to 00 once 60 minutes has been reached. 
		}
		break; 
	case 3: 
		cout << "1 second added." << endl;
		if (setSecond < 59) {
			++setSecond; // to increment until 60 is reached.  
		}
		else {
			setSecond = 00; //resets to 00 once 60 minutes has been reached. 
		}
		break;
	case 4: 
		cout << "Goodbye!" << endl; 
		break; 
	default: 
		cout << "Invalid choice. Please enter a number between 1-4: " << endl; 
		cin.clear(); 
		break; 
 	}
}