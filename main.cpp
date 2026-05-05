#include <iostream>
#include "directory.h"
#include "file.h"
#include "link.h"
#include "string.h"

int main() {
    std::cout << "Filesystem Simulator Demo" << std::endl;

    // Create root directory
    Directory* root = new Directory("root", nullptr);
    std::cout << "Created root directory" << std::endl;

    // Add subdirectory
    Directory* sub = new Directory("subdir", root);
    root->addElement(sub);
    std::cout << "Added subdirectory" << std::endl;

    // Add file
    File* f = new File("file1", root);
    root->addElement(f);
    std::cout << "Added file" << std::endl;

    // Add link
    Link* l = new Link("link1", root, sub);
    root->addElement(l);
    std::cout << "Added link" << std::endl;

    // Print the structure
    std::cout << "Filesystem structure:" << std::endl;
    root->print();

    // Cleanup
    delete root;
    std::cout << "Demo complete" << std::endl;
    return 0;
}