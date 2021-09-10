#ifndef JSONFILE_H_
#define JSONFILE_H_

#include <string>

class JsonFile {
private:
	std::string jsonFileName;
public:
	JsonFile(const std::string &jsonFileName);
	virtual ~JsonFile();
	void jsonReaderNotes();
	void jsonReaderStream();
};

#endif /* JSONFILE_H_ */
