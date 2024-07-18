#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=347 lang=cpp
 *
 * [347] 前 K 个高频元素
 */

// @castor solve=start
// 使用字典记录每个元素出现的频率，然后按频率排序，记录前 `k` 个即可。
// @castor solve=end

// @lc code=start
class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        map<int, int> dic;
        for (auto i : nums) { dic[i] ++; }

        vector<pair<int, int>> ls(dic.begin(), dic.end());
        sort(ls.begin(), ls.end(), [](pair<int, int> a, pair<int, int> b) {
            if (a.second == b.second) return a.first > b.first;
            else return a.second > b.second;
        });

        vector<int> res;
        for (int i = 0; i < k; i ++) res.push_back(ls[i].first);

        return res;
    }
};
// @lc code=end

