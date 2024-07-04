#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=25 lang=cpp
 *
 * [25] K 个一组翻转链表
 */

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
    ListNode* reverseKGroup(ListNode* node, int k) {
        int cnt = 0;
        for (auto cur = node; cur; cur = cur->next) { cnt ++; }

        auto head = new ListNode(0, node);
        auto p = head;
        ListNode *pre = nullptr; auto cur = head->next;

        for (; cnt >= k; cnt -= k) {
            for (int i = 0; i < k; i ++) {
                auto next = cur->next;
                cur->next = pre;
                pre = cur;
                cur = next;
            }

            auto next = p->next;
            p->next->next = cur;
            p->next = pre;
            p = next;
        }

        return head->next;
    }
};
// @lc code=end

