#include <iostream>
#include <algorithm>
#include <vector>
#include <map>

using namespace std;
int main() {
    //freopen("maxcross.in", "r", stdin);
    //freopen("maxcross.out", "w", stdout);

    long long N;
    int K, B;
    cin >> N >> K >> B;
    vector<int> prefixSums(B+1, 0);

    for (int i = 1; i < B+1; i++) {
        cin >> prefixSums[i];

    }
    sort(prefixSums.begin(), prefixSums.end());

    int ans = 100000000;
    int minAns = 1000000000;

    for (int i = 0; i < B+1; i++) {
        for (int j = 0; j < i; j++) {
            if (prefixSums[i] - prefixSums[j] - 1 >= K) {

                ans = i - j - 1;

                minAns = min(ans, minAns);

                //cout << minAns << endl;
            }
        }
    }

    cout << minAns << endl;

}
