#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=139 lang=cpp
 *
 * [139] 单词拆分
 */

// @castor solve=start
// 动态规划：设当前下标为 idx
// 1. f(idx) 表示从 [0, idx] 的子串能否由字典中单词组成
// 2. 双重遍历，若 s[i, j] in Dict 且 f(i) = true，则 f(j) = true
// @castor solve=end

// @lc code=start
class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string, int> dic;
        for (auto s : wordDict) dic[s] ++;

        vector<bool> ls(s.size() + 1, false);
        ls[0] = true;

        for (int i = 0, l = s.size(); i < l; i ++) {
            for (int j = i + 1; j <= l; j ++) {
                auto temp = s.substr(i, j - i);

                if (ls[i] and dic.count(temp)) ls[j] = true;
            }
        }

        return ls.back();
    }
};
// @lc code=end

