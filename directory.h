#ifndef DIRECTORY_H
#define DIRECTORY_H

#include "filesystem_element.h"
#include "vector.h"

class Directory : public FileSystemElement {
    Vector<FileSystemElement*> elements;
public:
    Directory();
    Directory(const String& name, Directory* parent);
    ~Directory();
    void addElement(FileSystemElement* element);
    void removeElement(const String& name);
    const Vector<FileSystemElement*>& getElements() const;
    void print() override;
    // void serialize(std::ostream& os) const override;
    // void deserialize(std::istream& is) override;
};

#endif