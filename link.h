#ifndef LINK_H
#define LINK_H

#include "filesystem_element.h"

class Link : public FileSystemElement {
    Directory* target;
public:
    Link();
    Link(const String& name, Directory* parent, Directory* target);
    ~Link() override;
    const Directory* getTarget() const;
    void print() override;
    // void serialize(std::ostream& os) const override;
    // void deserialize(std::istream& is) override;
};

#endif