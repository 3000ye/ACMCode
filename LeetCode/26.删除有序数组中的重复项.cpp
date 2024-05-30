#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=26 lang=cpp
 *
 * [26] 删除有序数组中的重复项
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int idx = 1;
        for (int i = 0, l = nums.size(); i < l; i ++) {
            if (nums[idx - 1] != nums[i]) {
                nums[idx ++] = nums[i];
            }
        }

        return idx;
    }
};
// @lc code=end

