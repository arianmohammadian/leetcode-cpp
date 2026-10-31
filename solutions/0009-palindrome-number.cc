#include <climits>

using namespace std;

// 0009 - Palindrome Number
// https://leetcode.com/problems/palindrome-number/
// Time: O(log x) | Space: O(1)

class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;

        int original = x;
        long long reversed = 0;

        while (x > 0) {
            int digit = x % 10;
            x /= 10;
            reversed = reversed * 10 + digit;
        }

        return original == reversed;
    }
};
