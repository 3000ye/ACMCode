#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int res = 0, l = prices[0];
        for (auto i : prices) {
            if (i > l) res += i - l;

            l = i;
        }

        return res;
    }
};
// @lc code=end

