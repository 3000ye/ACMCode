#include <bits/stdc++.h>
#include <queue>
#include <tuple>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=373 lang=cpp
 *
 * [373] 查找和最小的 K 对数字
 */

// @lc code=start
class Solution {
public:
    vector<vector<int>> kSmallestPairs(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<vector<int>> res;
        priority_queue<tuple<int, int, int>> pque;

        for (int i = 0, l = nums1.size(); i < min(l, k); i ++) pque.emplace(-nums1[i] - nums2[0], i, 0);
        while (res.size() < k) {
            auto [_, i, j] = pque.top(); pque.pop();
            res.push_back({nums1[i], nums2[j]});

            if (j + 1 < nums2.size()) pque.emplace(-nums1[i] - nums2[j + 1], i, j + 1);
        }

        return res;
    }
};
// @lc code=end

