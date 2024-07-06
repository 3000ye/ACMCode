#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk; int low = 0;

        int cnt = 0;
        for (auto h : height) {
            if (stk.empty()) stk.push(h);
            else if (stk.top() < h) {
                int temp = 0, new_cnt = 0;
                
            }
            else if (stk.top() > h) {
                low = h; stk.push(h);
            }
        }

        return cnt;
    }
};
// @lc code=end

