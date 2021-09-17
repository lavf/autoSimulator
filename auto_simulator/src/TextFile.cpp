#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include "TextFile.h"

TextFile::TextFile(const std::string &fileName)
 :File{fileName}{}

TextFile::~TextFile() {
}

void TextFile::printHeader(){
	// std::cout << "123456789012345678901234567890" << std::endl;
	std::cout << "////////////////////////////////////////////////////\n" << std::endl;

	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << std::setw(20) << std::left << "Session"
			  << std::setw(20) << std::left << "Sequence Number"
			  << std::setw(12) << std::right << "Notice"
			  << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
}

void TextFile::printHeaderDe(){
	// std::cout << "123456789012345678901234567890" << std::endl;
	std::cout << "////////////////////////////////////////////////////\n" << std::endl;

	std::cout << "----------------------------------------------------" << std::endl;
	std::cout << std::setw(20) << std::left << "Sitzung"
			  << std::setw(20) << std::left << "Sequenznummer"
			  << std::setw(12) << std::right << "Anzeige"
			  << std::endl;
	std::cout << "----------------------------------------------------" << std::endl;
}

void TextFile::textReader(){

	std::ifstream file(fileName, std::ios::in);
	std::string session;
	std::string sessionNr;
	std::string seqNrLabel;
	std::string seqNr;
	std::string notification;


	if (file.is_open())
	{

		while(file >> session >> sessionNr >> seqNrLabel >> seqNr >> notification)
		{
			seqNr.erase(seqNr.size()-1);
			sessionNr.erase(sessionNr.size()-1);
			std::cout << std::setw(20) << std::left << sessionNr
					  << std::setw(20) << std::left << seqNr
					  << std::setw(12) << std::right << ((notification == "End_Critical") ?  "End Critical": ((notification == "End_Alarm") ? "End Alarm": notification)) << std::endl;


		}
//		std::getline(file, line);
//				while(file)
//				{
//					std::cout << line << std::endl;
//					std::getline(file, line);
//				}
		std::cout << "\n////////////////////////////////////////////////////\n" << std::endl;
		file.close();
    } else {
    	std::cout << "ERROR!\n";
    	std::cout << "\n////////////////////////////////////////////////////\n" << std::endl;
    }

}


