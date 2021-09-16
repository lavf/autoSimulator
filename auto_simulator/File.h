#ifndef FILE_H_
#define FILE_H_

#include <string>

class File {
private:
	static constexpr const char *defFileName1 = "src/notesTextFiles/11simulator.txt";
protected:
	std::string fileName;
	std::string jsonVideostream;
	std::string jsonNotes;
public:
	File(const std::string &fileName = defFileName1);
	File(const std::string &jsonVideostream, const std::string &jsonNotes, const std::string &fileName = defFileName1);
	virtual ~File();
};

#endif /* FILE_H_ */
