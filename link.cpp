#include "link.h"
#include "directory.h"
#include <iostream>

Link::Link() : FileSystemElement(), target(nullptr) {}

Link::Link(const String& name, Directory* parent, Directory* target) : FileSystemElement(name, parent), target(target) {}

Link::~Link() {}

const Directory* Link::getTarget() const {
    return target;
}

void Link::print() {
    std::cout << "Link: " << getName().getCstr() << " -> ";
    if (target) {
        std::cout << target->getName().getCstr();
    } else {
        std::cout << "(null)";
    }
    std::cout << std::endl;
}

// void Link::serialize(std::ostream& os) const { }
// void Link::deserialize(std::istream& is) { }