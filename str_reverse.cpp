#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

string my_strrev(string s)
{
    int half = s.length() / 2;
    for (int i = 0; i < half; ++i)
    {
        char tmp = s[i];
        s[i] = s[s.length() - i - 1];
        s[s.length() - i - 1] = tmp;
    }

    return s;
}

int main()
{
    string s;
    cout << "Enter a string: ";
    cin >> s;

    if (s == my_strrev(s))
        cout << "It's a palindrome!!!";
    else
        cout << "It's not a palindrome!";

    return 0;
}