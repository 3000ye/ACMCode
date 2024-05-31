#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=169 lang=cpp
 *
 * [169] 多数元素
 */

// @lc code=start
class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int k = nums.size() / 2;
        sort(nums.begin(), nums.end());

        int cnt = 0, x = nums[0];
        for (auto i : nums) {
            if (i == x) cnt ++;
            else {
                if (cnt > k) break;
                
                cnt = 1; x = i;
            }
        }

        return x;
    }
};
// @lc code=end

