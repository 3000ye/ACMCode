#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=921 lang=cpp
 *
 * [921] 使括号有效的最少添加
 */

// @lc code=start
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> stk;

        for (auto c : s) {
            if (!stk.empty() and stk.top() == '(' and c == ')') stk.pop();
            else stk.push(c);
        }

        return stk.size();
    }
};
// @lc code=end

