#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1019 lang=cpp
 *
 * [1019] 链表中的下一个更大节点
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
    vector<int> nextLargerNodes(ListNode* head) {
        vector<int> ls;

        while (head) {
            auto cur = head->next;
            int val = head->val;

            while (cur and cur->val <= val) cur = cur->next;
            if (cur and cur->val > val) ls.push_back(cur->val);
            else ls.push_back(0);

            head = head->next;
        }

        return ls;
    }
};
// @lc code=end

