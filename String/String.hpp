#ifndef STRING_HPP_SENTRY
#define STRING_HPP_SENTRY

class String {
    char *str;
    int len;

public:
    String() : str(0), len(0) {}
    String(const char *);
    String(const String&);
    ~String() { if (str) delete[] str; }

    int GetLen() { return len; }

    const char* GetStr() const { return str; }

    char& operator[](int idx) { return str[idx]; }

private:
    const String& operator=(const char*);
};

#endif