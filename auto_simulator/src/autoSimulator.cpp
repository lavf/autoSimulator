//============================================================================
// Name        : autoSimulator.cpp
// Author      : Leticia
// Description : Video text file
//============================================================================

#include <iostream>
#include <string>
#include "JsonFile.h"
#include "TextFile.h"
#include "autoSimulatorUtil.h"


// User's choice is converted to upper case character
char getChoice(){
	char userChoice {};
	std::cin >> userChoice;
	return toupper(userChoice);
}


int main() {

	char userChoice {};
	std::cout << std::endl;

	do {
	// Menu List
	displayMenu();

	// Obtain the user's choice as an upper case character
	userChoice = getChoice();

	// Read text file
	if(userChoice == 'T'){
		TextFile notesTextFile ("src/notesTextFiles/videoeleven.txt");
		notesTextFile.textReader();
	}
	// Parse "Videostream" file (JSON file)
	else if(userChoice == 'V'){
		// JSON Reader File 13.json
		JsonFile videostreamFile ("src/videostreamJsonFiles/13test.json");
		videostreamFile.jsonReaderStream();
	}
	// Parse "Notes" file (JSON file)
	else if(userChoice == 'N'){
		JsonFile notesFile ("src/notesJsonFiles/videoeleven.json");
		notesFile.jsonReaderNotes();
	}
	//
	else if(userChoice == 'S'){
		std::cout << "s" << std::endl;
	}
	//
	else if(userChoice == 'L'){
		std::cout << "l" << std::endl;
	}
	//
	else if(userChoice == 'F'){
		std::cout << "f" << std::endl;
	}
	// Message of goodbye
	else if(userChoice == 'Q'){
		std::cout << "Goodbye" << std::endl;
	}
	// Illegal choices
	else
		std::cout << "Unknown selection, please try again\n" << std::endl;
	}while(userChoice !='Q');


    std::cout << "========================================\n" << std::endl;

}
