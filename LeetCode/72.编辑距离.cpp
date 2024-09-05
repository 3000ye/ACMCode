#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=72 lang=cpp
 *
 * [72] 编辑距离
 */

// @lc code=start
class Solution {
public:
    int minDistance(string word1, string word2) {
        vector<vector<int>> f(word1.size() + 1, vector<int>(word2.size() + 1, 0));

        for (int i = 0, l = f.size(); i < l; i ++) { f[i][0] = i; }
        for (int j = 0, l = f[0].size(); j < l; j ++) { f[0][j] = j; }

        for (int i = 1, l = f.size(); i < l; i ++) {
            for (int j = 1, k = f[i].size(); j < k; j ++) {
                f[i][j] = min(f[i - 1][j - 1], min(f[i - 1][j], f[i][j - 1])) + 1;

                if (word1[i - 1] == word2[j - 1]) {
                    f[i][j] = min(f[i][j], f[i - 1][j - 1]);
                }
            }
        }

        return f.back().back();
    }
};
// @lc code=end

