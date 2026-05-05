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
    bool operator==(const String& rhs_str) const {
        if (len != rhs_str.len) return false;
        for (int i = 0; i < len; i++) {
            if (pData[i] != rhs_str.pData[i]) return false;
        }
        return true;
    }
    const char* getCstr() const;
    const int getLen() const;
    char& operator[](int idx);
    char operator[](int idx) const;
};

#endif