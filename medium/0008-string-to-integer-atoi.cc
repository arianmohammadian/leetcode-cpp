#include <string>
#include <climits>

using namespace std;

// 0008 - String to Integer (atoi)
// https://leetcode.com/problems/string-to-integer-atoi/
// Time: O(n) | Space: O(1)

class Solution {
public:
    int getDigit(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        return -1;
    }

    int myAtoi(string s) {
        int i = 0;
        while (i < s.size() && s[i] == ' ') i++;

        bool pos = true;
        if (i < s.size() && (s[i] == '-' || s[i] == '+')) {
            if (s[i] == '-') pos = false;
            i++;
        }

        long long n = 0;
        while (i < s.size()) {
            int d = getDigit(s[i]);
            if (d == -1) break;

            n = n * 10 + d;

            if (n > INT_MAX) {
                if (pos) return INT_MAX;
                if (n > static_cast<long long>(INT_MAX) + 1)
                    return INT_MIN;
            }

            i++;
        }

        if (!pos) n = -n;

        if (n < INT_MIN) return INT_MIN;
        if (n > INT_MAX) return INT_MAX;

        return static_cast<int>(n);
    }
};
