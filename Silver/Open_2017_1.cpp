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
    //freopen("pairup.in", "r", stdin);
    //freopen("pairup.out", "w", stdout);
    int N, X;
    cin >> N >> X;

    vector<int> a(N);

    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    int l = 0;
    int r = 0;
    int subSum = 0;
    int count = 0;
    while (r <= N) {
        if (subSum == X) {
            count++;
        }
        if (subSum < X) {
            subSum += a[r];
            r++;
        } else {
            subSum -= a[l];
            l++;
        }

    }

    cout << count << endl;
}

