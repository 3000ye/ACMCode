#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=860 lang=cpp
 *
 * [860] 柠檬水找零
 */

// @lc code=start
class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
        int x = 0, y = 0, z = 0;
        for (auto b : bills) {
            if (b == 5) x ++;
            else if (b == 10) {
                if (x > 0) { x --; y ++;}
                else return false;
            }
            else {  // 20 块
                if (y > 0) {
                    y --;
                    if (x > 0) x --;
                    else return false;
                }
                else if (x >= 3) x -= 3;
                else return false;
            }
        }

        return true;
    }
};
// @lc code=end

