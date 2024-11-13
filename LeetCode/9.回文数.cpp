/*
 * @lc app=leetcode.cn id=9 lang=cpp
 * @lcpr version=20003
 *
 * [9] 回文数
 */


// @lcpr-template-start
#include "bits/stdc++.h"
#include <vector>
using namespace std;
#define ll long long
#define ld long double
// @lcpr-template-end
// @lc code=start
#define ll long long
#define ld long double
class Solution {
public:
    bool isPalindrome(int x) {
        if (x < 0) return false;
        return x == toLL(toList(x));
    }

    ll toLL(vector<int> ls) {
        ll res = 0, cur = 1;
        for (auto i : ls) {
            res *= 10;
            res += i;
        }

        return res;
    }

    vector<int> toList(int x) {
        vector<int> ls;
        while (x > 0) {
            int temp = x % 10;
            x /= 10;
            ls.push_back(temp);
        }

        return ls;
    }
};
// @lc code=end



/*
// @lcpr case=start
// 121\n
// @lcpr case=end

// @lcpr case=start
// -121\n
// @lcpr case=end

// @lcpr case=start
// 10\n
// @lcpr case=end

 */

