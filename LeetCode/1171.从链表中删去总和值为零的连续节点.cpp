#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1171 lang=cpp
 *
 * [1171] 从链表中删去总和值为零的连续节点
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
    ListNode* removeZeroSumSublists(ListNode* node) {
        auto head = new ListNode(0);
        head->next = node;

        map<int, ListNode*> dic;
        int sum = 0;
        for (auto cur = head; cur; cur = cur->next) {
            sum += cur->val;
            dic[sum] = cur;
        }
        
        sum = 0;
        for (auto cur = head; cur; cur = cur->next) {
            sum += cur->val;
            cur->next = dic[sum]->next;
        }

        return head->next;
    }
};
// @lc code=end

