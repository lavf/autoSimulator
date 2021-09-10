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
	int changedHr = stoi(hour) - 1;
	std::string strChangedHr = std::to_string(changedHr);
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

// Same as convertDateTime but with different format
void convertDateTime2(std::string str){
	std::tm tm = {};
	std::stringstream ss(str);
	ss >> std::get_time(&tm, "%H:%M:%S %d.%m.");
	std::chrono::system_clock::from_time_t(std::mktime(&tm));
	std::cout << "Time: " << std::put_time(&tm, "%H:%M:%S") << std::endl;
	std::cout << "Date: " << std::put_time(&tm, "%d %b") << std::endl;
}

// Display the options in the terminal
void displayMenu(){
	std::cout << "T - Display content of text file" << std::endl;
	std::cout << "V - Read 'Videostream' file (JSON file)" << std::endl;
	std::cout << "N - Read 'Notes' file (JSON file)" << std::endl;
	std::cout << "S - ------" << std::endl;
	std::cout << "L - ------" << std::endl;
	std::cout << "F - ------" << std::endl;
	std::cout << "Q - Quit" << std::endl;
	std::cout << "\nEnter your choice: " << std::endl;
}

void printTimeNow(){
	auto rightNow = std::chrono::system_clock::now();
	std::time_t timeNow = std::chrono::system_clock::to_time_t(rightNow);
    std::cout << "Time now: " << std::ctime(&timeNow);
}
