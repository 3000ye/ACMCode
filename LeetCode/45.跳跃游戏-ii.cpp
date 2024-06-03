#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=45 lang=cpp
 *
 * [45] 跳跃游戏 II
 */

// @lc code=start
class Solution {
public:
    int jump(vector<int>& nums) {
        int idx = 0, t = 0, end = 0;

        for (int i = 0, l = nums.size(); i < l - 1; i ++) {
            idx = max(idx, i + nums[i]);

            if (i == end) {
                end = idx; t ++;
            }
        }

        return t;
    }
};
// @lc code=end

