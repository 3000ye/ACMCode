#include <algorithm>
#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=743 lang=cpp
 *
 * [743] 网络延迟时间
 */

// @lc code=start
class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // 存储图
        vector<vector<int>> dic(n + 1, vector<int>(n + 1, 999999));
        for (auto t : times) {
            dic[t[0]][t[1]] = t[2];
        }

        // Dijkstra 最短路
        vector<int> dis(n + 1, 999999), flag(n + 1);
        dis[k] = 0;
        while (1) {
            int idx = -1;
            for (int i = 1; i <= n; i ++) {
                if (!flag[i] and (idx < 0 or dis[i] < dis[idx])) {
                    idx = i;
                }
            }

            if (idx < 0) return *max_element(dis.begin() + 1, dis.end());
            if (dis[idx] == 999999) return -1;

            flag[idx] = true;
            // 更新最短路
            for (int i = 1; i <= n; i ++) {
                dis[i] = min(dis[i], dis[idx] + dic[idx][i]);
            }
        }
    }
};
// @lc code=end

