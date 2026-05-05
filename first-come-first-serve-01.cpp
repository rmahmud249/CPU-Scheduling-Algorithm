#include <iostream>
using namespace std;
int main() {
    int bt[20], wt[20], tat[20];
    int i, n;
    float wtavg = 0, tatavg = 0;
    cout << "Enter the number of processes: ";
    cin >> n;
    // Input burst times
    for (i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process " << i+1 << ": ";
        cin >> bt[i];
    }
    // Initial values
    wt[0] = 0;
    tat[0] = bt[0];
    wtavg = 0;
    tatavg = bt[0];
    // Calculate waiting time and turnaround time
    for (i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];

        wtavg += wt[i];
        tatavg += tat[i];
    }
    // Output results
    cout << "\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";

    for (i = 0; i < n; i++) {
        cout << "P" << i+1 << "\t\t"
             << bt[i] << "\t\t"
             << wt[i] << "\t\t"
             << tat[i] << endl;
    }
    // Averages
    cout << "\nAverage Waiting Time: " << wtavg / n;
    cout << "\nAverage Turnaround Time: " << tatavg / n << endl;

    return 0;
}
