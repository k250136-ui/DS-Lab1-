#include <iostream>
using namespace std;

const int AVAILABLE = 0;
const int RESERVED = 1;

int main()
{
    int numRows;
    cout << "Enter the number of rows: ";
    cin >> numRows;

    int *seatsPerRow = new int[numRows];

    int **seats = new int *[numRows];

    int totalSeats = 0;

    for (int r = 0; r < numRows; r++)
    {
        cout << "Enter number of seats in Row " << (r + 1) << ": ";
        cin >> seatsPerRow[r];

        seats[r] = new int[seatsPerRow[r]];
        for (int s = 0; s < seatsPerRow[r]; s++)
        {
            seats[r][s] = AVAILABLE;
        }

        totalSeats += seatsPerRow[r];
    }

    int numOperations;
    cout << "\nEnter number of operations to perform: ";
    cin >> numOperations;

    for (int op = 0; op < numOperations; op++)
    {
        int row, seat;
        char action;

        cout << "\nOperation " << (op + 1)
             << " - Enter row, seat, and action (R = reserve, C = cancel): ";
        cin >> row >> seat >> action;

        int r = row - 1;
        int s = seat - 1;

        if (r < 0 || r >= numRows || s < 0 || s >= seatsPerRow[r])
        {
            cout << "Invalid row or seat number. Operation skipped.\n";
            continue;
        }

        if (action == 'R' || action == 'r')
        {
            if (seats[r][s] == RESERVED)
            {
                cout << "Seat already reserved.\n";
            }
            else
            {
                seats[r][s] = RESERVED;
                cout << "Seat reserved successfully.\n";
            }
        }
        else if (action == 'C' || action == 'c')
        {
            if (seats[r][s] == AVAILABLE)
            {
                cout << "Seat is already available.\n";
            }
            else
            {
                seats[r][s] = AVAILABLE;
                cout << "Reservation cancelled successfully.\n";
            }
        }
        else
        {
            cout << "Invalid action. Use 'R' to reserve or 'C' to cancel.\n";
        }
    }

    cout << "\n--- Current Seating Arrangement (0 = Available, 1 = Reserved) ---\n";
    int availableCount = 0;
    for (int r = 0; r < numRows; r++)
    {
        cout << "Row " << (r + 1) << ": ";
        for (int s = 0; s < seatsPerRow[r]; s++)
        {
            cout << seats[r][s] << " ";
            if (seats[r][s] == AVAILABLE)
            {
                availableCount++;
            }
        }
        cout << endl;
    }

    double availablePercentage = 0.0;

    if (totalSeats > 0)
    {
        availablePercentage = (static_cast<double>(availableCount) / totalSeats) * 100;
    }

    cout << "\nTotal seats: " << totalSeats << endl;
    cout << "Available seats: " << availableCount << endl;
    cout << "Percentage of seats still available: " << availablePercentage << "%\n";

    for (int r = 0; r < numRows; r++)
    {
        delete[] seats[r];
    }
    delete[] seats;
    delete[] seatsPerRow;

    return 0;
}