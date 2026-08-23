#include <iostream>
#include <cstring>
using namespace std;

class MyString
{
private:
    char *str;

public:
    MyString(const char *s = "")
    {
        str = new char[strlen(s) + 1];
        strcpy(str, s);
    }

    MyString(const MyString &obj)
    {
        str = new char[strlen(obj.str) + 1];
        strcpy(str, obj.str);
    }

    MyString& operator=(const MyString &obj)
    {
        if (this != &obj)
        {
            delete[] str;

            str = new char[strlen(obj.str) + 1];
            strcpy(str, obj.str);
        }

        return *this;
    }

    void display()
    {
        cout << str << endl;
    }

    ~MyString()
    {
        delete[] str;
    }
};

int main()
{
    MyString s1("Hello");

    cout << "Original object s1: ";
    s1.display();


    MyString s2 = s1;

    cout << "Copied object s2: ";
    s2.display();


    MyString s3("World");

    cout << "Before assignment, s3: ";
    s3.display();

    s3 = s1;

    cout << "After assignment, s3: ";
    s3.display();

    return 0;
}