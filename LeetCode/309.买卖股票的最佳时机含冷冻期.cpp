#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=309 lang=cpp
 *
 * [309] 买卖股票的最佳时机含冷冻期
 */

// @castor solve=start
// 动态规划：每天都可以买也可以卖，设当前为 d 天，当前股票价格为 p
// 买入：由于冷冻期，则只能从 sale(d - 2) 递推得到，
// 而又因为不能操作，所以 sale(d - 2) = sale(d - 1)，即 buy(d) = max{ buy(d - 1), sale(d - 1) - p }
// 卖出：sale(d) = max{ sale(d - 1), buy(d - 1) + p }
// @castor solve=end

// @lc code=start
class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int sale = 0, buy = INT_MIN, pre_sale = 0;

        for (int p : prices) {
            // 卖出股票 p
            int new_sale = max(sale, buy + p);
            // 买入股票 p，因为有冷冻期，买入的前 1 天不能操作
            // pre_sale 为前 1 天的 sale（实际和前 2 天的 sale 一致）
            buy = max(buy, pre_sale - p);
            // 向前递推
            pre_sale = sale; sale = new_sale;
        }

        return sale;
    }
};
// @lc code=end

