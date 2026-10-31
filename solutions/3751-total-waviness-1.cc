// 3751 - Total Waviness of Numbers in Range I
// https://leetcode.com/problems/total-waviness-of-numbers-in-range-i/
// Time: O(N * log M) | Space: O(log M)

class Solution {
public:
    int totalWaviness(int num1, int num2) {
        int res = 0;

        for(int i = num1; i <= num2; i++) res += waviness(i);

        return res;
    }


private:
    int waviness(int x) {
        if(x < 100) return 0;

        vector<int> digits;

        while(x > 0) {
            digits.push_back(x % 10);
            x /= 10;
        }

        int res = 0;

        for(int i = 1; i < digits.size() - 1; i++) {
            if(
                (digits[i - 1] < digits[i] && digits[i] > digits[i + 1])
                ||
                (digits[i - 1] > digits[i] && digits[i] < digits[i + 1])
            ) res ++;
        }

        return res;
    }
};
