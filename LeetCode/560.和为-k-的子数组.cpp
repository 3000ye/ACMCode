#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& ls, int k) {
        int l = 0, r = 0, n = ls.size();

        int sum = ls[r], res = 0;
        while (r < n or l < n) {
            if (sum < k) {
                if (r < n - 1) sum += ls[++ r];
            }
            if (sum > k) {
                if (l < n - 1) sum -= ls[l ++];
            }
            if (sum == k) {
                res ++;
                if (r < n - 1) sum += ls[++ r];
                else sum -= ls[l ++];
            }

            if (r >= n and l >= n) break;
        }

        return res;
    }
};
// @lc code=end

