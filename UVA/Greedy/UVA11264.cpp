#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(pair<double, double> a, pair<double, double> b) {
    if (a.first != b.first) {
        return a.first < b.first;
    }
    return a.second > b.second;
}


int solve(int n) {
    vector<long long> a(n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }
    int sum = 0;
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (sum < a[i]) {
            ans++;
            sum += a[i];
        }
    }

    return ans;


}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        int n;
        scanf("%d", &n);
        int ans = solve(n);
        printf("%d\n", ans);
    }

}
