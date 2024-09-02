#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1345 lang=cpp
 *
 * [1345] 跳跃游戏 IV
 */

// @castor solve=start
// 宽度优先遍历
// @castor solve=end

// @lc code=start
class Solution {
public:
    int minJumps(vector<int>& arr) {
        const int inf = 0x3f3f3f3f;
        int n = arr.size();
        unordered_map<int, vector<int>> dic;
        for(int i = n - 1; ~i; i--) {
            dic[arr[i]].push_back(i);
        }
        vector<int> ls(n, inf); queue<int> que;
        que.push(0); ls[0] = 0;

        while(!que.empty()) {
            auto t = que.front(), sss = ls[t]; que.pop();

            if(t == n - 1) return sss;
            if(t + 1 < n and ls[t + 1] == inf) {
                que.push(t + 1);
                ls[t + 1] = sss + 1;
            }
            if(t - 1 >= 0 and ls[t - 1] == inf) {
                que.push(t - 1);
                ls[t - 1] = sss + 1;
            }
            const auto& list = dic[arr[t]];
            for(auto ne :list) {
                if(ls[ne] == inf) {
                    que.push(ne); ls[ne] = sss + 1;
                }
            }
            dic[arr[t]].clear();
        }
        return -1;
    }
};
// @lc code=end

