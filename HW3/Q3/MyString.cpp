#include "MyString.h"

char* MyString::getData() const {
    return this->str;
}

int MyString::getLength() const {
    return this->len;
}

void MyString::setData(char* data) {
    str = data;
}

void MyString::setLength(int n) {
    len = n;
}


MyString::MyString(const char* s)
{
    if (s)
    {
        len = strlen(s);
        str = new char[len + 1];
        strcpy(str, s);
    }
    else
        str = nullptr;
}

MyString::MyString(const MyString& ms)
    :MyString(ms.str)
{
    cout << "copy ctor: " << str << endl;
}

MyString& MyString::operator=(const MyString& ms)
{
    len = ms.len;

    if (str)
        delete[] str;

    if (ms.str)
    {
        len = strlen(ms.str);
        str = new char[len + 1];
        strcpy(str, ms.str);
    }
    else
        str = nullptr;

    return *this;
}

MyString::MyString(MyString&& ms)
{  // move constructor

    cout << "move ctor" << endl;

    len = ms.len;
    str = ms.str; 
    ms.str = nullptr;

}



MyString& MyString::operator=(MyString&& ms)
{ 
    cout << "move assign" << endl;
    if (str)
        delete[] str;

    len = ms.len;
    str = ms.str; 
    ms.str = nullptr;

    return *this;
}
MyString::~MyString()
{
    if (str) {
        delete[] str;
    }
    str = nullptr;
    
}


bool MyString::operator==(const MyString& ms) const
{
    return !strcmp(str, ms.str);
}

bool MyString::operator!=(const MyString& ms) const {
    return !(ms == *this);
}

bool MyString::operator>(const MyString& ms) const {
    if (strcmp(str, ms.str) > 0)
        return true;
    return false;
}

bool MyString::operator<(const MyString& ms) const {
    if (strcmp(str, ms.str) < 0)
        return true;
    return false;
}

bool MyString::operator>=(const MyString& ms) const {
    if (*this < ms)
        return false;
    return true;
}

bool MyString::operator<=(const MyString& ms) const {
    if (*this > ms)
        return false;
    return true;
}

ostream& operator<<(ostream& os, const MyString& ms)
{
    if (ms.str)
        os << ms.str << endl;

    return os;
}

istream& operator>>(istream& is, MyString& ms)
{
    is >> ms.len;

    ms.str = new char[ms.len + 1];
    is >> ms.str;

    return  is;
}



char& MyString::operator[] (const int index) {
    if (index >= len) {
        cout << "ERROR" << endl;
         exit(0);
        return str[0];
    }
    return  *(str + index);
}

MyString MyString::insert(int index, const char* string2) {
    
    if (index > len || len < 0) {
        cout << "ERROR" << endl;
        return "";
    }

    char* temp = new char[strlen(string2) + len + 1];
    int i = 0, string1Index=0;
    while (i < index) {
        temp[i] = str[string1Index];
        string1Index++;
        i++;
    }
    
    for (int j = 0; j < strlen(string2); j++, i++)
        temp[i] = string2[j];
    for (int k = i; k < strlen(string2) + len; k++) {
        temp[k] = str[string1Index];
        string1Index++;
    }
    
    temp[strlen(string2) + len] = '\0';
    MyString newString(temp);
    return newString;
}
