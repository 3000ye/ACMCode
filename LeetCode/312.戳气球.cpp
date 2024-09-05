#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=312 lang=cpp
 *
 * [312] 戳气球
 */

// @lc code=start
class Solution {
public:
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        vector<int> ls(n + 2, 1);
        for (int i = 0; i < n; i ++) ls[i + 1] = nums[i];

        vector<vector<int>> f(n + 2, vector<int>(n + 2, 0));
        for (int i = n - 1; i >= 0; i --) {
            for (int j = i + 2; j < n + 2; j ++) {
                for (int k = i + 1; k < j; k ++) {
                    f[i][j] = max(
                        f[i][j], f[i][k] + f[k][j] + ls[i] * ls[k] * ls[j]
                    );
                }
            }
        }

        return f[0][n + 1];
    }
};
// @lc code=end

