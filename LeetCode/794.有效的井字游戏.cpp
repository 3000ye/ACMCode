#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=794 lang=cpp
 *
 * [794] 有效的井字游戏
 */

// @castor solve=start
// 1. 先手赢则 `X` 比 `O` 的数量多 `1`
// 2. 后手赢则 `X` 和 `O` 的数量相同
// 3. 不能同时都赢
// 4. `X` 的数量只能和 `O` 相同或多 `1`
// @castor solve=end

// @lc code=start
class Solution {
public:
    bool validTicTacToe(vector<string>& board) {
        // 记录 X 和 O 的数量
        int cntx = 0, cnto = 0;
        for (auto s : board) {
            for (auto c : s) {
                if (c == 'X') cntx ++;
                if (c == 'O') cnto ++;
            }
        }
        if (cntx < cnto or cntx > cnto + 1) return false;

        // 判断谁是赢家
        bool winx = false, wino = false;
        string tempx = "", tempy = "";
        for (int i = 0; i < 3; i ++) {
            string tempw = "", temph = "";
            for (int j = 0; j < 3; j ++) {
                tempw += board[i][j]; temph += board[j][i];
                if (i == j) tempx += board[i][j];
                if (i + j == 2) tempy += board[i][j];
            }

            if (tempw == "XXX" or temph == "XXX") winx = true;
            if (tempw == "OOO" or temph == "OOO") wino = true;
        }

        if (tempx == "XXX" or tempy == "XXX") winx = true;
        if (tempx == "OOO" or tempy == "OOO") wino = true;

        if (winx and wino) return false;
        else if (winx and cntx == cnto) return false;
        else if (wino and cntx != cnto) return false;

        return true;
    }
};
// @lc code=end

