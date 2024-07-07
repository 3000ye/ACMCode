#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=862 lang=cpp
 *
 * [862] 和至少为 K 的最短子数组
 */

// @lc code=start
class Solution {
public:
    int shortestSubarray(vector<int>& nums, int k) {
        queue<int> que;
        int sum = 0, cnt = 0, res = 9999999;
        bool flag = false;
        for (auto i : nums) {
            que.push(i); cnt ++; sum += i;

            while (sum - que.front() >= k) {
                sum -= que.front(); que.pop(); cnt --;
            }
            if (sum >= k) { 
                res = min(res, cnt); flag = true;
            }
        }

        if (!flag) return -1;
        else return res;
    }
};
// @lc code=end

