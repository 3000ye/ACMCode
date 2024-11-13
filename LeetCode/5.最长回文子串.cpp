/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=20003
 *
 * [5] 最长回文子串
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
    string longestPalindrome(string s) {
        int res = 1, idx = 0, n = s.size();
        bool dp[1010][1010] = {false};

        // for (int i = 0; i < n; i ++) {
        //     // cout << "-----------" << endl;
        //     for (int j = i; j < n; j ++) {
        //         if (j - i >= 2) dp[i][j] = dp[i + 1][j - 1] and s[i] == s[j];
        //         else dp[i][j] = s[i] == s[j];

        //         // cout << i << " " << j << endl;

        //         if (dp[i][j] and j - i + 1 > res) {
        //             cout << i << " " << j << endl;
        //             res = j - i + 1; idx = i;
        //         }
        //     }
        // }

        for (int j = 0; j < n; j ++) {
            for (int i = j; i >= 0; i --) {
                if (j - i >= 2) dp[i][j] = dp[i + 1][j - 1] and s[i] == s[j];
                else dp[i][j] = s[i] == s[j];

                if (dp[i][j] and j - i + 1 > res) {
                    res = j - i + 1; idx = i;
                }
            }
        }

        return s.substr(idx, res);
    }
};
// @lc code=end



/*
// @lcpr case=start
// "babad"\n
// @lcpr case=end

// @lcpr case=start
// "cbbd"\n
// @lcpr case=end

 */

