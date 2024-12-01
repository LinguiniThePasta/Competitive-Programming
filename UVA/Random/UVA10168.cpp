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

void Num(int x, int &a, int &b) {
    for (int i = 2; i <= x / 2; i++) {
        if (isPrime(i) && isPrime(x - i)) {
            a = i;
            b = x - i;

            return;
        }
    }
}

int main() {
    int s;
    int n = 10000000;

    while (scanf("%d", &s) == 1) {
        if (s <= 7) {
            printf("Impossible.\n");
            continue;
        }
        int a, b;
        int f = s - 4;
        int d = 2;
        if (s % 2 == 1) {
            d = 3;
            f = s - 5;
        }

        Num(f, a, b);
        printf("%d %d %d %d\n", 2, d, a, b);
    }
    return 0;
}
