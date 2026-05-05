#ifndef FILE_H
#define FILE_H

#include "filesystem_element.h"

class File : public FileSystemElement {
public:
    File();
    File(const String& name, Directory* parent);
    ~File();
    void print() override;
    // void serialize(std::ostream& os) const override;
    // void deserialize(std::istream& is) override;
};

#endif