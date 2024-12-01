#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <map>

#define ll long long

using namespace std;
int solve() {
}

int checkIfPossible(int num, map<char, int> a, int tot, int couldMake) {
    int sum = 0;
    for (auto [chara, n] : a) {
        sum += n * (num - couldMake);
    }
    if (sum > tot) {
        return 0;
    }
    return 1;
}

int main() {
    string s;
    cin >> s;
    int p1, p2, p3;
    cin >> p1 >> p2 >> p3;
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;
    int t;
    cin >> t;

    int couldMake = t;
    map<char, int> a;
    for (int i = 0; i < s.length(); i++) {
        a[s[i]] += 1;
        if (s[i] == 'B') {
            couldMake = min(couldMake, p1/a[s[i]]);
            a[s[i]] *= n1;
        }
        else if (s[i] == 'S') {
            couldMake = min(couldMake, p2/a[s[i]]);
            a[s[i]] *= n2;
        }
        else {
            couldMake = min(couldMake, p3/a[s[i]]);
            a[s[i]] *= n3;
        }
    }

    ll l = 0;
    ll r = t;
    int mid = r / 2;
    int ans = 0;

    while (l < r) {
        mid = (r + l) / 2;
        int res = checkIfPossible(mid, a, t, couldMake);
        if (res) {
            l = mid + 1;
            ans = max(ans, mid);
        }
        else {
            r = mid - 1;
        }
    }
    cout << ans;
    return 0;
}

