#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=316 lang=cpp
 *
 * [316] 去除重复字母
 */

// @lc code=start
class Solution {
public:
    string removeDuplicateLetters(string s) {
        vector<int> ls(26), flag(26);
        for (auto c : s) ls[c - 'a'] ++;

        string ans;
        for (auto c : s) {
            ls[c - 'a'] --;
            if (flag[c - 'a']) continue;

            while (!ans.empty() and c < ans.back() and ls[ans.back() - 'a']) {
                flag[ans.back() - 'a'] = false;
                ans.pop_back();
            }

            ans += c;
            flag[c - 'a'] = true;
        }

        return ans;
    }
};
// @lc code=end

