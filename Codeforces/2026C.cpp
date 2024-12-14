#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

#define ll long long
using namespace std;
int n;
string s;

int solve() {
    int j = s.length() - 1;
    int i;
    for (i = s.length() - 1; i >= 0; i--) {
        if (s[i] == '0') {
            break;
        }
    }
    

}


int main() {
    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        cin >> s;
        solve();
    }

    return 0;
}
