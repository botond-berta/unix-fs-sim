#include <iostream>

#include "string.h"
#include "vector.h"
#include "filesystem_element.h"
#include "directory.h"
#include "file.h"
#include "link.h"

void testString() {
    std::cout << "--- STRING TEST ---" << std::endl;
    
    // 1. Test: Default ctor
    std::cout << "Test case #1 - Default Constructor" << std::endl;
    String s1;
    std::cout << "Empty String Test: ";
    if (s1.getLen() == 0 && s1.getCstr() == nullptr) {
        std::cout << "OK" << std::endl;
    } else {
        if (s1.getLen() != 0) {
            std::cout << "FAILED (s1.len() != 0)" << std::endl;
        } else if (s1.getCstr() != nullptr) {
            std::cout << "FAILED (s1.getCstr() != nullptr)" << std::endl;
        } else {
            std::cout << "FAILED" << std::endl;
        }
    }
    std::cout << std::endl;

    // 2. Test: C String ctor
    std::cout << "Test case #2 - C String Constructor" << std::endl;
    std::cout << "C String Test: ";
    const char* cstr = "Test";
    String s2(cstr);
    if (s2.getLen() == 4 && s2.getCstr() != nullptr && s2[4] == '\0') {
        int mismatch = 0;
        for (int i = 0; i < 4; i++) {
            if (s2[i] != cstr[i]) {
                std::cout << "FAILED (content mismatch)" << std::endl;
                mismatch = 1;
                break;
            }
        }
        if (mismatch == 0) {
            std::cout << "OK" << std::endl;
        }
    } else {
        std::cout << "FAILED" << std::endl;
    }
    std::cout << std::endl;
}

void testVector() {
    std::cout << "--- VECTOR TEST ---" << std::endl;
    
    // 1. Test: Default ctor
    std::cout << "Test case #1 - Default Constructor" << std::endl;
    Vector<int> v1;
    std::cout << "Empty Vector Test: ";
    if (v1.getSize() == 0 && v1.getCapacity() == 0) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "FAILED" << std::endl;
    }
    std::cout << std::endl;

    // 2. Test: Push back
    std::cout << "Test case #2 - Push Back" << std::endl;
    v1.push_back(10);
    v1.push_back(20);
    v1.push_back(30);
    std::cout << "Push Back Test: ";
    if (v1.getSize() == 3 && v1[0] == 10 && v1[1] == 20 && v1[2] == 30) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "FAILED" << std::endl;
    }
    std::cout << std::endl;

    // 3. Test: Copy constructor
    std::cout << "Test case #3 - Copy Constructor" << std::endl;
    Vector<int> v2(v1);
    std::cout << "Copy Constructor Test: ";
    if (v2.getSize() == 3 && v2[0] == 10 && v2[1] == 20 && v2[2] == 30) {
        std::cout << "OK" << std::endl;
    } else {
        std::cout << "FAILED" << std::endl;
    }
    std::cout << std::endl;
}

void testFilesystem() {
    std::cout << "--- FILESYSTEM TEST ---" << std::endl;

    // Create root
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

    // Print
    std::cout << "Printing structure:" << std::endl;
    root->print();

    // Cleanup
    delete root;
    std::cout << "Cleanup done" << std::endl;
}

int main() {
    testString();
    testVector();
    testFilesystem();
    return 0;
}