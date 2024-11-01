#include <algorithm>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.first != b.first) {
        return b.first > a.first;
    }
    return b.second < a.second;

}

vector<pair<int, int>> list(0);

int solve() {
    int m;
    scanf("%d", &m);
    int l, r;
    vector<pair<int, int>> a(0);
    while (scanf("%d %d", &l, &r) == 2 && (l != 0 || r != 0)) {
        a.push_back(make_pair(l, r));
    }
    sort(a.begin(), a.end(), cmp);

    int maxReach = 0;
    int curEnd = 0;
    int i = 0;
    while (curEnd < m) {
        int best = -1;
        while (i < a.size() && a[i].first <= curEnd) {
            if (maxReach < a[i].second) {
                maxReach = a[i].second;
                best = i;
            }
            i++;
        }
        if (best == -1) {
            return -1;
        }
        curEnd = maxReach;
        list.push_back(a[best]);
    }

    sort(list.begin(), list.end());
    return list.size();
}

int main() {
    int t;
    scanf("%d", &t);

    while (t--) {
        list.clear();
        int ans = solve();
        if (ans == -1) {
            printf("%d\n", 0);
        }
        else {
            printf("%d\n", ans);
            for (auto & i : list) {
                printf("%d %d\n", i.first, i.second);
            }
        }
        if (t) {
            printf("\n");
        }
    }

}
