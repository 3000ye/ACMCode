#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=130 lang=cpp
 *
 * [130] 被围绕的区域
 */

// @lc code=start
class Solution {
public:
    int res[300][300] = {0};
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    void solve(vector<vector<char>>& board) {
        int m = board.size(), n = board[0].size();

        for (int i = 0; i < m; i ++) {
            dfs(board, i, 0); dfs(board, i, n - 1);
        }

        for (int i = 1; i < n - 1; i ++) {
            dfs(board, 0, i); dfs(board, m - 1, i);
        }

        for (int i = 0; i < m; i ++) {
            for (int j = 0; j < n; j ++) {
                if (board[i][j] == 'O' and res[i][j] == 0) {
                    board[i][j] = 'X';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& b, int r, int c) {
        if (r < 0 or r >= b.size() or c < 0 or c >= b[0].size() or b[r][c] == 'X' or res[r][c] == 1) return ;

        res[r][c] = 1;
        for (int i = 0; i < 4; i ++) {
            dfs(b, r + dx[i], c + dy[i]);
        }
    }
};
// @lc code=end

