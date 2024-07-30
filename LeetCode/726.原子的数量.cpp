#include <bits/stdc++.h>
#include <string>
using namespace std;

/*
 * @lc app=leetcode.cn id=726 lang=cpp
 *
 * [726] 原子的数量
 */

// @lc code=start
class Solution {
public:
    string countOfAtoms(string formula) {
        stack<int> stk; map<string, int> cnt;
        int idx = 1, flag = 0, n = formula.size();
        for (int i = n - 1; i >= 0; i--) {
            auto c = formula[i];
            if(c == ')') !flag ? stk.push(1), 0 : flag = 0;
            else if ( c=='(' ) idx /= stk.top(), stk.pop();
            else if (isdigit(c)) {
                int v = c - '0', x = i, b = 10;
                while (isdigit(formula[--x])) v += (formula[x] - '0') * b, b *= 10;                
                i = x + 1, stk.push(v), idx *= v, flag=1;
            }
            else if (isalpha(c)) {
                string s{c};
                if (islower(c)) s = string{formula[i - 1]} + s, --i;                
                cnt[s] += idx;
                if (flag) idx /= stk.top(),stk.pop(),flag= 0;                
            }
        }
        string ans;
        for(auto&[s,num]:cnt)ans+=s+(num>1?to_string(num):"");        
        return ans;
    }
};

// @lc code=end

