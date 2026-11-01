// 0023 - Merge k Sorted Lists
// https://leetcode.com/problems/merge-k-sorted-lists/
// Time: O(N log k) | Space: O(k)

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */

#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        if (lists.empty()) return nullptr;
        if (lists.size() == 1) return lists[0];

        queue<ListNode*> q;
        for (ListNode* p : lists) q.push(p);

        while (q.size() > 1) {
            ListNode* p1 = q.front(); q.pop();
            ListNode* p2 = q.front(); q.pop();

            q.push(merge2(p1, p2));
        }

        return q.front();
    }

private:
    ListNode* merge2(ListNode* p1, ListNode* p2) {
        ListNode dummy;
        ListNode* tail = &dummy;

        while (p1 != nullptr && p2 != nullptr) {
            if (p1->val <= p2->val) {
                tail->next = p1;
                p1 = p1->next;
            }
            else {
                tail->next = p2;
                p2 = p2->next;
            }
            tail = tail->next;
        }

        tail->next = (p1 != nullptr) ? p1 : p2;

        return dummy.next;
    }
};
