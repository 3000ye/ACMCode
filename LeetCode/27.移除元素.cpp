#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=27 lang=cpp
 *
 * [27] 移除元素
 */

// @lc code=start
class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        int cnt = nums.size();
        vector<int> ls;

        for (auto i : nums) {
            if (i == val) cnt --;
            else ls.push_back(i);
        }

        nums = ls;
        return cnt;
    }
};
// @lc code=end

