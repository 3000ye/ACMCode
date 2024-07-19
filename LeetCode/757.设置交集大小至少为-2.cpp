#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=757 lang=cpp
 *
 * [757] 设置交集大小至少为2
 */

// @lc code=start
class Solution {
public:
    int solve(vector<vector<int>>& ls) {
        sort(ls.begin(), ls.end(), [](const auto& a, const auto& b) {
            return a[1] != b[1] ? a[1] < b[1] : a[0] > b[0];
        });

        int res = 2; int end = ls[0][1]; int temppp = end - 1;
        for (int i = 1; i < ls.size(); ++i) {
            if (ls[i][0] <= temppp) { continue; } 
            else if (ls[i][0] <= end) {
                res += 1; temppp = end; end = ls[i][1];
            } 
            else {
                res += 2; end = ls[i][1]; temppp = end - 1;
            }
        }

        return res;
    }
};
// @lc code=end

