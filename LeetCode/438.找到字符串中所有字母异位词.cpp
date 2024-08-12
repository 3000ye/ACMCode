#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=438 lang=cpp
 *
 * [438] 找到字符串中所有字母异位词
 */

// @castor solve=start
// 滑动窗口，维护一个数组来存储每个字母的个数，每次滑动都和目标进行对比
// @castor solve=end

// @lc code=start
class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        if (s.size() < p.size()) return {};

        int l = 0, r = p.size() - 1, n = s.size();
        vector<int> ls(26, 0), ps(26, 0);
        for (int i = l; i <= r; i ++) {
            ls[s[i] - 'a'] ++; ps[p[i] - 'a'] ++;
        }

        vector<int> res;
        while (r < n) {
            if (ls == ps) res.push_back(l);
            
            ls[s[l ++] - 'a'] --;
            if (r + 1 < n) ls[s[++ r] - 'a'] ++;
            else break;
        }

        return res;
    }
};
// @lc code=end

