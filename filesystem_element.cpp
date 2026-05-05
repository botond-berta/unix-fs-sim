#include "filesystem_element.h"

FileSystemElement::FileSystemElement() : name(), parent(nullptr) {}

FileSystemElement::FileSystemElement(const String& name, Directory* parent) : name(name), parent(parent) {}

FileSystemElement::~FileSystemElement() {}

const String& FileSystemElement::getName() const {
    return name;
}

const Directory* FileSystemElement::getParent() const {
    return parent;
}

void FileSystemElement::setName(const String& n) {
    name = n;
}

