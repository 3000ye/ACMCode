#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=1023 lang=cpp
 *
 * [1023] 驼峰式匹配
 */

// @lc code=start
class Solution {
public:
    vector<bool> camelMatch(vector<string>& queries, string pattern) {
        vector<bool> res(queries.size(), true);

        for (int k = 0, l = queries.size(); k < l; k ++) {
            auto s = queries[k];
            int i = 0, j = 0;

            while (i < pattern.size() or j < s.size()) {
                if (pattern[i] == s[j]) { i ++; j ++;}
                else {
                    if (s[j] >= 'a' and s[j] <= 'z') j ++;
                    else { res[k] = false; break; }
                }
            }

            if (i >= pattern.size()) {
                while (j < s.size()) {
                    if (s[j] >= 'A' and s[j] <= 'Z') { res[k] = false; break; }
                }
            }
        }

        return res;
    }
};
// @lc code=end

