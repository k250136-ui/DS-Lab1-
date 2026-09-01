#include<iostream>
using namespace std;

void sort(int arr[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - 1 - i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

int main()
{
    int books[] = {105, 203, 150, 87, 310, 120, 250};
    int n = sizeof(books) / sizeof(books[0]);
    int search;

    cout << "Enter book ID to search: ";
    cin >> search;

    int low = 0;
    int high = n - 1;
    int mid;
    bool found = false;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (books[mid] == search)
        {
            found = true;
            break;
        }
        else if (search < books[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (found)
    {
        cout << "Before sorting: Book found." << endl;
    }
    else
    {
        cout << "Before sorting: Book not found." << endl;
    }

    sort(books, n);
    cout << "\nSorted Book IDs: ";

    for (int i = 0; i < n; i++)
    {
        cout << books[i] << " ";
    }

    cout << endl;
    low = 0;
    high = n - 1;
    found = false;

    while (low <= high)
    {
        mid = (low + high) / 2;

        if (books[mid] == search)
        {
            found = true;
            break;
        }
        else if (search < books[mid])
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }

    if (found)
    {
        cout << "After sorting: Book found." << endl;
    }
    else
    {
        cout << "After sorting: Book not found." << endl;
    }

    return 0;
}