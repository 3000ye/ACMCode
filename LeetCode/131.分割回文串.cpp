#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=131 lang=cpp
 *
 * [131] 分割回文串
 */

// @castor solve=start
// 使用 深度搜索优先，规则是：
// 1. 从 0 开始搜索，只要遇到回文串就递归
// 2. 为了找到所有可能，遇到非回文串选择跳过而非终止
// @castor solve=end

// @lc code=start
class Solution {
public:
    vector<vector<string>> res;
    vector<string> path;
    vector<vector<string>> partition(string s) {
        dfs(0, s);
        return res;
    }

    void dfs(int cur, string s) {
        if (cur == s.size()) {
            res.push_back(path); return;
        }

        for (int i = cur, l = s.size(); i < l; i ++) {
            // 判断是否回文
            string x = s.substr(cur, i - cur + 1);
            string y = x; reverse(x.begin(), x.end());

            if (x == y) {
                path.push_back(y);
                dfs(i + 1, s);

                // 恢复现场
                path.pop_back();
            }
        }
    }
};
// @lc code=end

