#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=343 lang=cpp
 *
 * [343] 整数拆分
 */

// @castor solve=start
// 数学结论
// @castor solve=end

// @lc code=start
class Solution {
public:
    int integerBreak(int n) {
        if (n <= 3) { return n - 1; }

        int x = n / 3, y = n % 3;
        if (y == 0) return (int)pow(3, x);
        else if (y == 1) return (int)pow(3, x - 1) * 4;
        else return (int)pow(3, x) * 2;
    }
};
// @lc code=end

