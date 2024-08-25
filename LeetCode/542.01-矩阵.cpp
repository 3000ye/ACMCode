#include <bits/stdc++.h>
#include <climits>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=542 lang=cpp
 *
 * [542] 01 矩阵
 */

// @lc code=start
class Solution {
public:
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<vector<int>> res(m, vector<int>(n, INT_MAX));

        queue<pair<int, int>> que;
        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (mat[i][j] == 0) { res[i][j] = 0; que.push({i, j}); }
            }
        }

        while (!que.empty()) {
            auto temp = que.front(); que.pop();

            for (int i = 0; i < 4; i ++) {
                int x = temp.first + dx[i], y = temp.second + dy[i];

                if (x >= 0 and x < m and y >= 0 and y < n) {
                    if (res[x][y] > res[temp.first][temp.second] + 1) {
                        res[x][y] = res[temp.first][temp.second] + 1;
                        que.push({x, y});
                    }
                }
            }
        }

        return res;
    }
};
// @lc code=end

