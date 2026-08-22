#include<iostream>
using namespace std;

void MinMax(int arr[], int n, int *min, int *max)
{
    *min = arr[0];
    *max = arr[0];

    for (int i = 1; i < n; i++)
    {
        if (*min <= arr[i])
            *min = arr[i];

        if (*max >= arr[i])
            *max = arr[i];
    }
}

int main(){
    int arr[] = {25, 10, 45, 5, 30, 60, 15};
    int size = sizeof(arr)/sizeof(arr[0]);
    int min,max;

    MinMax(arr, size, &min, &max);

    cout << "Elements in Array: ";
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    
    cout << "\nSmallest number: " << min << endl;
    cout << "Largest number: " << max << endl;
    
    return 0;
}