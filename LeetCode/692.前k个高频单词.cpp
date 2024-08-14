#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=692 lang=cpp
 *
 * [692] 前K个高频单词
 */

// @lc code=start
class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        unordered_map<string, int> dic;
        for (auto s : words) dic[s] ++;

        vector<pair<string, int>> ls(dic.begin(), dic.end());
        sort(ls.begin(), ls.end(), [](pair<string, int> a, pair<string, int> b) {
            return a.second == b.second ? a.first < b.first : a.second > b.second;
        });

        vector<string> res;
        for (int i = 0; i < k; i ++) res.push_back(ls[i].first);

        return res;
    };
};
// @lc code=end

