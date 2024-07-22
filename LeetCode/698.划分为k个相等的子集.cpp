#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        map<int, int> dic;
        int sum = 0;
        for (auto i : nums) { dic[i] ++; sum += i; }
        if (sum % k) return false;

        int target = sum / k;

    }
};
// @lc code=end

