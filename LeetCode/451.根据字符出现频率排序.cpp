#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=451 lang=cpp
 *
 * [451] 根据字符出现频率排序
 */

// @lc code=start
class Solution {
public:
    string frequencySort(string s) {
        map<char, int> dic;
        for (auto c : s) dic[c] ++;

        vector<pair<char, int>> ls(dic.begin(), dic.end());
        sort(ls.begin(), ls.end(), [](pair<char, int> a, pair<char, int> b) {
            if (a.second == b.second) return a.first < b.first;
            else return a.second > b.second;
        });

        string res = "";
        for (auto [c, n] : ls) {
            while (n --) res += c;
        }
        
        return res;
    }
};
// @lc code=end

