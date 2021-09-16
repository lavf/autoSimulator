#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"

TextFile::TextFile(const std::string &fileName)
 :File{fileName}{}

TextFile::~TextFile() {
}

void TextFile::textReader(){

	std::ifstream file(fileName, std::ios::in);
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
		std::cout << "\n////////////////////////////////////////////////////\n" << std::endl;
		file.close();
    } else {
    	std::cout << "ERROR!\n";
    	std::cout << "\n////////////////////////////////////////////////////\n" << std::endl;
    }

}
