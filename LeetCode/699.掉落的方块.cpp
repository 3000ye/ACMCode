#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=699 lang=cpp
 *
 * [699] 掉落的方块
 */

// @lc code=start
class Solution {
public:
    vector<int> fallingSquares(vector<vector<int>>& positions) {
        int i = 0, j = 0, n = positions.size(), m = 0, temp = 0, max_ = 0;
        vector<vector<int>> arr;
        vector<int> ans;

        for (i = 0; i < n; ++i) {
            temp = 0;
            for (j = 0; j < m; ++j) {
                if (!(arr[j][1] <= positions[i][0] || arr[j][0] >= positions[i][0] + positions[i][1])) {
                    temp = max(temp, arr[j][2]);
                }
            }
            arr.push_back({positions[i][0], positions[i][0] + positions[i][1], temp + positions[i][1]});
            max_ = max(max_, temp + positions[i][1]);
            ans.push_back(max_);
            ++m;
        }

        return ans;
    }
};
// @lc code=end

