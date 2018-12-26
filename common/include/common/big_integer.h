#pragma once
#include <string>

using namespace std;

//-------------------------------------------------------------
class BigInteger {
private:
    string number;
    bool sign;
public:
    BigInteger(); // empty constructor initializes zero
    explicit BigInteger(string s); // "string" constructor
    BigInteger(string s, bool sin); // "string" constructor
    explicit BigInteger(int n); // "int" constructor
    explicit BigInteger(unsigned long n); // "int" constructor
    void setNumber(string s);

    const string &getNumber() const; // retrieves the number
    void setSign(bool s);

    const bool &getSign() const;

    BigInteger absolute() const; // returns the absolute value

    BigInteger &operator=(BigInteger b);

    bool operator==(BigInteger b) const;

    bool operator!=(BigInteger b) const;

    bool operator>(BigInteger b) const;

    bool operator<(BigInteger b) const;

    bool operator>=(BigInteger b) const;

    bool operator<=(BigInteger b) const;

    BigInteger &operator++(); // prefix
    BigInteger const operator++(int); // postfix
    BigInteger &operator--(); // prefix
    BigInteger const operator--(int); // postfix
    BigInteger operator+(BigInteger b) const;

    BigInteger operator-(BigInteger b) const;

    BigInteger operator*(BigInteger b) const;

    BigInteger operator/(BigInteger b) const;

    BigInteger operator%(BigInteger b) const;

    BigInteger &operator+=(BigInteger b);

    BigInteger &operator-=(BigInteger b);

    BigInteger &operator*=(BigInteger b);

    BigInteger &operator/=(BigInteger b);

    BigInteger &operator%=(BigInteger b);

    BigInteger &operator[](int n);

    BigInteger operator-(); // unary minus sign
    operator string(); // for conversion from BigInteger to string
private:
    bool equals(BigInteger n1, BigInteger n2) const;

    bool less(BigInteger n1, BigInteger n2) const;

    bool greater(BigInteger n1, BigInteger n2) const;

    string add(string number1, string number2) const;

    string subtract(string number1, string number2) const;

    string multiply(string n1, string n2) const;

    pair<string, long long> divide(string n, long long den) const;

    string toString(long long n) const;

    long long toInt(string s) const;
};
