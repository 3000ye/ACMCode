#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1046 lang=cpp
 *
 * [1046] 最后一块石头的重量
 */

// @lc code=start
class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        while (stones.size() > 1) {
            sort(stones.begin(), stones.end());
            int l = stones.size();
            
            if (stones[l - 1] == stones[l - 2]) {
                stones.pop_back(); stones.pop_back();
            }
            else {
                int x = stones[l - 1] - stones[l - 2];
                stones.pop_back(); stones.pop_back(); stones.push_back(x);
            }
        }

        return stones.size() != 0 ? stones[0] : 0;
    }
};
// @lc code=end

