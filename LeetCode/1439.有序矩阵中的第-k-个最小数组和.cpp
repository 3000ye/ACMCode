#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1439 lang=cpp
 *
 * [1439] 有序矩阵中的第 k 个最小数组和
 */

// @lc code=start
class Solution {
public:
    int kthSmallest(vector<vector<int>> &mat, int k) {
        vector<int> ls = {0};
        for (auto &row: mat) {
            vector<int> temp;
            for (int x: ls)
                for (int y: row)
                    temp.push_back(x + y);
            sort(temp.begin(), temp.end());
            if (temp.size() > k) temp.resize(k);
            ls = std::move(temp);
        }
        return ls.back();
    }
};

// @lc code=end

