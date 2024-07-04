#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1190 lang=cpp
 *
 * [1190] 反转每对括号间的子串
 */

// @castor solve=start
// 遍历 s 并将元素 c 压入栈 stk
// 遇到 ')' 时则开始弹出，遇到 '(' 时停止
// 反转弹出的部分，再重新压入栈
// @castor solve=end

// @lc code=start
class Solution {
public:
    string reverseParentheses(string s) {
        stack<char> stk;
        s = '(' + s + ')';
        for (auto c : s) {
            if (c == ')') {
                string temp = "";
                while (!stk.empty() and stk.top() != '(') {
                    temp += stk.top(); stk.pop();
                }
                if (stk.top() == '(') stk.pop();

                for (auto t : temp) {
                    stk.push(t);
                }
            }
            else stk.push(c);
        }

        string res = "";
        while (!stk.empty()) {
            res += stk.top(); stk.pop();
        }

        return res;
    }
};
// @lc code=end

