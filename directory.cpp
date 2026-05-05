#include "directory.h"
#include <iostream>

Directory::Directory() : FileSystemElement() {}

Directory::Directory(const String& name, Directory* parent) : FileSystemElement(name, parent) {}

Directory::~Directory() {
    for (int i = 0; i < elements.getSize(); ++i) {
        delete elements[i];
    }
}

void Directory::addElement(FileSystemElement* element) {
    elements.push_back(element);
}

void Directory::removeElement(const String& name) {
    for (int i = 0; i < elements.getSize(); ++i) {
        if (elements[i]->getName() == name) {
            delete elements[i];
            elements[i] = elements[elements.getSize() - 1];
            elements.pop_back();
            return;
        }
    }
}

const Vector<FileSystemElement*>& Directory::getElements() const {
    return elements;
}

void Directory::print() {
    std::cout << "Directory: " << getName().getCstr() << std::endl;
    for (int i = 0; i < elements.getSize(); ++i) {
        std::cout << "  ";
        elements[i]->print();
    }
}

// void Directory::serialize(std::ostream& os) const { }
// void Directory::deserialize(std::istream& is) { }

