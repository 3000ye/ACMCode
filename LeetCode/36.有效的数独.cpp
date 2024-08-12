#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=36 lang=cpp
 *
 * [36] 有效的数独
 */

// @lc code=start
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        unordered_map<char, int> row, col;
        for (int i = 0; i < 9; i ++) {
            for (int j = 0; j < 9; j ++) {
                // cout << i << " " << j << endl;
                if (board[i][j] != '.') row[board[i][j]] ++;
                if (board[j][i] != '.') col[board[j][i]] ++;
                
                // cout << board[i][j] << " " << board[j][i] << endl;

                if (row[board[i][j]] >= 2 or col[board[j][i]] >= 2) return false;
            }
            row.clear(); col.clear();
        }

        unordered_map<char, int> dic;
        for (int i = 0; i < 3; i ++) {
            for (int j = 0; j < 3; j ++) {
                for (int p = i * 3; p < i * 3 + 3; p ++) {
                    for (int q = j * 3; q < j * 3 + 3; q ++) {
                        if (board[p][q] != '.') dic[board[p][q]] ++;

                        if (dic[board[p][q]] >= 2) return false;
                    }
                }

                dic.clear();
            }
        }

        return true;
    }
};
// @lc code=end

