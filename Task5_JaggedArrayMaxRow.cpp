#include <iostream>
using namespace std;

int main() {
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;

    int* rowSize = new int[numRows];

    int** arr = new int*[numRows];

    for (int i = 0; i < numRows; i++) {
        cout << "Enter size of Row " << (i + 1) << ": ";
        cin >> rowSize[i];

        arr[i] = new int[rowSize[i]];

        cout << "Enter " << rowSize[i] << " elements for Row " << (i + 1) << ": ";
        for (int j = 0; j < rowSize[i]; j++) {
            cin >> arr[i][j];
        }
    }

    cout << "\n--- Jagged Array Elements ---\n";
    for (int i = 0; i < numRows; i++) {
        cout << "Row " << (i + 1) << ": ";
        for (int j = 0; j < rowSize[i]; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }

    int maxRowIndex = 0;
    for (int i = 1; i < numRows; i++) {
        if (rowSize[i] > rowSize[maxRowIndex]) {
            maxRowIndex = i;
        }
    }

    cout << "\nRow with the maximum number of elements: Row " << (maxRowIndex + 1) << endl;
    cout << "Size of that row: " << rowSize[maxRowIndex] << endl;

    cout << "Elements of Row " << (maxRowIndex + 1) << ": ";
    for (int j = 0; j < rowSize[maxRowIndex]; j++) {
        cout << arr[maxRowIndex][j] << " ";
    }
    cout << endl;

    for (int i = 0; i < numRows; i++) {
        delete[] arr[i];
    }
    delete[] arr;
    delete[] rowSize;

    return 0;
}