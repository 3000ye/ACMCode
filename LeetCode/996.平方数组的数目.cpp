#include <bits/stdc++.h>
#include <cmath>
using namespace std;

/*
 * @lc app=leetcode.cn id=996 lang=cpp
 *
 * [996] 平方数组的数目
 */

// @castor solve=start
// 使用 深度优先搜索，规则是：
// 1. 使用 flag 记录每个元素是否使用过，若使用过则跳过
// 2. 在同层级里面，若有相同元素也跳过（需要事先对序列排序）
// 3. 若 path 不为空，则判断是否满足条件
// @castor solve=end

// @lc code=start
class Solution {
public:
    vector<vector<int>> res;
    vector<int> path; vector<bool> flag;
    int numSquarefulPerms(vector<int>& nums) {
        flag.resize(nums.size());
        // 排序，为剪枝的步骤准备
        sort(nums.begin(), nums.end());
        dfs(nums);
        return res.size();
    }

    void dfs(vector<int>& ls) {
        if (path.size() == ls.size()) {
            res.push_back(path); return;
        }

        for (int i = 0, l = ls.size(); i < l; i ++) {
            // 剪枝：已经使用过该元素则跳过
            if (flag[i]) continue;
            // 剪枝：在同一层里面已经用过相同的元素则跳过
            if (i > 0 and ls[i] == ls[i - 1] and !flag[i - 1]) continue;
            // 剪枝：若 path 不为空，则需判断是否满足平方和条件
            if (!path.empty()) {
                int root = sqrt(path.back() + ls[i]);
                if (root * root != path.back() + ls[i]) continue;
            }

            path.push_back(ls[i]); flag[i] = true;
            dfs(ls);
            // 恢复现场
            path.pop_back(); flag[i] = false;
        }
    }
};
// @lc code=end

