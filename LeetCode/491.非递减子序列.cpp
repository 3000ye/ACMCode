#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=491 lang=cpp
 *
 * [491] 非递减子序列
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;
    vector<vector<int>> findSubsequences(vector<int>& nums) {
        dfs(0, -9999, nums);
        return res;
    }

    void dfs(int cur, int preValue, vector<int> ls) {
        if (cur == ls.size()) {
            if (path.size() >= 2) res.emplace_back(path);
            return;
        }

        if (ls[cur] >= preValue) {
            path.emplace_back(ls[cur]);
            dfs(cur + 1, ls[cur], ls);
            path.pop_back();
        }

        if (ls[cur] != preValue) dfs(cur + 1, preValue, ls);
    }
};
// @lc code=end

