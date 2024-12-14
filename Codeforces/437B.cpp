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
    int s, l;
    cin >> s >> l;
    // if even, -1 if l < s/2
    // if odd
    vector<int> ans(0);
    int curSum = 0;
    for (int i = l; i >= 1; i--) {
        if (i % 2 == 0) {
            if (curSum + (i & -i) <= s) {
                curSum += i & -i;
                ans.push_back(i);
            }
            else {
                break;
            }
        }
    }
    for (int i = l; i >= 1; i--) {
        if (i % 2) {
            if (curSum < s) {
                curSum += 1;
                ans.push_back(i);
            }
            else {
                break;
            }
        }
    }
    if (curSum != s) {
        cout << -1;
        return 0;
    }

    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << " ";
    }
    return 0;
}
