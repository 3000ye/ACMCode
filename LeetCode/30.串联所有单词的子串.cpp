#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
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
        vector<int> res;
        int n = s.size(), x = words.size(), y = words[0].size(), l = x * y;
        unordered_map<string, int> target;
        for (auto w : words) target[w] ++;

        vector<unordered_map<string, int>> ls(y);
        for (int i = 0; i < y and i + l <= n; i ++) {
            for (int j = i; j < i + l; j += y) {
                auto w = s.substr(j, y);
                ls[i][w] ++;
            }

            if (ls[i] == target) res.push_back(i);
        }

        for (int i = y; i + l <= n; i ++) {
            int r = i % y;
            auto sa = s.substr(i - y, y), sb = s.substr(i + l - y, y);
            if (-- ls[r][sa] == 0) ls[r].erase(sa);
            ls[r][sb] ++;

            if (ls[r] == target) res.push_back(i);
        }

        return res;
    }
};
// @lc code=end

