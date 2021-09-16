#include "File.h"

File::File(const std::string &fileName)
:fileName{fileName}{}

File::File(const std::string &jsonVideostream, const std::string &jsonNotes, const std::string &fileName)
:jsonVideostream{jsonVideostream}, jsonNotes{jsonNotes}, fileName{fileName}{}

File::~File() {
}

