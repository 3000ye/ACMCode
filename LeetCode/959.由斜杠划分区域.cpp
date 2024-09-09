#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=959 lang=cpp
 *
 * [959] 由斜杠划分区域
 */

// @lc code=start
class Solution {
public:
    int regionsBySlashes(vector<string> &dics) {
        int res = 0;
        vector<vector<int>> g(dics.size() * 3, vector<int>(dics[0].size() * 3, 0));
        for (int i = 0; i < dics.size(); i++) {
            for (int j = 0; j < dics.size(); j++) {
                if (dics[i][j] == '/')
                    g[i * 3 + 2][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3][j * 3 + 2] = 1;
                else if (dics[i][j] == '\\')
                    g[i * 3][j * 3] = g[i * 3 + 1][j * 3 + 1] = g[i * 3 + 2][j * 3 + 2] = 1;
            }
        }

        for (int i = 0; i < g.size(); i++) {
            for (int j = 0; j < g[0].size(); j++) {
                if (g[i][j] == 0) {
                    dfs(g, i, j); res++;
                }
            }
        }

        return res;
    }

    void dfs(vector<vector<int>> &dics, int i, int j) {
        if (i >= 0 && i < dics.size() && j >= 0 && j < dics[0].size() && dics[i][j] == 0) {
        dics[i][j] = 1;
        dfs(dics, i + 1, j);
        dfs(dics, i - 1, j);
        dfs(dics, i, j + 1);
        dfs(dics, i, j - 1);
        }
    }
};
// @lc code=end
