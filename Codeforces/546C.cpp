#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

#define ll long long
using namespace std;
int n, i;

int solve() {
}


int main() {
    int n;
    cin >> n;
    if (n % 2 == 0) {
        cout << -1 << "\n";
        return 0;
    }

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < n; j++) {
            cout << j << " ";
        }
        cout << "\n";
    }
    for (int j = 0; j < n; j++) {
        cout << (2*j) % n<< " ";
    }


    return 0;
}
