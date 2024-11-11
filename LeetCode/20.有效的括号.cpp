/*
 * @lc app=leetcode.cn id=20 lang=cpp
 * @lcpr version=20003
 *
 * [20] 有效的括号
 */


// @lcpr-template-start
#include "bits/stdc++.h"
#include <unordered_map>
using namespace std;
#define ll long long
#define ld long double
// @lcpr-template-end
// @lc code=start
class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> dic = {
            {'(', ')'},
            {'[', ']'},
            {'{', '}'}
        };

        for (auto c : s) {
            if (stk.empty() or dic[stk.top()] != c) stk.push(c);
            else stk.pop();
        }

        return stk.empty();
    }
};
// @lc code=end



/*
// @lcpr case=start
// "()"\n
// @lcpr case=end

// @lcpr case=start
// "()[]{}"\n
// @lcpr case=end

// @lcpr case=start
// "(]"\n
// @lcpr case=end

// @lcpr case=start
// "([])"\n
// @lcpr case=end

 */

