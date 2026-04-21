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
};

#endif STRING_H