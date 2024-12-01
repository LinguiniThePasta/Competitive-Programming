#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <map>

#define ll long long

using namespace std;
int n, i;

int solve() {
}


int main() {
    int n;
    cin >> n;
    map<int, ll> mapA;
    map<int, ll> mapB;
    map<pair<int, int>, ll> doubleCount;
    ll ans = 0;
    while (n--) {
        int x, y;
        cin >> x >> y;
        ans += mapA[x];
        ans += mapB[y];
        if (doubleCount[make_pair(x, y)]) {
            ans -= doubleCount[make_pair(x, y)];
        }
        doubleCount[make_pair(x, y)] += 1;
        mapA[x] += 1;
        mapB[y] += 1;
    }

    cout << ans << "\n";

    return 0;
}
