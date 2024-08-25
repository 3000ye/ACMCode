#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=756 lang=cpp
 *
 * [756] 金字塔转换矩阵
 */

// @lc code=start
class Solution {
public:
    unordered_map<string, vector<char>> dic;
    bool pyramidTransition(string bottom, vector<string>& allowed) {
        int l = bottom.size();
        vector<string> ls(l); ls[l - 1] = bottom;

        for (auto s : allowed) dic[s.substr(0, 2)].emplace_back(s[2]);

        return dfs(ls, l - 1, 0);
    }

    bool dfs(vector<string>& ls, int r, int c) {
        if (r == c) { c = 0; r --; }
        if (r == 0) return true;

        auto temp = ls[r].substr(c, 2);
        if (dic.find(temp) == dic.end()) return false;

        for (auto ch: dic[temp]) {
            ls[r - 1].push_back(ch);

            if (dfs(ls, r, c + 1)) return true;

            // 恢复现场
            ls[r - 1].pop_back();
        }

        return false;
    }
};
// @lc code=end

