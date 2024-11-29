#ifndef STRING_HPP
#define STRING_HPP

#include <iostream>
#include <vector>
class String
{
public:
    String();                  // Empty string
    String(char);              // String('x')
    String(const char[]);      // String("abc")
    String(const String &);    // Copy Constructor
    ~String();                 // Destructor
    void swap(String &);       // Constant time swap
    String &operator=(String); // Assignment Copy

    int capacity() const;       // Max chars that can be stored
    int length() const;         // Actual number of chars in string
    char &operator[](int);      // Accessor/Modifier
    char operator[](int) const; // Accessor

    String &operator+=(const String &);
    bool operator==(const String &) const;
    bool operator<(const String &) const;
    String substr(int, int) const;          // sub from staring to ending position
    int findch(int, char) const;            // Location of charater starting at position
    int findstr(int, const String &) const; // Location of string starting at a position

    friend std::ostream &operator<<(std::ostream &, const String &);
    friend std::istream &operator>>(std::istream &, String &);

    std::vector<String> split(char) const;

private:
    char *str;      // Pointer to char[]
    int stringSize; // Size includes NULL terminator
};

String operator+(String, const String &);
bool operator==(const char[], const String &);
bool operator==(char, const String &);
bool operator<(const char[], const String &);
bool operator<(char, const String &);
bool operator<=(const String &, const String &);
bool operator!=(const String &, const String &);
bool operator>=(const String &, const String &);
bool operator>(const String &, const String &);
#endif