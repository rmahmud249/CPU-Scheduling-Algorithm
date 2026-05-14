#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, tq;

    cout << "Enter number of processes: ";
    cin >> n;

    vector<int> bt(n), rem(n), wt(n), tat(n), p(n);

    for (int i = 0; i < n; i++) {
        cout << "Enter Burst Time for Process P" << i + 1 << ": ";
        cin >> bt[i];
        rem[i] = bt[i];   
        p[i] = i + 1;
    }

    cout << "Enter Time Quantum: ";
    cin >> tq;

    int time = 0;
    bool done;

    while (true) {
        done = true;

        for (int i = 0; i < n; i++) {
            if (rem[i] > 0) {
                done = false;

                if (rem[i] > tq) {
                    time += tq;
                    rem[i] -= tq;
                } else {
                    time += rem[i];
                    tat[i] = time;
                    rem[i] = 0;
                }
            }
        }

        if (done) break;
    }


    float wtSum = 0, tatSum = 0;

    for (int i = 0; i < n; i++) {
        wt[i] = tat[i] - bt[i];

        wtSum += wt[i];
        tatSum += tat[i];
    }

    cout << "\nPROCESS\tBURST\tWAIT\tTURNAROUND\n";

    for (int i = 0; i < n; i++) {
        cout << "P" << p[i] << "\t\t"
             << bt[i] << "\t"
             << wt[i] << "\t"
             << tat[i] << endl;
    }

    cout << "\nAverage Waiting Time: " << wtSum / n;
    cout << "\nAverage Turnaround Time: " << tatSum / n << endl;

    return 0;
}