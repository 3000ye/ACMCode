#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=725 lang=cpp
 *
 * [725] 分隔链表
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
    vector<ListNode*> splitListToParts(ListNode* head, int k) {
        vector<ListNode*> ls(k, nullptr);
        
        int cnt = 0;
        for (auto cur = head; cur; cur = cur->next) cnt ++;
        if (cnt == 0) return ls;

        if (cnt < k) {
            for (int i = 0; i < cnt; i ++) {
                ls[i] = head;
                head = head->next;
                ls[i]->next = nullptr;
            }
        }
        else {
            int step = cnt / k, remain = cnt % k;
            for (int i = 0; i < k; i ++) {
                ls[i] = head;

                for (int j = 0; j < step - 1; j ++) head = head->next;

                if (remain > 0) {
                    head = head->next;
                    remain --;
                }

                auto cur = head->next;
                head->next = nullptr;
                head = cur;
            }
        }

        return ls;
    }
};
// @lc code=end

