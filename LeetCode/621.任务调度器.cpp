#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @lc code=start
typedef pair<int, int> pii;

class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> ls(26, 0);
        for (auto t : tasks) { ls[t - 'A'] ++; }
        sort(ls.begin(), ls.end(), [](int a, int b) { return a > b; });

        
    }
};
// @lc code=end

