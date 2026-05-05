#include "file.h"
#include <iostream>

File::File() : FileSystemElement() {}

File::File(const String& name, Directory* parent) : FileSystemElement(name, parent) {}

File::~File() {}

void File::print() {
    std::cout << "File: " << getName().getCstr() << std::endl;
}

// void File::serialize(std::ostream& os) const { }
// void File::deserialize(std::istream& is) { }