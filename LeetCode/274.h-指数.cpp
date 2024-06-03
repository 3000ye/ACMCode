#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=274 lang=cpp
 *
 * [274] H 指数
 */


// @lc code=start
class Solution {
public:
    static bool cmp(int a, int b) { return a > b; }

    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), cmp);

        for (int i = 0, l = citations.size(); i < l; i ++) {
            if (i + 1 > citations[i]) return i;
        }

        return citations.size();
    }
};
// @lc code=end

