#include <iostream>
using namespace std;

int main()
{
    int p[20], bt[20], wt[20], tat[20];
    int i, k, n;
    float wtavg = 0, tatavg = 0;

    cout << "Enter the number of processes: ";
    cin >> n;

    for (i = 0; i < n; i++){
        p[i] = i;
        cout << "Enter Burst Time for Process " << i+1 << ":";
        cin >> bt[i];
    }

    for (i = 0; i < n; i++){
        for (k = i + 1; k < n; k++){
            if (bt[i] > bt[k])
            {
           
                swap(bt[i], bt[k]);
                swap(p[i], p[k]);
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];

    for (i = 1; i < n; i++){
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = tat[i - 1] + bt[i];

        wtavg += wt[i];
        tatavg += tat[i];
    }
    tatavg += tat[0]; 
 
    cout << "\nPROCESS\tBURST TIME\tWAITING TIME\tTURNAROUND TIME\n";
    for (i = 0; i < n; i++){
        cout << "P" << p[i]+1 << "\t\t"
             << bt[i] << "\t\t"
             << wt[i] << "\t\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << wtavg / n;
    cout << "\nAverage Turnaround Time: " << tatavg / n;

    return 0;
}
