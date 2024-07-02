#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=148 lang=cpp
 *
 * [148] 排序链表
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
    ListNode* sortList(ListNode* head) {
        if (head == nullptr || head->next == nullptr) {
            return head;
        }

        vector<ListNode*> ls;
        auto cur = head;
        while (cur != nullptr) {
            ls.push_back(cur);
            cur = cur->next;
        }

        sort(ls.begin(), ls.end(), [](ListNode* a, ListNode* b) {
            return a->val < b->val;
        });

        head = ls[0];
        for (int i = 1, l = ls.size(); i < l; i ++) {
            ls[i - 1]->next = ls[i];
        }
        ls[ls.size() - 1]->next = nullptr;

        return head;
    }
};
// @lc code=end

