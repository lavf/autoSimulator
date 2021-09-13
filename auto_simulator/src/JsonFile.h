#ifndef JSONFILE_H_
#define JSONFILE_H_

#include <string>

class JsonFile {
private:
	std::string jsonFileName;
	std::string jsonVideostream;
	std::string jsonNotes;
	std::string textFileName;
public:
	JsonFile(const std::string &jsonFileName);
	JsonFile(const std::string &jsonVideostream, const std::string &jsonNotes, const std::string &textFileName);
	virtual ~JsonFile();
	void jsonReaderNotes();
	void jsonReaderStream();
	void jsonCompare();
};

#endif /* JSONFILE_H_ */
