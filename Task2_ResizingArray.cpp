#include<iostream>
using namespace std;

int main(){
    int capacity = 5;
    int size = 0;
    int resize = 0;

    int* arr = new int[capacity];

    while (true)
    {
        int val;
        cin >> val;
        if (val == -1)
        {
            break;
        }

        if (size == capacity) {
            int newCapacity = capacity * 2;
            int* newArr = new int[newCapacity];

            for (int i = 0; i < size; i++) {
                newArr[i] = arr[i];
            }

            delete[] arr;
            arr = newArr;
            capacity = newCapacity;
            resize++;
        }

        arr[size] = val;
        size++;
    }  

    cout << "\nElements entered: ";
    for (int i = 0; i < size; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    cout << "Final size: " << size << endl;
    cout << "Final capacity: " << capacity << endl;
    cout << "Number of times array was resized: " << resize << endl;

    delete[] arr;

    return 0;
}