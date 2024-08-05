#include <bits/stdc++.h>
#include <utility>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=997 lang=cpp
 *
 * [997] 找到小镇的法官
 */

// @lc code=start
class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if (n == 1 and trust.size() == 0) return 1;
        
        // ls[i].first 存 i 信任的人数，ls[i].second 存信任 i 的人数
        vector<pair<int, int>> ls(1010);
        for (auto t : trust) {
            int a = t[0], b = t[1];
            ls[a].first ++; ls[b].second ++;
        }

        // 寻找满足 ls[i].first = 0, ls[i].second = n - 1 的人
        vector<int> res;
        for (int i = 0; i <= n; i ++) {
            if (ls[i].first == 0 and ls[i].second == n - 1) res.push_back(i);
        }

        if (res.size() != 1) return -1;
        else return res[0];
    }
};
// @lc code=end

