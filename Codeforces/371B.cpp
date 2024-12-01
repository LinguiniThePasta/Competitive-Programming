#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>
#include <map>

#define ll long long

using namespace std;
int n, i;
int numOfFactors(int *a, int b) {
    int ans = 0;
    while ( *a % b == 0) {
        *a /= b;
        ans++;
    }
    return ans;
}

int main() {
    int a, b;
    cin >> a >> b;
    int a2 = numOfFactors(&a, 2);
    int b2 = numOfFactors(&b, 2);
    int a3 = numOfFactors(&a, 3);
    int b3 = numOfFactors(&b, 3);
    int a5 = numOfFactors(&a, 5);
    int b5 = numOfFactors(&b, 5);


    if (a != b ) {
        cout << -1;
        return 0;
    }

    cout << abs(a2-b2) + abs(a3-b3) + abs(a5-b5);
    return 0;
}
