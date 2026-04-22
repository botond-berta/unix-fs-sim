#ifndef STRING_H
#define STRING_H

class String {
    char* pData;
    int len;
public:
    String();
    String(const char* s);
    String(const String& str);
    ~String();
    String& operator=(const String& rhs_str);
    const char* getCstr() const;
    const int getLen() const;
    char& operator[](int idx);
    char operator[](int idx) const;
};

#endif