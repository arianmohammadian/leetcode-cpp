#include <cstdint>

using namespace std;

// 0050 - Pow(x, n)
// https://leetcode.com/problems/powx-n/
// Time: O(log |n|) | Space: O(log |n|)

class Solution {
public:
    double auxF(double x, long long n) {
        // Base cases
        if (n == 0) return 1;
        if (n == 1) return x;

        // Recursive case
        double aux = auxF(x, n / 2);

        if (n % 2 == 0) return aux * aux;
        return aux * aux * x;
    }

    double myPow(double x, int n) {
        // Fast exponentiation
        long long exp = n;
        if (exp < 0) exp = -exp;

        double res = auxF(x, exp);

        if (n >= 0) return res;
        return 1.0 / res;
    }
};
