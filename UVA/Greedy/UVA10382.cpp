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

vector<pair<double, double>> list(0);

int solve(vector<pair<double, double>> a, double l) {
    int i = 0;
    int ans = 0;
    double maxEnd = 0;
    while (maxEnd < l) {
        //We want to get the current maxEnd, then
        //look for all intervals which cover the current maxEnd, and is the longest
        double reach = maxEnd;
        int best = -1;
        while (i < a.size() && a[i].first <= maxEnd) {
            if (a[i].second > reach) {
                reach = max(reach, a[i].second);
                best = i;
            }
            i++;
        }
        if (best == -1) {
            return -1;
        }
        maxEnd = reach;
        ans++;
    }
    return ans;
}

int main() {
    int n;
    double l, w;
    while (scanf("%d %lf %lf", &n, &l, &w) == 3) {
        list.clear();

        vector<pair<double, double>> a(0);

        while (n--) {
            double x, r;
            scanf("%lf %lf", &x, &r);
            double range = r*r - w*w/4;
            if (range < 0) {
                continue;
            }

            double left = x - sqrt(range);
            double right = x + sqrt(range);
            a.push_back(make_pair(left, right));
        }
        sort(a.begin(), a.end(), cmp);
        int ans = solve(a, l);
        printf("%d\n", ans);
    }
}
