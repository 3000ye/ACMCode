#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=143 lang=cpp
 *
 * [143] 重排链表
 */

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

struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


class Solution {
public:
    void reorderList(ListNode* node) {
        auto cur = node;
        vector<ListNode*> ls;

        while (cur) {
            ls.push_back(cur);
            cur = cur->next;
        }
        int i = 0, j = ls.size() - 1;
        
        while (i < j) {
            ls[i]->next = ls[j];
            i++;
            if (i == j) break;
            ls[j]->next = ls[i];
            j--;
        }
        ls[i]->next = nullptr;
    }
};
// @lc code=end

