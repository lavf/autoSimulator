#include "autoSimulatorUtil.h"
#include <iostream>
#include <chrono>
#include <ctime>
#include <string>
#include <sstream>
#include <iomanip>

// Adjust the hour to Central European Time and include the year to date string
std::string addYearAdjustHour(std::string str, const std::string &year ){
	// Changing the hour digit
	std::string hour = str.substr(0,2);
	std::string strChangedHr;
	if(hour == "00"){
		strChangedHr = "23";
	}else if(hour == "01" || hour == "02" || hour == "03" || hour == "04" ||
			hour == "05" || hour == "06" || hour == "07" || hour == "08" || hour == "09"){
		std::string temp = hour.substr(1,1);
		int changedHr = stoi(temp) - 1;
		strChangedHr = "0" + std::to_string(changedHr);
	}else if(hour == "10"){
			strChangedHr = "09";
	}else{
		int changedHr = stoi(hour) - 1;
		strChangedHr = std::to_string(changedHr);
	}
	str.replace(str.begin(),str.begin()+2,strChangedHr);
	str += year;
	return str;
}

// Convert date string into a datetime object
void convertDateTime(std::string str){
	std::tm tm = {};
	std::stringstream ss(str);
	ss >> std::get_time(&tm, "%H:%M:%S %d.%m.%Y");
	std::chrono::system_clock::from_time_t(std::mktime(&tm));
	std::cout << "Time: " << std::put_time(&tm, "%H:%M:%S") << std::endl;
	std::cout << "Date: " << std::put_time(&tm, "%d %b %Y") << std::endl;
}

void convertDateTimeDe(std::string str){
	std::tm tm = {};
	std::stringstream ss(str);
	ss >> std::get_time(&tm, "%H:%M:%S %d.%m.%Y");
	std::chrono::system_clock::from_time_t(std::mktime(&tm));
	std::cout << "Uhrzeit: " << std::put_time(&tm, "%H:%M:%S") << std::endl;
	std::cout << "Datum: " << std::put_time(&tm, "%d %b %Y") << std::endl;
}

// Same as convertDateTime but with different format
void convertDateTime2(std::string str){
	std::tm tm = {};
	std::stringstream ss(str);
	ss >> std::get_time(&tm, "%H:%M:%S %d.%m.");
	std::chrono::system_clock::from_time_t(std::mktime(&tm));
	std::cout << "Time: " << std::put_time(&tm, "%H:%M:%S") << std::endl;
	std::cout << "Date: " << std::put_time(&tm, "%d %b") << std::endl;
}

int convSeqStrIntoInt(std::string word){
	word.erase(word.size()-1);
	return std::stoi(word);
}

void displayLanguageMenu(){
	std::cout << "E - English" << std::endl;
	std::cout << "D - Deutsch" << std::endl;
	std::cout << "X - Quit" << std::endl;
	std::cout << "\nLanguage / Sprache: " << std::endl;
}

// Display the options in the terminal
void displayMenu(){
	std::cout << "T - Display content of text file" << std::endl;
	std::cout << "V - Read 'Videostream' file (JSON file)" << std::endl;
	std::cout << "N - Read 'Notes' file (JSON file)" << std::endl;
	std::cout << "A - Compare files: results from simulator, analysis and videostream" << std::endl;
	std::cout << "Q - Quit" << std::endl;
	std::cout << "\nEnter your choice: " << std::endl;
}

void displaySubMenu(std::string directoryName, std::string dataType){
	std::cout << "S - Show files of '" << directoryName << "' directory" << std::endl;
	std::cout << "E - Enter '" << dataType  << "' file name" << std::endl;
	std::cout << "R - Return to main menu" << std::endl;
	std::cout << "\nEnter your choice: " << std::endl;
}

void displayMenuDe(){
	std::cout << "T - Textdatei einlesen" << std::endl;
	std::cout << "V - 'Videostream'-Datei (JSON-Datei) einlesen" << std::endl;
	std::cout << "N - 'Notes'-Datei (JSON-Datei) einlesen" << std::endl;
	std::cout << "A - Vergleich von Simulator-Ergebnis-, Analyse- und Videostream-Datei" << std::endl;
	std::cout << "Q - Beenden" << std::endl;
	std::cout << "\nGeben Sie Ihre Auswahl ein: " << std::endl;
}

void displaySubMenuDe(std::string directoryName, std::string dataType){
	std::cout << "S - Dateien im '"<< directoryName << "'-Verzeichnis anzeigen" << std::endl;
	std::cout << "E - '" << dataType << "'-Dateiname eingeben" << std::endl;
	std::cout << "R - Zum Hauptmenü zurückkehren" << std::endl;
	std::cout << "\nGeben Sie Ihre Auswahl ein: " << std::endl;
}

// User's choice is converted to upper case character
char getChoice(char userChoice){
	std::cin >> userChoice;
	return toupper(userChoice);
}

void listDirectoryNotesJson(){
	std::cout << "////////////////////////////////////////////////////" << std::endl;
	char command[50] = "ls src/notesJsonFiles";
	system(command);
	std::cout << "////////////////////////////////////////////////////\n" << std::endl;
}

void listDirectoryNotesText(){
	std::cout << "////////////////////////////////////////////////////" << std::endl;
	char command[50] = "ls src/notesTextFiles";
	system(command);
	std::cout << "////////////////////////////////////////////////////\n" << std::endl;
}

void listDirectoryVideostreamJson(){
	std::cout << "////////////////////////////////////////////////////" << std::endl;
	char command[50] = "ls src/videostreamJsonFiles";
	system(command);
	std::cout << "////////////////////////////////////////////////////\n" << std::endl;
}

void printTimeNow(){
	auto rightNow = std::chrono::system_clock::now();
	std::time_t timeNow = std::chrono::system_clock::to_time_t(rightNow);
    std::cout << std::ctime(&timeNow);
}
