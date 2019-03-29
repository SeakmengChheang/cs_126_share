#include <iostream>

using std::cin;
using std::cout;

int main()
{
    int n = 5;
    for (int i = 0; i < n * 2; ++i)
    {
        if (i < 5)
            for (int j = 0; j <= i; ++j)
                cout << j + 1;
        else
            for (int j = 1; j < n * 2 - i; ++j)
                cout << j;
        cout << '\n';
    }

    return 0;
}