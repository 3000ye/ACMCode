#include <bits/stdc++.h>
#include <string>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=93 lang=cpp
 *
 * [93] 复原 IP 地址
 */

// @lc code=start
class Solution {
public:
    vector<string> res;
    vector<int> path;

    vector<string> restoreIpAddresses(string s) {
        if (s.size() < 4 or s.size() > 12) return res;
        dfs(s, 0);
        return res;
    }

    void dfs(string& s, int cur) {
        // path 长度为 4 且 走到终点时终止
        if (path.size() == 4) {
            if (cur == s.size()) {
                string temp = "";
                for (auto i : path) { temp += std::to_string(i); temp += "."; }
                temp.pop_back();

                res.push_back(temp);
            }

            return;
        }

        // 走到终点但是 path 长度不够，直接终止
        if (cur == s.size()) return;

        // 开始搜索
        // s[cur] = 0 的时候特判
        if (s[cur] == '0') {
            path.push_back(0);
            dfs(s, cur + 1);

            path.pop_back();
            return;
        }

        // 一般情况
        int sum = 0;
        for (int i = cur, l = s.size(); i < l; i ++) {
            sum = sum * 10 + (s[i] - '0');
            if (sum <= 255) {
                path.push_back(sum);
                dfs(s, i + 1);

                // 恢复现场
                path.pop_back();
            }
            else break;
        }
    }
};
// @lc code=end