#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=79 lang=cpp
 *
 * [79] 单词搜索
 */

// @castor solve=start
// 使用 深度搜索优先，规则是：
// 1. 从每个位置都可以开始搜索，只要有一个起点满足即可
// 2. 每次开始都判断是否满足 word，不满足则直接终止
// 3. 使用 flag 记录已经走过的路径，避免回头路
// 4. 每次都向 4 个方向延伸，只要有一个方向满足即可
// @castor solve=end

// @lc code=start
class Solution {
public:
    vector<pair<int, int>> path;
    int flag[10][10] = {0};
    int dx[4] = {0, 0, 1, -1};
    int dy[4] = {1, -1, 0, 0};

    bool exist(vector<vector<char>>& board, string word) {
        // 每一个位置都可以开始
        for (int i = 0, p = board.size(); i < p; i ++) {
            for (int j = 0, q = board[0].size(); j < q; j ++) {
                if (dfs(i, j, word, board, p, q)) {
                    return true;
                }
            }
        }

        return false;
    }

    bool dfs(int x, int y, string word, vector<vector<char>>& board, int p, int q) {
        // 剪枝: 如果当前不满足 word 则直接终止
        if (board[x][y] != word[0]) return false;

        // 加入 path，word 去头
        path.push_back(pair<int, int>(x, y));
        flag[x][y] = 1;
        char temp = word[0];
        word = word.substr(1);

        // 是否满足退出条件
        if (word == "") return true;
        else {
            // 四个方向延伸，但不能走回头路
            for (int k = 0; k < 4; k ++) {
                int tx = x + dx[k], ty = y + dy[k];

                if (tx >= 0 and tx < p and ty >= 0 and ty < q) {
                    if (flag[tx][ty] == 1) continue;
                    if (dfs(tx, ty, word, board, p, q)) return true;
                }
            }
        }

        // 恢复现场
        path.pop_back();
        flag[x][y] = 0;
        word = temp + word;

        return false;
    }
};
// @lc code=end

