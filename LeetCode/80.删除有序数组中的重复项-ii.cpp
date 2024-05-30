#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=80 lang=cpp
 *
 * [80] 删除有序数组中的重复项 II
 */

// @lc code=start
class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 2) return nums.size();

        int idx = 1;
        for (int i = 1, l = nums.size(); i < l; i ++) {
            if ((nums[idx] != nums[i] or nums[idx - 1] != nums[i]) and idx != i) {
                nums[++ idx] = nums[i];
            }
        }

        return idx + 1;
    }
};
// @lc code=end

