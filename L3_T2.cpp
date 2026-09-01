#include <iostream>
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
    int n;
    cout << "Enter number of employee scores: ";
    cin >> n;

    int scores[100];

    cout << "Enter employee scores: ";

    for (int i = 0; i < n; i++)
    {
        cin >> scores[i];
    }

    sort(scores, n);

    cout << "Scores in sort order: ";

    for (int i = 0; i < n; i++)
    {
        cout << scores[i] << " ";
    }

    int k;
    cout << "\nEnter the value of k: ";
    cin >> k;
    int kthScore = scores[k - 1];
    cout << k << "th smallest score is: " << kthScore << endl;

    int low = 0;
    int high = n - 1;
    bool found = false;

    while (low <= high)
    {
        int mid = (low + high) / 2;

        if (scores[mid] == kthScore)
        {
            found = true;
            break;
        }
        else if (kthScore < scores[mid])
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
        cout << "Score exists in the array.";
    }
    else
    {
        cout << "Score does not exist in the array.";
    }

    return 0;
}