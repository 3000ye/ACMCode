#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=62 lang=cpp
 *
 * [62] 不同路径
 */

// @castor solve=start
// 动态规划：扩大数组规模降低代码量
// f(x, y) = f(x - 1, y) + f(x, y - 1)
// @castor solve=end

// @lc code=start
class Solution {
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> dic(m + 1, vector<int> (n + 1, 0));

        dic[1][1] = 1;
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                dic[i][j] += dic[i - 1][j] + dic[i][j - 1];
            }
        }

        return dic[m][n];
    }
};
// @lc code=end

