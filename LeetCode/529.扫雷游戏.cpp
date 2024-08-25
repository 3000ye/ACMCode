#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=529 lang=cpp
 *
 * [529] 扫雷游戏
 */

// @castor solve=start
// 深度优先遍历
// @castor solve=end

// @lc code=start
class Solution {
public:
    int dx[8] = {0, 1, 0, -1, 1, 1, -1, -1};
    int dy[8] = {1, 0, -1, 0, 1, -1, 1, -1};

    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int a = click[0], b = click[1];

        if (board[a][b] == 'M') board[a][b] = 'X';
        else dfs(board, a, b);

        return board;
    }

    void dfs(vector<vector<char>>& dic, int a, int b) {
        int cnt = 0;
        for (int i = 0; i < 8; ++i) {
            int tx = a + dx[i];
            int ty = b + dy[i];
            if (tx < 0 or tx >= dic.size() or ty < 0 or ty >= dic[0].size()) {
                continue;
            }
            cnt += dic[tx][ty] == 'M';
        }

        if (cnt > 0) dic[a][b] = cnt + '0';
        else {
            dic[a][b] = 'B';
            for (int i = 0; i < 8; ++i) {
                int tx = a + dx[i];
                int ty = b + dy[i];
                if (tx < 0 or tx >= dic.size() or ty < 0 or ty >= dic[0].size() or dic[tx][ty] != 'E') {
                    continue;
                }

                dfs(dic, tx, ty);
            }
        }
    }
};
// @lc code=end

