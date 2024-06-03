#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=55 lang=cpp
 *
 * [55] 跳跃游戏
 */

// @lc code=start
class Solution {
public:
    bool canJump(vector<int>& nums) {
        int idx = 0;
        for (int i = 0, l = nums.size(); i < l; i ++) {
            if (i > idx) break;

            idx = max(idx, i + nums[i]);
            if (idx >= l - 1) return true;
        }

        return false;
    }
};
// @lc code=end

