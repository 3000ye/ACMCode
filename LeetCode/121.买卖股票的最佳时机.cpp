#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=121 lang=cpp
 *
 * [121] 买卖股票的最佳时机
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int l = prices[0], res = 0;
        for (auto i : prices) {
            l = min(l, i);
            res = max(res, i - l);
        }

        return res;
    }
};
// @lc code=end

