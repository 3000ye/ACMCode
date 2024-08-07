#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=81 lang=cpp
 *
 * [81] 搜索旋转排序数组 II
 */

// @lc code=start
class Solution {
public:
    bool search(vector<int>& nums, int target) {
        auto it = find(nums.begin(), nums.end(), target);
        if (it == nums.end()) return false;
        else return true;
    }
};
// @lc code=end

