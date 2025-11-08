#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
using namespace std;

int Count(const char* str, int i)
{
    if (!str[i] || !str[i + 1])
        return 0;

    if ((str[i] == 'n' && str[i + 1] == 'o') ||
        (str[i] == 'o' && str[i + 1] == 'n'))
        return 1 + Count(str, i + 1);
    else
        return Count(str, i + 1);
}

char* Replace(const char* str, char* dest, char* t, int i)
{
    if (!str[i])
    {
        *t = '\0';
        return dest;
    }

    if ((str[i] == 'n' && str[i + 1] == 'o') ||
        (str[i] == 'o' && str[i + 1] == 'n'))
    {
        *t++ = '*';
        *t++ = '*';
        *t++ = '*';
        return Replace(str, dest, t, i + 2);
    }
    else
    {
        *t++ = str[i++];
        return Replace(str, dest, t, i);
    }
}

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    int pairs = Count(str, 0);

    if (pairs > 0)
    {
        cout << "String contained " << pairs << " groups of 'no' or 'on'" << endl;

        char* dest = new char[3 * strlen(str) + 1];
        dest[0] = '\0';
        char* result = Replace(str, dest, dest, 0);

        cout << "Modified string (param) : " << dest << endl;
        cout << "Modified string (result): " << result << endl;

        delete[] dest;
    }
    else
    {
        cout << "No 'no' or 'on' found" << endl;
    }

    return 0;
}
