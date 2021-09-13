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


int main() {

	char userLanguageChoice {};
	char userChoice {};

	do {
		displayLanguageMenu();
		userLanguageChoice = getChoice(userLanguageChoice);

		char userSubChoice {};
		std::string textDirectory {"notesTextFiles"};
		std::string videoJsonDirectory {"videostreamJsonFiles"};
		std::string notesJsonDirectory {"notesJsonFiles"};

		std::string textType {"Text"};
		std::string videoJsonType {"Videostream"};
		std::string notesJsonType {"Notes"};



		std::cout << std::endl;

		if(userLanguageChoice == 'E'){
			do {
			// Menu List
			displayMenu();

			// Obtain the user's choice as an upper case character
			userChoice = getChoice(userChoice);

			// Read text file
			if(userChoice == 'T'){
				do {
				displaySubMenu(textDirectory, textType);
				userSubChoice = getChoice(userSubChoice);

				if(userSubChoice == 'S'){
					listDirectoryNotesText();
				}
				else if(userSubChoice == 'E'){
					std::string userTextFileInput {};
					std::cout << "Enter text file name: ";
					std::cin >> userTextFileInput;
					TextFile notesTextFile ("src/notesTextFiles/" + userTextFileInput);
					notesTextFile.textReader();
				}
				// Return to main menu
				else if(userSubChoice == 'R'){
					std::cout << "\nTo Main Menu...\n" << std::endl;
				}
				// Illegal choices
				else
					std::cout << "Unknown selection, please try again\n" << std::endl;
				}while(userSubChoice !='R');
			}
			// Parse "Videostream" file (JSON file)
			else if(userChoice == 'V'){
				do {
					displaySubMenu(videoJsonDirectory, videoJsonType);
					userSubChoice = getChoice(userSubChoice);

					if(userSubChoice == 'S'){
						listDirectoryVideostreamJson();
					}
					else if(userSubChoice == 'E'){
						std::string userVideoJsonInput {};
						std::cout << "Enter 'Video' file name: ";
						std::cin >> userVideoJsonInput;
						JsonFile videostreamFile ("src/videostreamJsonFiles/" + userVideoJsonInput);
						videostreamFile.jsonReaderStream();
					}
					// Return to main menu
					else if(userSubChoice == 'R'){
						std::cout << "\nTo Main Menu...\n" << std::endl;
					}
					// Illegal choices
					else
						std::cout << "Unknown selection, please try again\n" << std::endl;
					}while(userSubChoice !='R');
			}
			// Parse "Notes" file (JSON file)
			else if(userChoice == 'N'){
				do {
					displaySubMenu(notesJsonDirectory, notesJsonType);
					userSubChoice = getChoice(userSubChoice);

					if(userSubChoice == 'S'){
						listDirectoryNotesJson();
					}
					else if(userSubChoice == 'E'){
						std::string userNotesJsonInput {};
						std::cout << "Enter 'Notes' file name: ";
						std::cin >> userNotesJsonInput;
						JsonFile notesFile ("src/notesJsonFiles/" + userNotesJsonInput);
						notesFile.jsonReaderNotes();
					}
					// Return to main menu
					else if(userSubChoice == 'R'){
						std::cout << "\nTo Main Menu...\n" << std::endl;
					}
					// Illegal choices
					else
						std::cout << "Unknown selection, please try again\n" << std::endl;
					}while(userSubChoice !='R');
			}
			// Show "notesJsonFiles" directory
			else if(userChoice == 'A'){
				listDirectoryNotesJson();
			}
			// Message of goodbye
			else if(userChoice == 'Q'){
				std::cout << "Goodbye" << std::endl;
			}
			// Illegal choices
			else
				std::cout << "Unknown selection, please try again\n" << std::endl;
			}while(userChoice !='Q');
		}
		else if(userLanguageChoice == 'D'){
			do {
				// Menu List
				displayMenuDe();

				// Obtain the user's choice as an upper case character
				userChoice = getChoice(userChoice);

				// Read text file
				if(userChoice == 'T'){
					do {
					displaySubMenuDe(textDirectory, textType);
					userSubChoice = getChoice(userSubChoice);

						if(userSubChoice == 'S'){
							listDirectoryNotesText();
						}
						else if(userSubChoice == 'E'){
							std::string userTextFileInput {};
							std::cout << "Textdateiname eingeben: ";
							std::cin >> userTextFileInput;
							TextFile notesTextFile ("src/notesTextFiles/" + userTextFileInput);
							notesTextFile.textReader();
						}
						// Return to main menu
						else if(userSubChoice == 'R'){
							std::cout << "\nzum Hauptmenü...\n" << std::endl;
						}
						// Illegal choices
						else
							std::cout << "Unbekannte Auswahl, bitte versuchen Sie es nochmal\n" << std::endl;
					}while(userSubChoice !='R');
				}
				// Parse "Videostream" file (JSON file)
				else if(userChoice == 'V'){
					do {
						displaySubMenuDe(videoJsonDirectory, videoJsonType);
						userSubChoice = getChoice(userSubChoice);

						if(userSubChoice == 'S'){
							listDirectoryVideostreamJson();
						}
						else if(userSubChoice == 'E'){
							std::string userVideoJsonInput {};
							std::cout << "'Video'-Dateiname eingeben: ";
							std::cin >> userVideoJsonInput;
							JsonFile videostreamFile ("src/videostreamJsonFiles/" + userVideoJsonInput);
							videostreamFile.jsonReaderStream();
						}
						// Return to main menu
						else if(userSubChoice == 'R'){
							std::cout << "\nzum Hauptmenü...\n" << std::endl;
						}
						// Illegal choices
						else
							std::cout << "Unbekannte Auswahl, bitte versuchen Sie es nochmal\n" << std::endl;
					}while(userSubChoice !='R');
				}
				// Parse "Notes" file (JSON file)
				else if(userChoice == 'N'){
					do {
						displaySubMenuDe(notesJsonDirectory, notesJsonType);
						userSubChoice = getChoice(userSubChoice);
							if(userSubChoice == 'S'){
								listDirectoryNotesJson();
							}
							else if(userSubChoice == 'E'){
								std::string userNotesJsonInput {};
								std::cout << "'Notes'-Dateiname eingeben: ";
								std::cin >> userNotesJsonInput;
								JsonFile notesFile ("src/notesJsonFiles/" + userNotesJsonInput);
								notesFile.jsonReaderNotes();
							}
							// Return to main menu
							else if(userSubChoice == 'R'){
								std::cout << "\nzum Hauptmenü...\n" << std::endl;
							}
							// Illegal choices
							else
								std::cout << "Unbekannte Auswahl, bitte versuchen Sie es nochmal\n" << std::endl;
					}while(userSubChoice !='R');
				}
				// Compare three files: Notes-JSON, Videostream-JSON and Simulator-txt
				else if(userChoice == 'A'){
					std::string videoNumber {};
					std::string userJsonNotes {};
					std::string userJsonVideostream {};
					std::string userTextSim {};

					std::cout << "'Videostream'-Nummer eingeben: ";
					std::cin >> videoNumber;

					userJsonVideostream = videoNumber + "short.json";
					userJsonNotes = "video" + videoNumber + ".json";
					userTextSim = videoNumber + "sim.txt";

					JsonFile jsonComp ("src/videostreamJsonFiles/" + userJsonVideostream, "src/notesJsonFiles/" +userJsonNotes, "src/notesTextFiles/" + userTextSim);
					jsonComp.jsonCompare();
				}
				// Message of goodbye
				else if(userChoice == 'Q'){
					std::cout << "Auf Wiedersehen" << std::endl;
				}
				// Illegal choices
				else
					std::cout << "Unbekannte Auswahl, bitte versuchen Sie es nochmal\n" << std::endl;
			}while(userChoice !='Q');
		}
		else if(userLanguageChoice == 'X'){
			std::cout << "Goodbye / Auf Wiedersehen" << std::endl;
		}
		else
			std::cout << "Unknown selection, please try again\n" << std::endl;
	}while(userLanguageChoice !='X' && userChoice !='Q');
}
