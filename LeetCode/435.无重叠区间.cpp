#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=435 lang=cpp
 *
 * [435] 无重叠区间
 */

// @lc code=start
class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        if (intervals.empty()) { return 0; }
        
        sort(intervals.begin(), intervals.end(), [](const auto& u, const auto& v) { return u[1] < v[1]; });

        int l = intervals.size();
        int idx = intervals[0][1];
        int res = 1;
        for (int i = 1; i < l; ++i) {
            if (intervals[i][0] >= idx) {
                ++res;
                idx = intervals[i][1];
            }
        }
        return l - res;
    }
};
// @lc code=end

