#include <vector>
#include <algorithm>

using namespace std;

// 0004 - Median of Two Sorted Arrays
// https://leetcode.com/problems/median-of-two-sorted-arrays/
// Time: O(log(n + m)) | Space: O(log(n + m))

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        int N = n + m;
        int k = (N + 1) / 2;
        bool even = (N % 2 == 0);

        return aux(nums1, nums2, 0, n, 0, m, k, even);
    }

private:
    double aux(const vector<int>& A, const vector<int>& B,
               int ia, int fa, int ib, int fb, int k, bool even) {
        int na = fa - ia;
        int nb = fb - ib;

        if (na == 0) {
            if (!even) return B[ib + k - 1];

            double x = B[ib + k - 1];
            double y = B[ib + k];
            return (x + y) / 2.0;
        }

        if (nb == 0) {
            if (!even) return A[ia + k - 1];

            double x = A[ia + k - 1];
            double y = A[ia + k];
            return (x + y) / 2.0;
        }

        if (k == 1) {
            if (!even) return min(A[ia], B[ib]);

            int x, y;

            if (A[ia] <= B[ib]) {
                x = A[ia];
                ia++;
            } else {
                x = B[ib];
                ib++;
            }

            if (ia == fa) y = B[ib];
            else if (ib == fb) y = A[ia];
            else y = min(A[ia], B[ib]);

            return (static_cast<double>(x) + y) / 2.0;
        }

        int pa = min(na, k / 2);
        int pb = min(nb, k / 2);

        if (A[ia + pa - 1] <= B[ib + pb - 1])
            return aux(A, B, ia + pa, fa, ib, fb, k - pa, even);

        return aux(A, B, ia, fa, ib + pb, fb, k - pb, even);
    }
};
