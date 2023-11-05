#include "BigReal.h"
#include <sstream>

BigReal::BigReal() : wholePart(0), fractionalPart(0) {
    // Initialize your data members here.
}

BigReal::BigReal(const std::string& realNumber) {
    parseRealNumber(realNumber);
}

BigReal::BigReal(const BigReal& other) : wholePart(other.wholePart), fractionalPart(other.fractionalPart) {
    // Copy the data members from the other object.
}

BigReal& BigReal::operator=(const BigReal& other) {
    if (this != &other) {
        wholePart = other.wholePart;
        fractionalPart = other.fractionalPart;
    }
    return *this;
}

BigReal BigReal::operator+(const BigReal& other) const {
    BigReal result;
    result.wholePart = wholePart + other.wholePart;
    result.fractionalPart = fractionalPart + other.fractionalPart;

    // Adjust the whole part when the fractional part exceeds or equals 1,000,000
    if (result.fractionalPart >= 1000000) {
        result.wholePart += 1;
        result.fractionalPart -= 1000000;
    }

    return result;
}

BigReal BigReal::operator-(const BigReal& other) const {
    BigReal result;
    result.wholePart = wholePart - other.wholePart;
    result.fractionalPart = fractionalPart - other.fractionalPart;

    // Adjust the whole part and fractional part for borrowing
    while (result.fractionalPart < 0) {
        result.fractionalPart += 1000000;
        result.wholePart--;
    }

    return result;
}

std::string BigReal::toString() const {
    std::stringstream ss;
    ss << wholePart << ".";
    if (fractionalPart < 100000) {
        ss << "0";  // Add a leading zero for fractional parts less than 100000
    }
    ss.fill('0');
    ss.width(5);
    ss << fractionalPart;
    return ss.str();
}


void BigReal::parseRealNumber(const std::string& realNumber) {
    size_t dotPos = realNumber.find('.');
    if (dotPos != std::string::npos) {
        wholePart = std::stoi(realNumber.substr(0, dotPos));
        fractionalPart = std::stoll(realNumber.substr(dotPos + 1));
    } else {
        wholePart = std::stoi(realNumber);
        fractionalPart = 0;
    }
}
