#include <iostream>
using namespace std;

void accending(int arr[], int n)
{
    int swap = 0;
    int comparision = 0;

    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            comparision++;

            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                swap++;
            }
        }

        cout << "After Pass " << i + 1 << ": ";

        for (int k = 0; k < n; k++)
        {
            cout << arr[k] << " ";
        }

        cout << "\nPrice reached its final position: " << arr[n - 1 - i] << endl;
    }

    cout << "Number of comparision: " << comparision << endl;

    cout << "Number of swaping: " << swap << endl;

    cout << "Sorted prices: ";

    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int prices[] = {1200, 450, 800, 450, 1500, 700, 1200};

    int n = sizeof(prices) / sizeof(prices[0]);

    accending(prices, n);

    return 0;
}