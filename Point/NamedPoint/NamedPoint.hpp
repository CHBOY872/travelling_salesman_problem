#ifndef NAMEDPOINT_HPP_SENTRY
#define NAMEDPOINT_HPP_SENTRY

#include "../Point/Point.hpp"
#include "../../String/String.hpp"

class NamedPoint : public Point {
    String header;

public:
    NamedPoint(const char *_header, float _x, float _y)
        : Point(_x, _y), header(_header) {}
    NamedPoint(const NamedPoint& a) : Point(a), header(a.header) {}
    
    virtual ~NamedPoint() {}

    const char* GetHeader() const { return header.GetStr(); }
    
    void SetHeader(String* _header) { header = *_header; }

    friend NamedPoint operator+(const NamedPoint& a, const NamedPoint& b);
    friend NamedPoint operator-(const NamedPoint& a, const NamedPoint& b);

    virtual const NamedPoint& operator=(const NamedPoint& a);

private:
    NamedPoint(float _x, float _y) : Point(_x, _y) {}
    NamedPoint(const Point& a) : Point(a), header() {}
};

NamedPoint operator+(const NamedPoint& a, const NamedPoint& b);
NamedPoint operator-(const NamedPoint& a, const NamedPoint& b);

#endif