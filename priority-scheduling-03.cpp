#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int p[20], bt[20], pri[20], wt[20], tat[20];
    int i, k, n;
    float wtavg, tatavg;

    cout << "Enter the number of processes: ";
    cin >> n;

    // Input process details
    for (i = 0; i < n; i++)
    {
        p[i] = i + 1;
        cout << "Enter the Burst Time & Priority of Process " << i + 1 << ":";
        cin >> bt[i] >> pri[i];
    }

    // Sorting based on priority (lower number = higher priority)
    for (i = 0; i < n; i++)
    {
        for (k = i + 1; k < n; k++)
        {
            if (pri[i] > pri[k])
            {
                swap(p[i], p[k]);
                swap(bt[i], bt[k]);
                swap(pri[i], pri[k]);
            }
        }
    }

    // Waiting time and turnaround time calculation
    wtavg = wt[0] = 0;
    tatavg = tat[0] = bt[0];

    for (i = 1; i < n; i++)
    {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];

        wtavg += wt[i];
        tatavg += tat[i];
    }

    // Output table
    cout << "\nPROCESS\tPRIORITY\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    for (i = 0; i < n; i++)
    {
        cout << "P" << p[i] << "\t"
             << pri[i] << "\t\t"
             << bt[i] << "\t\t"
             << wt[i] << "\t\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time is: " << wtavg / n << endl;
    cout << "Average Turnaround Time is: " << tatavg / n << endl;

    return 0;
}
