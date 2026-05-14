#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> bt(n), wt(n), tat(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process P" << i + 1 << ": ";
        cin >> bt[i];
    }

    wt[0] = 0;
    tat[0] = bt[0];

    float wtSum = wt[0];
    float tatSum = tat[0];


    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i]; 

        wtSum += wt[i];
        tatSum += tat[i];
    }

    cout << "\nPROCESS\tBURST\tWAIT\tTURNAROUND\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << i + 1 << "\t\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << wtSum / n;
    cout << "\nAverage Turnaround Time: " << tatSum / n << endl;

    return 0;
}