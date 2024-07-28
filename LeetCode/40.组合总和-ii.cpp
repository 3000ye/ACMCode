#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=40 lang=cpp
 *
 * [40] 组合总和 II
 */

// @castor solve=start
// 使用 深度优先搜索，规则是：
// 1. 将数组排序，如果当前 sum > target 则直接终止
// 2. 每次只能将大于等于自己的元素加入 path，避免重复
// 3. 如果同层级的搜索中已经存在当前元素，则跳过，避免重复
// 4. 使用 target == 0 来替代 sum == target 判断
// @castor solve=end

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path;

    vector<vector<int>> combinationSum2(vector<int>& ls, int target) {
        sort(ls.begin(), ls.end());
        dfs(0, path, ls, target);
        return res;
    }

    void dfs(int cur, vector<int>& path, vector<int>& ls, int target) {
        if (target == 0) {
            res.push_back(path); return;
        }

        // 开始搜索
        for (int i = cur, l = ls.size(); i < l; i ++) {
            // 剪枝：大于 target 直接终止
            if (target - ls[i] < 0) break;
            // 剪枝：如果同层级的已经存在，则跳过
            if (i > cur and ls[i] == ls[i - 1]) continue;


            // 将当前元素加入 path
            path.push_back(ls[i]);
            dfs(i + 1, path, ls, target - ls[i]);
            // 恢复现场
            path.pop_back();
        }
    }
};
// @lc code=end

