#ifndef AUTOSIMULATORUTIL_H_
#define AUTOSIMULATORUTIL_H_
#include <string>

std::string addYearAdjustHour(std::string str, const std::string &year);
void convertDateTime(std::string str);
void convertDateTime2(std::string str);
int convSeqStrIntoInt(std::string word);
void displayLanguageMenu();
void displayMenu();
void displaySubMenu(std::string directoryName, std::string dataType);
void displayLanguageMenuDe();
void displayMenuDe();
void displaySubMenuDe(std::string directoryName, std::string dataType);
char getChoice(char userChoice);
void listDirectoryNotesJson();
void listDirectoryNotesText();
void listDirectoryVideostreamJson();
void printTimeNow();


#endif /* AUTOSIMULATORUTIL_H_ */
