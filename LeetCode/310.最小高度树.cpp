#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=310 lang=cpp
 *
 * [310] 最小高度树
 */

// @castor solve=start
// 使用 深度搜索优先，规则是：
// 1. 每次都找出所有的叶子节点，然后将叶子节点去掉，最后留下的 1（或 2）个叶子节点就是答案
// 2. 每层搜索时，需要注意只能操作一层的叶子节点
// @castor solve=end

// @lc code=start
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        if (n == 1) return {0};
        // 存储图
        vector<vector<int>> adj(n); vector<int> relative(n);
        for (auto i : edges) {
            adj[i[0]].push_back(i[1]);
            adj[i[1]].push_back(i[0]);
            relative[i[0]] ++; relative[i[1]] ++;
        }

        // 找到度为 1 的节点（叶子节点）
        queue<int> que;
        for (int i = 0; i < n; i ++) {
            if (relative[i] == 1) que.push(i);
        }

        // 存储每层叶子节点（最后一层则为答案）
        vector<int> res;
        while (!que.empty()) {
            res.clear();

            // 保证每次都只操作一层数据
            int q = que.size();
            for (int _ = 0; _ < q; _ ++) {
                int cur = que.front(); que.pop(); res.push_back(cur);
                for (int i : adj[cur]) {
                    relative[i] --;
                    if (relative[i] == 1) que.push(i);
                }
            }
        }

        return res;
    }
};
// @lc code=end

