#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=30 lang=cpp
 *
 * [30] 串联所有单词的子串
 */

// @lc code=start
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int x = words.size(), y = words[0].size();
        if (x * y > s.size()) return {};

        set<string> target(words.begin(), words.end());
        vector<int> res;
        for (int i = 0, l = x * y, n = s.size(); i + l < n; i ++) {
            
        }
    }
};
// @lc code=end

