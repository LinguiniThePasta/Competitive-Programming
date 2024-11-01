#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;
int main() {
    int c, s;
    int num = 1;
    while (cin >> c >> s) {
        vector<int> specimen(s);
        int sum = 0;
        for (int i = 0; i < s; i++) {
            cin >> specimen[i];
            sum += specimen[i];
        }

        double avg = (double)sum / c;

        for (int i = 0; i < 2 * c - s; i++) {
            specimen.push_back(0);
        }

        sort(specimen.begin(), specimen.end());
        double imbalance = 0;
        cout << "Set #" << num << "\n";
        for (int i = 0; i < specimen.size()/2; i++) {
            cout << " " << i << ":";
            if (specimen[i] != 0) {
                cout << " " << specimen[i];
            }
            if (specimen[specimen.size() - i - 1] != 0) {
                cout << " ";
                cout << specimen[specimen.size() - i - 1];
            }
            cout << "\n";
            imbalance += abs((specimen[i] + specimen[specimen.size() - i - 1]) - avg);
        }
        cout << fixed << setprecision(5) << "IMBALANCE = " << imbalance << "\n\n";
        num++;
    }
}
