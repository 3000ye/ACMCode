#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=947 lang=cpp
 *
 * [947] 移除最多的同行或同列石头
 */

// @lc code=start
class Solution {
public:
    int removeStones(vector<vector<int>> &stones) {
        int l = stones.size();
        vector<vector<int>> dics(l);
        for (int i = 0; i < l; i++) {
            for (int j = 0; j < l; j++) {
                if (stones[i][0] == stones[j][0] or stones[i][1] == stones[j][1]) {
                    dics[i].push_back(j);
                }
            }
        }
        vector<int> flag(l);
        int cnt = 0;
        for (int i = 0; i < l; i++) {
            if (!flag[i]) {
                cnt++;
                dfs(i, dics, flag);
            }
        }
        return l - cnt;
    }

    void dfs(int x, vector<vector<int>> &dics, vector<int> &flag) {
        flag[x] = true;
        for (auto &y : dics[x]) {
            if (!flag[y]) {
                dfs(y, dics, flag);
            }
        }
    }
};
// @lc code=end

