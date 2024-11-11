/*
 * @lc app=leetcode.cn id=2 lang=cpp
 * @lcpr version=20003
 *
 * [2] 两数相加
 */


// @lcpr-template-start
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
// @lcpr-template-end

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

// @lc code=start
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
class Solution {
public:
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        auto que1 = toList(l1), que2 = toList(l2);
        queue<int> que; int e = 0;

        while (!que1.empty() or !que2.empty()) {
            int x = 0; if (!que1.empty()) {x = que1.front(); que1.pop(); }
            int y = 0; if (!que2.empty()) {y = que2.front(); que2.pop(); }
            int z = x + y + e;
            que.push(z % 10); e = z / 10;
        }
        if (e != 0) que.push(e);

        return toNode(que);
    }

    queue<int> toList(ListNode* node) {
        queue<int> que;
        auto p = node;
        while (p) {
            que.push(p->val);
            p = p->next;
        }

        return que;
    }

    ListNode* toNode(queue<int> que) {
        auto node = new ListNode(-1);

        auto p = node;
        while (!que.empty()) {
            auto temp = new ListNode(que.front());
            p->next = temp; p = p->next;
            que.pop();
        }

        return node->next;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [2,4,9]\n[5,6,4,9]\n
// @lcpr case=end

// @lcpr case=start
// [0]\n[0]\n
// @lcpr case=end

// @lcpr case=start
// [9,9,9,9,9,9,9]\n[9,9,9,9]\n
// @lcpr case=end

 */

