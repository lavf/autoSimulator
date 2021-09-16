#ifndef JSONFILE_H_
#define JSONFILE_H_

#include "File.h"
#include <string>

class JsonFile : public File {
public:
	JsonFile(const std::string &fileName);
	JsonFile(const std::string &jsonVideostream, const std::string &jsonNotes, const std::string &fileName);
	virtual ~JsonFile();
	void jsonReaderNotes();
	void jsonReaderStream();
	void jsonReaderStreamDe();
	void jsonCompare();
	void jsonCompareDe();
};

#endif /* JSONFILE_H_ */
