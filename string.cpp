#include "string.h"

String::String() : pData(nullptr), len(0) {}

String::String(const char* s) {
    len = 0;
    const char* s_ither = s;
    while (*s_ither != '\0') {
        len++;
        s_ither++;
    }
    pData = new char[len+1];
    for (int i = 0; i < len; i++)
        pData[i] = s[i];
    pData[len] = '\0';
}

String::String(const String& str) {
    len = str.len;
    pData = new char[len];
    for (int i = 0; i < len; i++) 
        pData[i] = str.pData[i];
}

String::~String() {
    delete[] pData;
}

String& String::operator=(const String& rhs_str) {
    if (this->pData == rhs_str.pData) return *this;
    delete[] pData;
    len = rhs_str.len;
    pData = new char[len];
    for (int i = 0; i < len; i++)
        pData[i] = rhs_str.pData[i];
    return *this;
}

const char* String::getCstr() const {
    return pData;
}

const int String::getLen() const {
    return len;
}

char& String::operator[](int idx) {
    return pData[idx];
}

char String::operator[](int idx) const {
    return pData[idx];
}