#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=378 lang=cpp
 *
 * [378] 有序矩阵中第 K 小的元素
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>>& matrix, int k) {
        vector<int> ls;
        for (auto v : matrix) ls.insert(ls.end(), v.begin(), v.end());

        sort(ls.begin(), ls.end());

        return ls[k - 1];
    }
};
// @lc code=end

