#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

// Function to compute GCD
long long gcd(long long a, long long b) {
    while (b != 0) {
        long long temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

// Function to find all divisors of g
vector<long long> findDivisors(long long g) {
    vector<long long> divisors;
    for (long long i = 1; i * i <= g; ++i) {
        if (g % i == 0) {
            divisors.push_back(i);
            if (i != g / i) {
                divisors.push_back(g / i);
            }
        }
    }
    sort(divisors.begin(), divisors.end());
    return divisors;
}

int main() {
    long long a, b;
    int n;

    cin >> a >> b;

    long long g = gcd(a, b);
    vector<long long> divisors = findDivisors(g);

    cin >> n;

    while (n--) {
        long long low, high;
        cin >> low >> high;
        auto it = upper_bound(divisors.begin(), divisors.end(), high);
        if (it == divisors.begin() || *(--it) < low) {
            cout << -1 << "\n";
        } else {
            cout << *it << "\n";
        }
    }

    return 0;
}