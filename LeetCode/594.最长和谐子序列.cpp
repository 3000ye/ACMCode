#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=594 lang=cpp
 *
 * [594] 最长和谐子序列
 */

// @lc code=start
class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int, int> dic, temp;
        for (auto i : nums) { dic[i] ++; temp[i] ++; }

        int res = 0;
        for (auto [k, v] : dic) {
            if (temp[k + 1] != 0) res = max(res, temp[k + 1] + v);
            if (temp[k - 1] != 0) res = max(res, temp[k - 1] + v);
        }

        return res;
    }
};
// @lc code=end

