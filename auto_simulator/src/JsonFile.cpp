#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include "JsonFile.h"
#include "autoSimulatorUtil.h"
#include "single_include/nlohmann/json.hpp"

using json = nlohmann::json;

JsonFile::JsonFile(const std::string &fileName)
: File{fileName} {}

JsonFile::JsonFile(const std::string &jsonVideostream, const std::string &jsonNotes, const std::string &fileName)
: File{jsonVideostream,jsonNotes,fileName}{}

JsonFile::~JsonFile() {
}


void JsonFile::jsonReaderNotes(){
	std::ifstream file(fileName);
	json j;
	file >> j;

	std::cout << "==================================================\n" << std::endl;
	std::cout << "Session Number: " << j["filename"] << '\n';
	std::cout << "Date: " << j["date"] << '\n';

	for(json& o : j["status"]) {
        //json& gi = o["time"];
        std::cout << "Nr.:" << o["notificationnr"] << " ";
        std::cout << "Time:" << o["time"] << " ";
        //std::cout << "Time: " << gi["hour"] << ":" << gi["minutes"] << ":" << gi["seconds"] << " ";
        std::cout << "Sequence: " << o["seqnr"] << " ";
        std::cout << "Notice: " << o["result"] << "\n";
	}

	file.close();
	std::cout << std::endl;
	std::cout << "==================================================\n" << std::endl;
}

void JsonFile::jsonReaderStream(){

	std::ifstream file(fileName);
	json j;
	file >> j;
	size_t lineNumber {0};
	int countFrames {0};
	std::cout << "==================================================\n" << std::endl;

	for(auto o : j["videostream"]){
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

		std::cout << "---------------------------------------------------" << std::endl;

		for(auto obj : o["content"]["disp"]){
			if (obj["n"]== "Frame ID"){
				std::cout << "Frame ID: " << obj["v"]<< std::endl;
				++countFrames;
			} //else
				//std::cout << "System Time: " << obj["v"]<< std::endl;
		}

		std::cout << "***************************************************" << std::endl;
		lineNumber++;
	}

	std::cout << "The JSON file has " << lineNumber << " lines" << std::endl;
	std::cout << "and has: " << countFrames << " Frames " << std::endl;
	file.close();
	std::cout << "===================================================\n" << std::endl;
}

void JsonFile::jsonReaderStreamDe(){

	std::ifstream file(fileName);
	json j;
	file >> j;
	size_t lineNumber {0};
	int countFrames {0};
	std::cout << "==================================================\n" << std::endl;

	for(auto o : j["videostream"]){
		std::cout << "Session oder Name des Videos: " << o["session"] << std::endl;
		std::cout << "Sequenznummer: " << o["seqnr"] << std::endl;
		std::string oldDate = o["date"];
		convertDateTimeDe(addYearAdjustHour(oldDate,"2021"));
		std::cout << "JSON geparst am: ";
		printTimeNow();

		std::cout << "---------------------------------------------------" << std::endl;

		for(auto obj : o["content"]["disp"]){
			if (obj["n"]== "Frame-ID"){
				std::cout << "Rahmen-ID: " << obj["v"]<< std::endl;
				++countFrames;
			} //else
				//std::cout << "System Time: " << obj["v"]<< std::endl;
		}

		std::cout << "***************************************************" << std::endl;
		lineNumber++;
	}

	std::cout << "Die JSON-Datei hat " << lineNumber << " Zeilen" << std::endl;
	std::cout << "und hat: " << countFrames << " Rahmen " << std::endl;
	file.close();
	std::cout << "===================================================\n" << std::endl;
}

void JsonFile::jsonCompare(){
	std::ifstream file(jsonVideostream);
	json jvs;
	file >> jvs;

	std::ifstream file2(jsonNotes);
	json jno;
	file2 >> jno;

	std::ifstream file1(fileName, std::ios::in);
	std::string session;
	std::string sessionNr;
	std::string sequence;
	std::string sequenceNr;
	std::string notificationSimulator;
	std::map <uint32_t, std::string> mapa {};


	while(file1 >> session >> sessionNr >> sequence >> sequenceNr >> notificationSimulator){
		int temp1 = convSeqStrIntoInt(sequenceNr);
		mapa.insert(std::make_pair(temp1, notificationSimulator));
	}

//	// Show map content
//	for (auto pair: mapa) {
//		std::cout << pair.first
//				  << "[";
//		for (auto i: pair.second)
//			std::cout << i;
//		std::cout << "]" << std::endl;
//	}
//	std::cout << std::endl;

	for(auto o : jvs["videostream"]){
		for(auto obj : jno["status"]){
			if(obj["seqnr"] == o["seqnr"]){
				std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
				std::cout << "Sequence: " << obj["seqnr"] << std::endl;
				std::string oldDate = o["date"];
				convertDateTime(addYearAdjustHour(oldDate,"2021"));
				std::cout << "Analysis Notice: " << obj["result"] << std::endl;
				if(mapa.find(o["seqnr"]) != mapa.end())
					std::cout << "Simulator Notice: " << mapa.at(o["seqnr"]) << std::endl;
			}
		}
	}

	file2.close();
	file1.close();
	file.close();
	std::cout << "===================================================\n" << std::endl;
}

void JsonFile::jsonCompareDe(){
	std::ifstream file(jsonVideostream);
	json jvs;
	file >> jvs;

	std::ifstream file2(jsonNotes);
	json jno;
	file2 >> jno;

	std::ifstream file1(fileName, std::ios::in);
	std::string session;
	std::string sessionNr;
	std::string sequence;
	std::string sequenceNr;
	std::string notificationSimulator;
	std::map <int, std::string> mapa {};


	while(file1 >> session >> sessionNr >> sequence >> sequenceNr >> notificationSimulator){
		int temp1 = convSeqStrIntoInt(sequenceNr);
		mapa.insert(std::make_pair(temp1, notificationSimulator));
	}

	for(auto o : jvs["videostream"]){
		for(auto obj : jno["status"]){
			if(obj["seqnr"] == o["seqnr"]){
				std::cout << "~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" << std::endl;
				std::cout << "Sequenz: " << obj["seqnr"] << std::endl;
				std::string oldDate = o["date"];
				convertDateTimeDe(addYearAdjustHour(oldDate,"2021"));
				std::cout << "Analyse-Anzeige: " << obj["result"] << std::endl;
				if(mapa.find(o["seqnr"]) != mapa.end())
					std::cout << "Simulator-Anzeige: " << mapa.at(o["seqnr"]) << std::endl;
			}
		}
	}

	file2.close();
	file1.close();
	file.close();
	std::cout << "===================================================\n" << std::endl;
}
