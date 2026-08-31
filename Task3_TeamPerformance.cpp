#include <iostream>
using namespace std;

int main() {
    int numTeams;
    cout << "Enter the number of teams: ";
    cin >> numTeams;

    int* employeesPerTeam = new int[numTeams];

    double** scores = new double*[numTeams];

    for (int t = 0; t < numTeams; t++) {
        cout << "\nEnter number of employees in Team " << (t + 1) << ": ";
        cin >> employeesPerTeam[t];

        scores[t] = new double[employeesPerTeam[t]];

        cout << "Enter " << employeesPerTeam[t]
             << " performance score(s) for Team " << (t + 1) << ":\n";
        for (int e = 0; e < employeesPerTeam[t]; e++) {
            cin >> scores[t][e];
        }
    }

    // Display scores team-wise
    cout << "\n--- Team-wise Performance Scores ---\n";
    for (int t = 0; t < numTeams; t++) {
        cout << "Team " << (t + 1) << ": ";
        for (int e = 0; e < employeesPerTeam[t]; e++) {
            cout << scores[t][e] << " ";
        }
        cout << endl;
    }

    int bestTeam = -1;
    double bestAverage = -1.0;

    cout << "\n--- Team Averages ---\n";
    for (int t = 0; t < numTeams; t++) {
        double sum = 0;
        for (int e = 0; e < employeesPerTeam[t]; e++) {
            sum += scores[t][e];
        }

        double average = (employeesPerTeam[t] > 0) ? (sum / employeesPerTeam[t]) : 0;
        cout << "Team " << (t + 1) << " Average: " << average << endl;

        if (average > bestAverage) {
            bestAverage = average;
            bestTeam = t;
        }
    }

    if (bestTeam != -1) {
        cout << "\nTeam with the highest average performance score: Team "
             << (bestTeam + 1) << " (Average = " << bestAverage << ")\n";
    }

    for (int t = 0; t < numTeams; t++) {
        delete[] scores[t];
    }
    delete[] scores;
    delete[] employeesPerTeam;

    return 0;
}