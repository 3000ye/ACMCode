#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=407 lang=cpp
 *
 * [407] 接雨水 II
 */

// @lc code=start
class Solution {
public:
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pque;
    bool dic[201][201];
    int movex[4] = {0, 0, 1, -1};
    int movey[4] = {1, -1, 0, 0};

    int trapRainWater(vector<vector<int>>& heightMap) {
        int n = heightMap.size(), m = heightMap[0].size(), res = 0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (i == 0 or i == n - 1 or j == 0 or j == m - 1) {
                    pque.push(make_pair(heightMap[i][j], make_pair(i, j)));
                    dic[i][j] = true;
                }
            }
        }

        while (!pque.empty()) {
            int h = pque.top().first, x = pque.top().second.first, y = pque.top().second.second;
            pque.pop();
            for (int i = 0; i < 4; i++) {
                int nx = movex[i] + x, ny = movey[i] + y;
                if (nx >= 0 and nx < n and ny >= 0 and ny < m and (!dic[nx][ny])) {
                    if (heightMap[nx][ny] < h) {
                        res += h - heightMap[nx][ny];
                    }
                    dic[nx][ny] = 1;
                    pque.push(make_pair(max(heightMap[nx][ny], h), make_pair(nx, ny)));
                }
            }
        }
        return res;
    }
};
// @lc code=end

