#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=554 lang=cpp
 *
 * [554] 砖墙
 */

// @castor solve=start
// 哈希表+前缀和
// 1. 每个边缘实际就是前缀和
// 2. 记录每个边缘的数量，找出最大的那个数量即可
// @castor solve=end

// @lc code=start
class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        unordered_map<int, int> dic;

        for (auto ls : wall) {
            int cnt = 0;
            for (auto i : ls) {
                cnt += i;
                dic[cnt] ++;
            }
        }

        vector<pair<int, int>> res(dic.begin(), dic.end());
        sort(res.begin(), res.end(), [](pair<int, int> a, pair<int, int> b) {return a.second > b.second; });

        if (res.size() == 1) return wall.size();
        else return wall.size() - res[1].second;
    }
};
// @lc code=end

