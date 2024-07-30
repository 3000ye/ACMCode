#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=327 lang=cpp
 *
 * [327] 区间和的个数
 */

// @lc code=start
class Solution {
public:
    int countRangeSum(vector<int> &nums, int lower, int upper) {
        int n = nums.size();
        long long sum = 0;
        multiset<long long> set;
        set.insert(0);
        int res = 0;
        for (int i = 0; i < n; i++) {
            sum += nums[i];
            res += distance(set.lower_bound(sum - upper),
                            set.upper_bound(sum - lower));
            set.insert(sum);
        }
        return res;
    }
};
// @lc code=end
