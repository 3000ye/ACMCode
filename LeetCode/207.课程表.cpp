#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=207 lang=cpp
 *
 * [207] 课程表
 */

// @castor solve=start
// 拓扑排序 Kahn 算法
// 1. 记录每个点的入度和每条边
// 2. 将入度为 0 的节点的边去掉，不断增加新的入度为 0 节点
// 3. 若将所有节点都找到则成功，反之图中存在环，失败
// @castor solve=end

// @lc code=start
class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> grid(numCourses);
        vector<int> ls(numCourses);
        for (auto i : prerequisites) {
            ls[i[1]] ++; grid[i[0]].emplace_back(i[1]);
        }

        stack<int> stk;
        for (int i = 0; i < numCourses; i ++) {
            if (ls[i] == 0) stk.push(i);
        }

        vector<int> res;
        while (!stk.empty()) {
            auto u = stk.top(); stk.pop(); res.emplace_back(u);

            for (auto v : grid[u]) {
                if (-- ls[v] == 0) stk.push(v);
            }
        }

        return res.size() == numCourses;
    }
};
// @lc code=end

