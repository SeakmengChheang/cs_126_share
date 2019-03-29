#include <iostream>
#include <time.h>

using std::cin;
using std::cout;

void insertIntoPropriatePlace(int *arr, int i)
{
    if (i != 0 && arr[i] < arr[i - 1]) {
        int index = -1;
        for (int j = 0; j < i; ++j)
            if (arr[j] > arr[i]) {
                index = j;
                break;
            }

        if (index != -1) {
            int lastItem = arr[i]; //save the last input for insterting purpose
            int previous = arr[index], tmp;
            for (int j = index; j < i; ++j) {
                tmp = arr[j + 1];
                arr[j + 1] = previous;
                previous = tmp;
            } //end loop

            arr[index] = lastItem; //insert it into the index
        } //end if
    } //end if
}

int main()
{
    constexpr int length = 200000;
    int arr[length];
    
    //cout << "Enter 10 numbers: ";
    srand(time(NULL));
    for (int i = 0; i < length; ++i) {
        arr[i] = rand() % 10000 - 500;

        insertIntoPropriatePlace(arr, i);
    } //end loop

    cout << "Sorted List:\n";
    for (auto i : arr)
        cout << i << ' ';
    cout << '\n';

    return 0;
}