#include <algorithm>
#include <cmath>
#include <iomanip>
#include <iostream>
#include <vector>

using namespace std;

unsigned int add(int x, int y) {
    int carryBit = 0;
    unsigned int rev_sum = 0;
    for (int i = 0; i < 32; i++) {
        int x_i = x & 1;
        int y_i = y & 1;

        int res = x_i + y_i;
        if (res == 3) {
            carryBit = 1;
            res = 1;
        }
        else if (res == 2) {
            carryBit = 1;
            res = 0;
        }
        else {
            carryBit = 0;
        }
        x = x >> 1;
        y = y >> 1;
        rev_sum = rev_sum << 1;
        rev_sum |= res;
    }
    unsigned int sum = 0;
    for (int i = 0; i < 32; i++) {
        sum = sum << 1;
        sum |= rev_sum & 1;
        rev_sum = rev_sum >> 1;
    }

    return sum;
}

int main() {
    unsigned int x, y;

    while (scanf("%u %u", &x, &y) == 2) {
        unsigned int res = add(x, y);
        printf("%u\n", res);
    }
    return 0;
}
