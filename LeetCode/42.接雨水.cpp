#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=42 lang=cpp
 *
 * [42] 接雨水
 */

// @castor solve=start
// 
// @castor solve=end

// @lc code=start
class Solution {
public:
    int trap(vector<int>& height) {
        stack<int> stk; int cnt = 0;

        for (int i = 0, l = height.size(); i < l; i ++) {
            while (!stk.empty() and height[stk.top()] < height[i]) {
                int idx = stk.top(); stk.pop();
                if (stk.empty()) break;

                int l = stk.top(), r = i;
                int h = min(height[r], height[l]) - height[idx];
                cnt += (r - l - 1) * h;
            }

            stk.push(i);
        }

        return cnt;
    }
};
// @lc code=end

