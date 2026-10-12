#include <iostream>
using namespace std;

void deleteItemAndCompact(int array[], int &length, int target);

int main()

{
    int len = 6;
    int tar = 4;

    int *arr = new int[len]{4, 1, 4, 4, 3, 2};

    cout << "Original Array:" << endl;

    for (int n = 0; n < len; ++n)
    {
        cout << arr[n] << endl;
    }

    deleteItemAndCompact(arr, len, 4);

    cout << "Compacted Array:" << endl;

    for (int n = 0; n < len; ++n)
    {
        cout << arr[n] << endl;
    }

    delete[] arr;

    return 0;
}

void deleteItemAndCompact(int array[], int &length, int target)
{
    int write = 0;
    for (int read; read < length; read++)
    {
        if (array[read] != target)
        {
            array[write] = array[read];
            write++;
        }
        }
    length = write;
}
