#ifndef TEXTFILE_H_
#define TEXTFILE_H_

#include "File.h"
#include <string>

class TextFile: public File {
public:
	TextFile(const std::string &fileName);
	virtual ~TextFile();
	void textReader();
};

#endif /* TEXTFILE_H_ */
