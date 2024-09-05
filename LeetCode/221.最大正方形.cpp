#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=221 lang=cpp
 *
 * [221] 最大正方形
 */

// @castor solve=start
// 动态规划：dp[i][j] = 以 (i, j) 为右下角的最大正方形的边长
// 转移方程：dp[i][j] = min{dp[i][j - 1], dp[i - 1][j], dp[i - 1][j - 1]} + 1
// @castor solve=end

// @lc code=start
class Solution {
public:
    int maximalSquare(vector<vector<char>>& matrix) {
        if (matrix.size() == 0 or matrix[0].size() == 0) return 0;

        int m = matrix.size(), n = matrix[0].size();
        vector<vector<int>> f(m + 2, vector<int>(n + 2));

        int res = 0;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (matrix[i][j] == '1') {
                    f[i + 1][j + 1] = min(f[i][j + 1], min(f[i][j], f[i + 1][j])) + 1;
                }
                res = max(res, f[i + 1][j + 1]);
            }
        }

        return res * res;
    }
};
// @lc code=end

