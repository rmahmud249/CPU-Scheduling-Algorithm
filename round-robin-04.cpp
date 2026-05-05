#include <iostream>
using namespace std;

int main()
{
    int i, j, n, t;
    int bu[10], wa[10], tat[10], ct[10], p[10], max_bt;
    float awt = 0, att = 0, time = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    // Input burst times
    for (i = 0; i < n; i++)
    {
        cout << "Enter Burst Time for process " << i + 1 << ": ";
        cin >> bu[i];

        ct[i] = bu[i];   // store original burst time
        p[i] = i + 1;
    }

    cout << "Enter the size of time slice (Time Quantum): ";
    cin >> t;

    // Find maximum burst time
    max_bt = bu[0];
    for (i = 1; i < n; i++)
    {
        if (max_bt < bu[i])
            max_bt = bu[i];
    }

    // Round Robin Scheduling
    for (j = 0; j < (max_bt / t) + 1; j++)
    {
        for (i = 0; i < n; i++)
        {
            if (bu[i] != 0)
            {
                if (bu[i] <= t)
                {
                    time += bu[i];
                    tat[i] = time;
                    bu[i] = 0;
                }
                else
                {
                    bu[i] -= t;
                    time += t;
                }
            }
        }
    }

    // Calculate waiting time and averages
    for (i = 0; i < n; i++)
    {
        wa[i] = tat[i] - ct[i];
        att += tat[i];
        awt += wa[i];
    }

    // Output table
    cout << "\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    for (i = 0; i < n; i++)
    {
        cout << "P" << p[i] << "\t\t"
             << ct[i] << "\t\t"
             << wa[i] << "\t\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Turnaround Time: " << att / n;
    cout << "\nAverage Waiting Time: " << awt / n;

    return 0;
}
