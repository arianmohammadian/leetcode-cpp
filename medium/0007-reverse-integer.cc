// 0007 - Reverse Integer
// https://leetcode.com/problems/reverse-integer/
// Time: O(log |x|) | Space: O(1)

#include <climits>
using namespace std;

class Solution {
public:
    int reverse(int x) {
        long long reversed = reverseAux(x);

        if (reversed >= INT_MIN && reversed <= INT_MAX)
            return (int) reversed;

        return 0;
    }

private:
    long long reverseAux(int x) {
        long long n = x;
        bool pos = true;

        if (n < 0) {
            pos = false;
            n *= -1;
        }

        long long res = 0;

        while (n > 0) {
            res = res * 10 + n % 10;
            n /= 10;
        }

        return pos ? res : -res;
    }
};
