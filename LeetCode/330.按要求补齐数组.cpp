#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=330 lang=cpp
 *
 * [330] 按要求补齐数组
 */

// @lc code=start
class Solution {
public:
    int minPatches(vector<int> &nums, int n) {
        int res = 0, i = 0;
        long long s = 1;
        while (s <= n) {
            if (i < nums.size() and nums[i] <= s) {
                s += nums[i++];
            } 
            else {
                s *= 2; res++;
            }
        }
        return res;
    }
};
// @lc code=end

