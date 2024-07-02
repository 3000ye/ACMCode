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
    ListNode* reverseKGroup(ListNode* head, int k) {
        auto res = new ListNode(0, head);

        auto cur = res->next;
        while (cur != nullptr) {
            int cnt = 0;
            auto temp = cur;
            while (cnt < k && temp != nullptr) {
                cout << temp->val << " ";
                temp = temp->next;
                cnt++;
            }
            cout << endl;

            if (cnt == k) {
                auto next = temp->next;
                temp->next = nullptr;
                auto new_temp = reverseList(temp);
                auto temp_temp = new_temp;
                while (temp_temp->next != nullptr) temp_temp = temp_temp->next;

                temp_temp->next = next;
                cur->next = new_temp;
                cur = temp_temp;
            }
            else {
                break;
            }
        }

        return res->next;
    }

    ListNode* reverseList(ListNode* head) {
        if (head == nullptr) return nullptr;

        ListNode *res = new ListNode(head->val);
        while (head->next != nullptr) {
            auto tmp = head->next;
            head->next = tmp->next;
            tmp->next = res;
            res = tmp;
        }

        return res;
    }
};
// @lc code=end

