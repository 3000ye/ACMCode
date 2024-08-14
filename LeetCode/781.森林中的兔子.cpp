#include <bits/stdc++.h>
#include <unordered_map>
using namespace std;

/*
 * @lc app=leetcode.cn id=781 lang=cpp
 *
 * [781] 森林中的兔子
 */

// @castor solve=start
// 哈希表
// 1. 记录每个数字出现的次数
// 2. 若有 x 只兔子有相同颜色，则至少需要 x + 1 只兔子
// 3. 每满 x + 1 次，则需要再增加 x + 1 只
// @castor solve=end

// @lc code=start
class Solution {
public:
    int numRabbits(vector<int>& answers) {
        unordered_map<int, int> dic;
        for (auto i : answers) dic[i] ++;

        int res = 0;
        for (auto [k, v] : dic) {
            int x = k + 1;
            int a = v / x, b = v % x;

            if (b > 0) res += a * x + x;
            else res += a * x;
        }

        return res;
    }
};
// @lc code=end

