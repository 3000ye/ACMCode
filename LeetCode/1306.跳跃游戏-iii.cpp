#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1306 lang=cpp
 *
 * [1306] 跳跃游戏 III
 */

// @lc code=start
class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if (start >= arr.size() or start < 0 or arr[start] == -1) return false;
        if (arr[start] == 0) return true;
        int cur = arr[start];
        arr[start] = -1;
        return canReach(arr,start+cur) or canReach(arr,start-cur);
    }
};
// @lc code=end

