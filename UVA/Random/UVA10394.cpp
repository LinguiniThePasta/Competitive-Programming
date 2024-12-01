#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

int isPrime(int s) {
    if (s == 1) {
        return 0;
    }
    for (int i = 2; i * i <= s; i++) {
        if (s % i == 0) {
            return 0;
        }
    }
    return 1;
}


int solve(int n) {
    return 0;
}

int main() {
    int s;
    int n = 20000000;
    vector<bool> prime(n, true);
    prime[0] = false;
    prime[1] = false;
    for (int i = 2; i * i <= n; i++) {
        if (prime[i] == true) {
            for (int j = i * i; j <= n; j += i) {
                prime[j] = false;
            }
        }
    }
    vector<pair<int, int>> twin_primes;
    for (int i = 2; i <= n - 2; i++) {
        if (prime[i] && prime[i + 2]) {
            twin_primes.emplace_back(i, i + 2);
        }
    }
    while (scanf("%d", &s) == 1) {
        printf("(%d, %d)\n", twin_primes[s - 1].first, twin_primes[s - 1].second);
    }
    return 0;

}
