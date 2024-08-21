#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=122 lang=cpp
 *
 * [122] 买卖股票的最佳时机 II
 */

// @castor solve=start
// 动态规划：每天都可以买卖，设当前为 d 天，股票价格为 p
// 买入：buy(d) = max{ buy(d - 1), sale(d - 1) - p }
// 卖出：sale(d) = max{ sale(d - 1), buy(d - 1) + p }
// @castor solve=end

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sale = 0, buy = INT_MIN;

        for (auto p : prices) {
            int new_sale = max(sale, buy + p);
            buy = max(buy, sale - p);
            sale = new_sale;
        }

        return sale;
    }
};
// @lc code=end

