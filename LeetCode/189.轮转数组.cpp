#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=189 lang=cpp
 *
 * [189] 轮转数组
 */

// @lc code=start
class Solution {
public:
    void rotate(vector<int>& nums, int k) {
        vector<int> res(nums.size());
        k = k % nums.size();
        for (int i = 0, l = nums.size(); i < l; i ++) {
            res[i] = nums[(i + l - k) % l];
        }

        nums = res;
    }
};
// @lc code=end

