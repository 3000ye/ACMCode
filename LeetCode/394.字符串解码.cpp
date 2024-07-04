#include <algorithm>
#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=394 lang=cpp
 *
 * [394] 字符串解码
 */

// @castor solve=start
// 遍历 s 并将元素 c 压入栈 stk
// 遇到 ']' 时则开始弹出，遇到 '[' 时停止，记录为 temp
// 继续弹出，记录数字 num
// 将 num 个 temp 重新入栈
// 最终 res 需反转一次
// @castor solve=end

// @lc code=start
class Solution {
public:
    string decodeString(string s) {
        string res = "";
        stack<char> stk;

        for (auto c : s) {
            if (c == ']') {
                string temp = "", num = "";
                while (stk.top() != '[') { temp += stk.top(); stk.pop(); }
                stk.pop();
                while (!stk.empty() and stk.top() >= '0' and stk.top() <= '9') { num += stk.top(); stk.pop(); }
                reverse(num.begin(), num.end());
                reverse(temp.begin(), temp.end());
                int n = stoi(num);
                while (n --) {
                    for (auto t : temp) stk.push(t);
                }
                // cout << num << " " << temp << endl;
            }
            else stk.push(c);
        }

        while (!stk.empty()) { res += stk.top(); stk.pop(); }
        reverse(res.begin(), res.end());

        return res;
    }
};
// @lc code=end

