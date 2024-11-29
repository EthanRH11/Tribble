#include <iostream>
#include <cassert>
#include <vector>
#include "string.hpp"
//***********************************************//

String::String() : stringSize(1)
{
    str = new char[stringSize];
    str[0] = '\0';
}
// Empty string
String::String(char ch)
{
    if (ch == '\0')
    {
        stringSize = 1;
    }
    else
    {
        stringSize = 2;
    }
    str = new char[stringSize];
    str[0] = ch;
    str[1] = '\0';
} // Stirng('x')
String::String(const char s[])
{
    stringSize = 0;
    while (s[stringSize] != '\0')
        ++stringSize;
    ++stringSize; // for the null terminator
    str = new char[stringSize];
    for (int i = 0; i < stringSize; ++i)
    {
        str[i] = s[i];
    }
} // String("abcd")

//************************************************//

String::String(const String &copy)
{
    stringSize = copy.stringSize;
    str = new char[stringSize];
    for (int i = 0; i < stringSize; ++i)
    {
        str[i] = copy.str[i];
    }

} // Copy Constructor

String::~String()
{
    delete[] str;
} // Destructor

void String::swap(String &rhs)
{
    int temp_stringSize = stringSize;
    stringSize = rhs.stringSize;
    rhs.stringSize = temp_stringSize;

    char *temp_str = str;
    str = rhs.str;
    rhs.str = temp_str;
} // Constant time swap

String &String::operator=(String rhs)
{
    swap(rhs);
    return *this;
} // Assignment Copy

//***********************************************//

int String::capacity() const
{
    return stringSize - 1;

} // Max chars that can be stored

int String::length() const
{
    return capacity();
} // Number of char in string

//*****************************************************//
char &String::operator[](int i)
{
    assert(i >= 0 && i < length());
    return str[i];
} // Accessor/Modifier

char String::operator[](int i) const
{
    assert(i >= 0 && i < length());
    return str[i];
} // Accessor

//****************************************************//

String &String::operator+=(const String &rhs)
{
    int newLen = length() + rhs.length() + 1;

    char *newStr = new char[newLen];

    for (int i = 0; i < this->length(); ++i)
    {
        newStr[i] = str[i];
    }

    for (int i = 0; i < rhs.length(); ++i)
    {
        newStr[this->length() + i] = rhs.str[i];
    }
    newStr[newLen - 1] = '\0';
    stringSize = newLen;
    delete[] str;
    str = newStr;

    return *this;
}
// Concatenation
bool String::operator==(const String &rhs) const
{
    int i = 0;
    while ((str[i] != 0) && (rhs.str[i] != 0) && (str[i] == rhs.str[i]) && (str[i] != '\0'))
    {
        ++i;
    }
    return str[i] == rhs.str[i];
}
bool String::operator<(const String &rhs) const
{
    int i = 0;
    while ((str[i] == rhs.str[i]) && (str[i] != 0) && (rhs.str[i] != 0))
    {
        ++i;
    }
    return str[i] < rhs.str[i];
}

//************************************************************//

String String::substr(int start, int end) const
{
    if (start < 0)
    {
        start = 0;
    }
    if (end < start)
    {
        return String(); // empty string
    }
    if (end >= length())
    {
        end = length() - 1;
    }
    int subLength = end - start + 1;
    char *subStr = new char[subLength + 1];

    for (int i = 0; i < subLength; ++i)
    {
        subStr[i] = str[start + i];
    }
    subStr[subLength] = '\0';
    String result(subStr);
    delete[] subStr;
    return result;

} // Sub from staring to ending positions
int String::findch(int n, char ch) const
{
    if (n < 0 || n >= stringSize)
    {
        return -1; // check if n is in range
    }

    for (int i = n; i < stringSize; ++i)
    {
        if (str[i] == ch)
        {
            return i;
        }
    }
    return -1; // character not found
} // Location of charater starting at a position
int String::findstr(int n, const String &sub) const
{
    int mainLength = length();
    int subLength = sub.length();

    if (n < 0 || n >= mainLength || subLength == 0 || subLength > mainLength)
    {
        return -1;
    }

    for (int i = n; i <= mainLength - subLength; ++i)
    {
        int j = 0;
        while (j < subLength && (*this)[i + j] == sub[j])
        {
            ++j;
        }
        if (j == subLength)
        {
            return i;
        }
    }
    return -1;
} // Location of string starting at a position

//************************************************************************//

std::istream &operator>>(std::istream &in, String &rhs)
{
    char *buffer = new char[rhs.stringSize];
    if (in.eof())
    {
        return in;
    }
    in >> buffer;
    rhs = String(buffer);
    delete[] buffer;
    return in;
}
std::ostream &operator<<(std::ostream &out, const String &rhs)
{
    out << rhs.str;
    return out;
}

//*******************************************************************//

String operator+(String lhs, const String &rhs)
{
    lhs += rhs;
    return lhs;
}

bool operator==(const char lhs[], const String &rhs)
{
    return String(lhs) == rhs;
}
bool operator==(char lhs, const String &rhs)
{
    return String(lhs) == rhs;
}
bool operator<(const char lhs[], const String &rhs)
{
    return String(lhs) < rhs;
}
bool operator<(char lhs, const String &rhs)
{
    return String(lhs) < rhs;
}
bool operator<=(const String &lhs, const String &rhs)
{
    return (lhs < rhs) || (lhs == rhs);
}
bool operator!=(const String &lhs, const String &rhs)
{
    return !(lhs == rhs);
}
bool operator>=(const String &rhs, const String &lhs)
{
    return !(lhs < rhs);
}
bool operator>(const String &lhs, const String &rhs)
{
    return rhs < lhs;
}

//*******************************************************************//

std::vector<String> String::split(char ch) const
{
    std::vector<String> result;
    int start = 0;

    if (length() == 0)
    {
        result.push_back(String());
        return result;
    }

    while (start < length())
    {
        int chPos = findch(start, ch);

        if (chPos != -1)
        {
            result.push_back(substr(start, chPos - 1));
            start = chPos + 1;
        }
        else
        {
            result.push_back(substr(start, length() - 1));
            break;
        }

        if (chPos == start)
        {
            result.push_back(String());
        }
    }
    // accounts for ch being at the end of string
    if (length() > 0 && str[length() - 1] == ch)
    {
        result.push_back(String());
    }

    return result;
}