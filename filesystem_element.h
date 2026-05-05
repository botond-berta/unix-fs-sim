#ifndef FILESYSTEM_ELEMENT_H
#define FILESYSTEM_ELEMENT_H

#include <iostream>
#include "string.h"

class Directory;

class FileSystemElement {
    String name;
    Directory* parent;
public:
    FileSystemElement();
    FileSystemElement(const String& name, Directory* parent);
    virtual ~FileSystemElement();
    const String& getName() const;
    const Directory* getParent() const;
    void setName(const String& n);
    virtual void print() = 0;
    // virtual void serialize(std::ostream& os) const = 0;
    // virtual void deserialize(std::istream& is) = 0;
};

#endif