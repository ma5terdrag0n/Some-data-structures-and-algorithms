//fact[] contains factorial mod md and inv contains factorial inverse mod md
// This code helps to calculate the nCr mod md very Easily !!
// For nCr mod md just do fact[n]*inv[r]*inv[n-r]


#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;

const int md = 1000000007;
const int co = 2000010;

long long fact[co + 10], inv[co + 10];

int main() {
    fact[0] = 1;
    for (int i = 1; i <= co; i++) fact[i] = fact[i - 1] * i % md;
    for (int i = 0; i <= co; i++) {
        int x = 1, step = 1 << 30;
        while (step > 0) {
          x = (long long)x * x % md;
          if (step & (md - 2)) x = (long long)x * fact[i] % md;
          step >>= 1;
        }
        inv[i] = x;
    }
    //fact[] contains factorial mod md and inv contains factorial inverse mod md
    // This code helps to calculate the nCr mod md very Easily !!
    // For nCr mod md just do fact[n]*inv[r]*inv[n-r]
    return 0;
}
