/*
 * @lc app=leetcode.cn id=5 lang=cpp
 * @lcpr version=20003
 *
 * [5] 最长回文子串
 */


// @lcpr-template-start
#include "bits/stdc++.h"
#include <algorithm>
using namespace std;
#define ll long long
#define ld long double
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    string longestPalindrome(string s) {
        int l = 0, r = 0, n = s.size();
        string res = "";

        while (l < n and r < n) {
            string temp = s.substr(l, r + 1);
            
            r ++;
        }

        return res;
    }

    bool isPalindrome(string s) {
        string temp = s;
        reverse(s.begin(), s.end());
        return temp == s;
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

