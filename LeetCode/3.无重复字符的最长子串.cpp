#include "bits/stdc++.h"
#include <unordered_map>
using namespace std;
#define ll long long
#define ld long double

/*
 * @lc app=leetcode.cn id=3 lang=cpp
 * @lcpr version=20003
 *
 * [3] 无重复字符的最长子串
 */



// @lc code=start
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> dic;
        int res = 0, l = 0, r = 0, n = s.size();

        while (r < n and l < n) {
            dic[s[r]] ++;

            if (dic[s[r]] > 1) {
                while (dic[s[r]] > 1) {
                    dic[s[l]] --; l ++;
                }
            }

            res = max(r - l + 1, res);
            r ++;
        }

        return res;
    }
};
// @lc code=end



/*
// @lcpr case=start
// "abcabcbb"\n
// @lcpr case=end

// @lcpr case=start
// "bbbbb"\n
// @lcpr case=end

// @lcpr case=start
// "pwwkew"\n
// @lcpr case=end

 */

