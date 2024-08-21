#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=63 lang=cpp
 *
 * [63] 不同路径 II
 */

// @castor solve=start
// 动态规划：扩大数组规模降低代码量
// f(x, y) = f(x - 1, y) + f(x, y - 1), G(i, j) != 1
// @castor solve=end

// @lc code=start
class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m = obstacleGrid.size(), n = obstacleGrid[0].size();
        vector<vector<int>> dic(m + 1, vector<int> (n + 1, 0));

        dic[1][1] = 1;
        for (int i = 1; i <= m; i ++) {
            for (int j = 1; j <= n; j ++) {
                if (i > 1 and obstacleGrid[i - 2][j - 1] == 0) dic[i][j] += dic[i - 1][j];
                if (j > 1 and obstacleGrid[i - 1][j - 2] == 0) dic[i][j] += dic[i][j - 1];
            }
        }

        return obstacleGrid[m - 1][n - 1] == 1 ? 0 : dic[m][n];
    }
};
// @lc code=end

