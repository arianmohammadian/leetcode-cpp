// 0022 - Generate Parentheses
// https://leetcode.com/problems/generate-parentheses/
// Time: O(n^2 * C_n * log C_n) | Space: O(n * C_n)
//
// C_n is the nth Catalan number.

#include <vector>
#include <string>
#include <set>
using namespace std;

class Solution {
public:
    vector<string> generateParenthesis(int n) {
        // Base cases
        if (n == 0) return {""};
        if (n == 1) return {"()"};

        // Recursive case
        vector<string> substrings = generateParenthesis(n - 1);
        set<string> res;

        for (const string& s : substrings) {
            for (int i = 0; i <= s.size(); i++) {
                string newString = s.substr(0, i) + "()" + s.substr(i);
                res.insert(newString);
            }
        }

        return vector<string>(res.begin(), res.end());
    }
};
