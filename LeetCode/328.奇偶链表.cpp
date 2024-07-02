#include <bits/stdc++.h>
#include <cstddef>
using namespace std;

/*
 * @lc app=leetcode.cn id=328 lang=cpp
 *
 * [328] 奇偶链表
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
    ListNode* oddEvenList(ListNode* head) {
        if (!head) return nullptr;
        vector<ListNode*> ls;
        
        auto cur = head;
        while (cur->next) {
            if (cur->next) ls.push_back(cur->next);
            if (cur->next and cur->next->next) {
                cur->next = cur->next->next;
                cur = cur->next;
            }
            else cur->next = nullptr;
        }

        cur = head;
        while (cur->next) cur = cur->next;
        for (auto temp : ls) {
            cout << temp->val << endl;
            cur->next = temp;
            cur = cur->next;
        }
        cur->next = nullptr;

        return head;
    }
};
// @lc code=end

