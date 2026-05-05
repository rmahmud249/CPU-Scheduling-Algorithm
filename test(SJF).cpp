#include <iostream>
using namespace std;

int main()
{
    int p[20], bt[20], wt[20], tat[20];
    int i, k, n;
    float wtavg = 0, tatavg = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    // Input burst times
    for (i = 0; i < n; i++){
        p[i] = i + 1;   // Process IDs start from P1
        cout << "Enter Burst Time for Process " << i + 1 << ": ";
        cin >> bt[i];
    }

    // Sorting based on Burst Time (SJF)
    for (i = 0; i < n; i++){
        for (k = i + 1; k < n; k++){
            if (bt[i] > bt[k])
            {
                swap(bt[i], bt[k]);
                swap(p[i], p[k]);
            }
        }
    }

    // Calculate waiting time and turnaround time
    wt[0] = 0;
    tat[0] = bt[0];

    for (i = 1; i < n; i++){
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];

        wtavg += wt[i];
        tatavg += tat[i];
    }
    tatavg += tat[0];

    // Output Table
    cout << "\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    for (i = 0; i < n; i++){
        cout << "P" << p[i] << "\t\t"
             << bt[i] << "\t\t"
             << wt[i] << "\t\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << wtavg / n;
    cout << "\nAverage Turnaround Time: " << tatavg / n;

    // -------- GANTT CHART --------
    cout << "\n\nGantt Chart:\n";

    // Top bar
    cout << " ";
    for (i = 0; i < n; i++){
        cout << "------";
    }

    // Process IDs row
    cout << "\n|";
    for (i = 0; i < n; i++){
        cout << " P" << p[i] << " |";
    }

    // Bottom bar
    cout << "\n ";
    for (i = 0; i < n; i++){
        cout << "------";
    }

    // Time line
    cout << "\n0";
    for (i = 0; i < n; i++){
        cout << "     " << tat[i];
    }

    cout << endl;

    return 0;
}
