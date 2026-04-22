#include <iostream>
#include "string.h"

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

int main() {
    testString();
    return 0;
}