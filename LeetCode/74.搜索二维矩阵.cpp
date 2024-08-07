#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=74 lang=cpp
 *
 * [74] 搜索二维矩阵
 */

// @lc code=start
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int m = matrix.size(), n = matrix[0].size();
        int l = 0, r = m - 1;
        while (l <= r) {
            int mid = l + ((r - l) / 2);

            if (matrix[mid][0] > target) r = mid - 1;
            else if (matrix[mid][n - 1] < target) l = mid + 1;
            else {
                // cout << mid << endl;
                auto it = find(matrix[mid].begin(), matrix[mid].end(), target);
                if (it == matrix[mid].end()) return false;
                else return true;
            }
        }

        return false;
    }
};
// @lc code=end

