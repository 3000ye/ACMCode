#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=154 lang=cpp
 *
 * [154] 寻找旋转排序数组中的最小值 II
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& ls) {
        int l = 0, r = ls.size() - 2;
        while (l <= r and ls[l] == ls.back()) l ++;

        while (l <= r) {
            int mid = l + ((r - l) >> 1);
            // cout << mid << endl;

            if (ls[mid] <= ls.back()) r = mid - 1;
            else l = mid + 1;
        }

        return min(ls[l], ls[0]);
    }
};
// @lc code=end

