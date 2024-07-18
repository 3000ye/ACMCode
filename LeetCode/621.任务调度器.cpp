#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=621 lang=cpp
 *
 * [621] 任务调度器
 */

// @castor solve=start
// 首先按照出现次数对每个任务进行排序
// 假设任务 `A` 出现次数最多，且有 k 个任务和 `A` 出现次数相同
// 则可以构造：AxxxxAxxxxAxxxxA，最低长度为 `res = (cntA - 1) * (n + 1) + (k + 1)`
// 但是可能出现一种情况：其他任务出现次数较少，但其他任务数量多，会导致 `res < tasks.size()`
// 因此需要在最后特判一下，若 `res < tasks.size()` 则至少需要 `tasks.size()` 时间
// @castor solve=end

// @lc code=start
class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int> ls(26, 0);
        for (auto t : tasks) { ls[t - 'A'] ++; }
        sort(ls.begin(), ls.end(), [](int a, int b) { return a > b; });

        int res = (ls[0] - 1) * (n + 1);
        for (int i = 0; i < 26; i ++) {
            if (ls[i] == ls[0]) res ++;
        }

        return res >= tasks.size() ? res : tasks.size();
    }
};
// @lc code=end

