#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"

TextFile::TextFile(const std::string &textFileName)
 :textFileName{textFileName}{}

TextFile::~TextFile() {
}

void TextFile::textReader(){

	std::ifstream file(textFileName, std::ios::in);
	std::string line;

	std::cout << "////////////////////////////////////////////////////\n" << std::endl;

	if (file.is_open())
	{
		std::getline(file, line);
		while(file)
		{
			std::cout << line << std::endl;
			std::getline(file, line);
		}
		file.close();
    } else
    	std::cout << "ERROR!\n";

	std::cout << "\n////////////////////////////////////////////////////\n" << std::endl;

}
