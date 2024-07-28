#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=78 lang=cpp
 *
 * [78] 子集
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> subsets(vector<int>& nums) {
        dfs(0, nums);
        return res;
    }

    void dfs(int cur, vector<int>& nums) {
        if (cur == nums.size()) {
            res.push_back(path); return;
        }

        // cur 加入子集
        path.push_back(nums[cur]);
        dfs(cur + 1, nums);
        // 恢复现场，cur 不加入子集
        path.pop_back();
        dfs(cur + 1, nums);
    }
};
// @lc code=end

