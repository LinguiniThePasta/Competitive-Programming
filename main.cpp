#include <iostream>
#include <algorithm>
#include <vector>
#include <math.h>
#include <map>
#include <set>

using namespace std;

#define ll long long
#define f first
#define s second

int main() {
    freopen("diamond.in", "r", stdin);
    freopen("diamond.out", "w", stdout);
    int N, K;
    cin >> N >> K;

    vector<int> a(N);
    for (int i = 0; i<N; i++) {
        cin >> a[i];
    }

    sort(a.begin(), a.end());

    int l, r;
    l = 0;
    r = 0;

    int maxNumOne = 0;
    while (r < N) {
        if (abs(a[r] - a[l]) <= K) {
            int numOne = r - l + 1;
            maxNumOne = max(numOne, maxNumOne);
            r++;
        } else {
            l++;
        }
    }

    for (int i = 0; i < N - (maxNumOne-1); i++) {
        if (a[i+maxNumOne-1] - a[i] <= K) {
            a.erase(a.begin() + i, a.begin() + i + maxNumOne);
            break;
        }
    }

    /*
    for (int i = 0; i < a.size(); i++) {
        cout << a[i] << endl;
    }
    */
    l = 0;
    r = 0;

    int maxNumTwo = 0;
    while (r < a.size()) {
        if (abs(a[r] - a[l]) <= K) {
            int numTwo = r - l + 1;
            maxNumTwo = max(numTwo, maxNumTwo);
            r++;
        } else {
            l++;
        }
    }

    cout << maxNumOne + maxNumTwo << endl;
}

