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
        vector<long long > ls(nums.size() + 1, 0); ls[0] = 0;
        for (int i = 0, l = nums.size(); i < l; i ++) {
            ls[i + 1] = ls[i] + nums[i];
        }

        deque<long long> dque; long long res = 999999999999;
        for (long long i = 0, l = nums.size(); i <= l; i ++) {
            long long cur = ls[i];
            while (!dque.empty() and cur - ls[dque.front()] >= k) {
                res = min(res, i - dque.front());
                dque.pop_front();
            }

            while (!dque.empty() and ls[dque.back()] >= cur) {
                dque.pop_back();
            }

            dque.push_back(i);
        }

        return res > nums.size() ? -1 : res;
    }
};
// @lc code=end

