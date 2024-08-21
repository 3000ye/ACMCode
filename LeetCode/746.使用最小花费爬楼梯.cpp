#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=746 lang=cpp
 *
 * [746] 使用最小花费爬楼梯
 */

// @castor solve=start
// 动态规划：需注意数组的长度
// f(x) = min{f(x - 1) + cost(x - 1), f(x - 2) + cost(x - 2)}
// @castor solve=end

// @lc code=start
class Solution {
public:
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int> ls(cost.size() + 2, 0);

        for (int i = 3, l = ls.size(); i < l; i ++ ) {
            ls[i] = min(
                ls[i - 1] + cost[i - 2], ls[i - 2] + cost[i - 3]
            );
        }

        return ls.back();
    }
};
// @lc code=end

