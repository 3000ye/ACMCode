#include <bits/stdc++.h>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=332 lang=cpp
 *
 * [332] 重新安排行程
 */

// @castor solve=start
// 深度优先遍历
// 1. 需满足两个条件：走完全程 + 字典序最小
// 2. 使用回溯找到所有走完全程的路线
// 3. 使用 map 的 key 有序特性，实现字典序最小
// @castor solve=end

// @lc code=start
class Solution {
public:
    // unordered_map<起点, map<终点, 次数>>
    unordered_map<string, map<string, int>> grid;
    vector<string> res;
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for (auto t : tickets) grid[t[0]][t[1]] ++;

        res.emplace_back("JFK");
        dfs(tickets.size());

        return res;
    }

    bool dfs(int n) {
        if (res.size() == n + 1) return true;

        for (auto& [k, v] : grid[res.back()]) {
            if (v > 0) {
                res.emplace_back(k); v --;
                if (dfs(n)) return true;
                res.pop_back(); v ++;
            }
        }

        return false;
    }
};
// @lc code=end

