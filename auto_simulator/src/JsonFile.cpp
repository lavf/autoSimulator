#include <iostream>
#include <fstream>
#include <string>
#include "JsonFile.h"
#include "autoSimulatorUtil.h"
#include "single_include/nlohmann/json.hpp"

using json = nlohmann::json;

JsonFile::JsonFile(const std::string &jsonFileName)
: jsonFileName {jsonFileName} {}

JsonFile::~JsonFile() {
}


void JsonFile::jsonReaderNotes(){
	std::ifstream file(jsonFileName);
	json j;
	file >> j;

	std::cout << "========================================\n" << std::endl;
	std::cout << "Session Number: " << j["session"] << '\n';
	std::cout << "Date: " << j["date"] << '\n';

	for(json& o : j["status"]) {
        //json& gi = o["time"];
        std::cout << "Nr.:" << o["notificationnr"] << " ";
        std::cout << "Time:" << o["time"] << " ";
        //std::cout << "Time: " << gi["hour"] << ":" << gi["minutes"] << ":" << gi["seconds"] << " ";
        //std::cout << "Frame: " << o["frame"] << " ";
        //std::cout << "Sequence: " << o["sequence"] << " ";
        //std::cout << "Frame: " << o["frame"] << " ";
        std::cout << "Notice: " << o["result"] << "\n";
	}
	std::cout << std::endl;
	std::cout << "========================================\n" << std::endl;
}

void JsonFile::jsonReaderStream(){

	std::ifstream file(jsonFileName);
	json j;
	file >> j;
	size_t lineNumber {0};
	int countFrames {0};

	//std::cout << j.size() << std::endl;

	std::cout << "========================================\n" << std::endl;

	for(auto o : j["test"]){
		std::cout << "Session or name of the video: " << o["session"] << std::endl;
		std::cout << "Sequence Number: " << o["seqnr"] << std::endl;
		std::cout << "Date and time string from JSON : " << o["date"] << std::endl;
//		convertDateTime2(o["date"]);
		std::string oldDate = o["date"];
//		// The following statement shows the date with hour changed due to time zone
//		std::cout << "Date with year: " << addYearAdjustHour(oldDate,"2021") << std::endl;
		convertDateTime(addYearAdjustHour(oldDate,"2021"));
		std::cout << "JSON parsed at: ";
		printTimeNow();

		std::cout << "---------------------------------" << std::endl;
		int frameID {0};


		for(auto obj : o["content"]["disp"]){
			if (obj["n"]== "Frame ID"){
				std::cout << "Frame ID: " << obj["v"]<< std::endl;
				frameID = obj["v"];
				++countFrames;
			} //else
				//std::cout << "System Time: " << obj["v"]<< std::endl;
		}

		std::cout << "*********************************" << std::endl;
		lineNumber++;
	}


	std::cout << "The JSON file has " << lineNumber << " lines" << std::endl;
	std::cout << "and has: " << countFrames << " Frames " << std::endl;
	std::cout << "========================================\n" << std::endl;
}
