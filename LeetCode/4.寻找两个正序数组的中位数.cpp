/*
 * @lc app=leetcode.cn id=4 lang=cpp
 * @lcpr version=20003
 *
 * [4] 寻找两个正序数组的中位数
 */


// @lcpr-template-start
#include "bits/stdc++.h"
#include <vector>
using namespace std;
#define ll long long
#define ld long double
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        nums1.insert(nums1.end(), nums2.begin(), nums2.end());
        sort(nums1.begin(), nums1.end());

        int m = nums1.size() >> 1;
        if (nums1.size() & 1) return nums1[m];
        else return (double)(nums1[m - 1] + nums1[m]) / 2;
    }
};
// @lc code=end



/*
// @lcpr case=start
// [1,3]\n[2]\n
// @lcpr case=end

// @lcpr case=start
// [1,2]\n[3,4]\n
// @lcpr case=end

 */

