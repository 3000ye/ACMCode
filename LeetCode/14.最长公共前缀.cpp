/*
 * @lc app=leetcode.cn id=14 lang=cpp
 * @lcpr version=20003
 *
 * [14] 最长公共前缀
 */


// @lcpr-template-start
#include "bits/stdc++.h"
using namespace std;
#define ll long long
#define ld long double
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end());

        string res = ""; int idx = 0;
        for (auto c : strs[0]) {
            if (c == strs.back()[idx]) {
                res += c; idx ++;
            }
            else break;
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// ["flower","flow","flight"]\n
// @lcpr case=end

// @lcpr case=start
// ["dog","racecar","car"]\n
// @lcpr case=end

 */

