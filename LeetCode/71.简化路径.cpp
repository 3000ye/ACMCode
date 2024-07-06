#include <bits/stdc++.h>
#include <cerrno>
using namespace std;

/*
 * @lc app=leetcode.cn id=71 lang=cpp
 *
 * [71] 简化路径
 */

// @castor solve=start
// 分类讨论模拟，要注意栈是否为空
// @castor solve=end

// @lc code=start
class Solution {
public:
    string simplifyPath(string path) {
        stack<char> stk;
        for (auto c : path + '/') {
            if (!stk.empty() and c == '/') {
                if (stk.top() == '/') continue;
                else if (stk.top() == '.') {
                    stk.pop();
                    if (stk.empty()) stk.push(c);
                    else if (stk.top() == '.') {  // ../
                        stk.pop();
                        if (stk.empty()) stk.push(c);
                        else if (stk.top() == '/') {  // /../
                            stk.pop();
                            while (!stk.empty() and stk.top() != '/') stk.pop();
                        }
                        else if (stk.top() == '.') {  // .../
                            stk.push('.'); stk.push('.'); stk.push(c);
                        }
                        else {
                            stk.push('.'); stk.push('.'); stk.push(c);
                        }
                    }
                    else if (stk.top() == '/') {  // /./
                        continue;
                    }
                    else {  // xxx./
                        stk.push('.'); stk.push(c);
                    }
                }
                else stk.push(c);
            }
            else stk.push(c);
        }

        if (!stk.empty() and stk.top() == '/') stk.pop();
        if (stk.empty()) stk.push('/');

        string res = "";
        while (!stk.empty()) { res += stk.top(); stk.pop(); }
        reverse(res.begin(), res.end());

        return res[0] == '/' ? res : '/' + res;
    }
};
// @lc code=end

