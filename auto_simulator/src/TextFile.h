#ifndef TEXTFILE_H_
#define TEXTFILE_H_

#include <string>

class TextFile {
private:
	std::string textFileName;
public:
	TextFile(const std::string &textFileName);
	virtual ~TextFile();
	void textReader();

};

#endif /* TEXTFILE_H_ */
