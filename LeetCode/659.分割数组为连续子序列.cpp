#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=659 lang=cpp
 *
 * [659] 分割数组为连续子序列
 */

// @lc code=start
class Solution {
public:
    bool isPossible(vector<int>& nums) {
        int n = nums.size();
        int dp1 = 0, dp2 = 0, dp3 = 0;
        int i = 0;

        while (i < n) {
            int start = i;
            int x = nums[i];
            while (i < n && nums[i] == x) {
                i++;
            }
            int cnt = i - start;

            if (start > 0 && x != nums[start - 1] + 1) {
                if (dp1 + dp2 > 0) {
                    return false;
                } 
                else {
                    dp1 = cnt; dp2 = dp3 = 0;
                }
            } 
            else {
                if (dp1 + dp2 > cnt) return false;
                int left = cnt - dp1 - dp2;
                int keep = min(dp3, left);
                dp3 = keep + dp2; dp2 = dp1; dp1 = left - keep;
            }
        }
        return dp1 == 0 && dp2 == 0;
    }
};
// @lc code=end

