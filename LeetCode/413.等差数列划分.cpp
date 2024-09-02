#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=413 lang=cpp
 *
 * [413] 等差数列划分
 */

// @castor solve=start
// 使用 dic[i][j] 表示 [i, j] 是否为等差数列
// 剪枝，每次发现不是等差数列就停止
// @castor solve=end

// @lc code=start
class Solution {
public:
    bool dic[5050][5050] = {false};
    int numberOfArithmeticSlices(vector<int>& ls) {
        int n = ls.size();

        int res = 0;
        for (int i = 0; i < n; i ++) {
            for (int j = i + 2; j < n; j ++) {
                // 剪枝，如果一开始就不满足就不要继续了
                if (i + 2 == j) {
                    if (ls[i + 1] - ls[i] != ls[j] - ls[i + 1]) break;
                    else { dic[i][j] = true; res ++; }
                }
                else {
                    if (dic[i][j - 1] and ls[j] - ls[j - 1] == ls[j - 1] - ls[j - 2]) {
                        res ++; dic[i][j] = true;
                    }
                    else break;
                }
            }
        }

        return res;
    }
};
// @lc code=end

