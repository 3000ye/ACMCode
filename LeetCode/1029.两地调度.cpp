#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1029 lang=cpp
 *
 * [1029] 两地调度
 */

// @lc code=start
class Solution {
public:
    int twoCitySchedCost(vector<vector<int>>& ls) {
        sort(ls.begin(), ls.end(), [](vector<int> a, vector<int> b) {
            return a[0] - a[1] < b[0] - b[1];
        });

        int sum = 0, n = ls.size() / 2;
        for (int i = 0; i < n; i ++) {
            sum += ls[i][0] + ls[n + i][1];
        }

        return sum;
    }
};
// @lc code=end

