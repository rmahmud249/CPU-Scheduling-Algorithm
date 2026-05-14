#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
    int n;

    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> p(n), bt(n), pri(n);
    vector<int> wt(n), tat(n);

    for (int i = 0; i < n; i++) {
        p[i] = i + 1;
        cout << "Enter Burst Time and Priority for Process P" << i + 1 << ": ";
        cin >> bt[i] >> pri[i];
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (pri[i] > pri[j]) {
                swap(p[i], p[j]);
                swap(bt[i], bt[j]);
                swap(pri[i], pri[j]);
            }
        }
    }

    wt[0] = 0;
    tat[0] = bt[0];

    int wtSum = wt[0];
    int tatSum = tat[0];

    for (int i = 1; i < n; i++) {
        wt[i] = wt[i - 1] + bt[i - 1];
        tat[i] = wt[i] + bt[i];   

        wtSum += wt[i];
        tatSum += tat[i];
    }

    cout << "\nPROCESS\tPRIORITY\tBURST\tWAIT\tTURNAROUND\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t\t"
             << pri[i] << "\t\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << (float)wtSum / n;
    cout << "\nAverage Turnaround Time: " << (float)tatSum / n << endl;

    return 0;
}