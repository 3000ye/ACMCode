#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=698 lang=cpp
 *
 * [698] 划分为k个相等的子集
 */

// @lc code=start
class Solution {
public:
    vector<int> subset_list;
    int target;

    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int sum = 0; for (auto i : nums) sum += i;
        if (sum % k) return false;
        target = sum / k;
        subset_list.resize(k);

        return dfs(nums, 0);
    }

    bool dfs(vector<int>& nums, int cur) {
        if (cur == nums.size()) { return true; }

        // 开始搜索
        for (int i = 0, l = subset_list.size(); i < l; i ++) {
            // 剪枝
            if (i > 0 and subset_list[i] == subset_list[i - 1]) continue;

            // 超出 target
            if (subset_list[i] + nums[cur] > target) continue;

            // 将 cur 放入当前子集中
            subset_list[i] += nums[cur];
            if (dfs(nums, cur + 1)) {
                return true;
            }
            // 恢复现场
            subset_list[i] -= nums[cur];
        }

        return false;
    }
};
// @lc code=end

