#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=153 lang=cpp
 *
 * [153] 寻找旋转排序数组中的最小值
 */

// @lc code=start
class Solution {
public:
    int findMin(vector<int>& ls) {
        int l = -1, r = ls.size() - 1;
        while (l + 1 < r) {
            int mid = l + ((r - l) >> 1);

            if (ls[mid] < ls.back()) r = mid;
            else l = mid;
        }

        return ls[r];
    }
};
// @lc code=end

