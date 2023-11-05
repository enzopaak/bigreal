#ifndef BIGREAL_H
#define BIGREAL_H

#include <string>

class BigReal {
public:
    BigReal();
    BigReal(const std::string& realNumber);
    BigReal(const BigReal& other);

    BigReal& operator=(const BigReal& other);

    BigReal operator+(const BigReal& other) const;
    BigReal operator-(const BigReal& other) const;

    std::string toString() const;

private:
    // Private data members to represent the real number components
    int wholePart;
    int fractionalPart;

    // Helper function to parse a real number string
    void parseRealNumber(const std::string& realNumber);
};

#endif
