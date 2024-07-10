#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=61 lang=cpp
 *
 * [61] 旋转链表
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
    ListNode* rotateRight(ListNode* head, int k) {
        if (head == nullptr) return nullptr;
        
        vector<ListNode*> ls;
        auto cur = head;
        while (cur != nullptr) {
            ls.push_back(cur);
            cur = cur->next;
        }

        int n = ls.size();
        k = k % n;
        while (k -- ) {
            auto last = ls.back();
            ls.pop_back();
            last->next = head;
            head = last;
        }
        ls.back()->next = nullptr;

        return head;
    }
};
// @lc code=end

