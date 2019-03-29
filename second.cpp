#include <iostream>

using std::cin;
using std::cout;

int fib(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return fib(n - 2) + fib(n - 1);
}

int main()
{
    int n;
    cout << "Enter a number: ";
    cin >> n;

    int curr = 1, previous = 0;
    cout << curr << ' ';
    for(int i = 0; i < n - 1; i++)
    {
        cout << curr + previous << ' ';
        int tmp = curr;
        curr = curr + previous;
        previous = tmp;
    }
    
    cout << '\n';
}