#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::string;

int main()
{
    double v1 = 0.0, v2 = 0.0;

    while (true)
    {
        cout << "Enter two numbers: ";
        cin >> v1 >> v2;

        cout << "[1] Sum\n[2] Difference\n[3] Quotient\n[4] Product\n[0] Exit\n";
        cout << "Enter choice: ";
        int choice = 0;
        cin >> choice;

        double result;
        string operation;
        switch (choice)
        {
        case 0:
            cout << "Exited!!!\n";
            return 0;
        case 1:
            result = v1 + v2;
            operation = "sum";
            break;
        case 2:
            result = v1 - v2;
            operation = "difference";
            break;
        case 3:
            result = v1 / v2;
            operation = "quotient";
            break;
        case 4:
            result = v1 * v2;
            operation = "product";
            break;
        }

        cout << "The " << operation << " of " << v1 << " and "
             << v2 << " is " << result << "\n";
    }
}
