#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=861 lang=cpp
 *
 * [861] 翻转矩阵后的得分
 */

// @lc code=start
class Solution {
public:
    int matrixScore(vector<vector<int>>& A) {
        if (A.empty()) return 0;
        int res = 0;
        int row = A.size(), col = A[0].size();
        for (int i = 0; i < row; ++i) {
            if (A[i][0] == 0) {
                for (int j = 0; j < col; ++j) {
                    A[i][j] = (1 - A[i][j]);
                }
            }
        }
        for (int j = 1; j < col; ++j) {
            int cnt = 0;
            for (int i = 0; i < row; ++i) {
                if (A[i][j] == 0) {
                    ++cnt;
                }
            }
            if (cnt > (row - cnt)) {
                for (int i = 0; i < row; ++i) {
                    A[i][j] = (1 - A[i][j]);
                }
            }
        }
        for (int i = 0; i < row; ++i) {
            for (int j = col - 1; j >= 0; --j) {
                res += A[i][j] * int(pow(2, col - 1 - j));
            }
        }
        return res;
    }
};
// @lc code=end

