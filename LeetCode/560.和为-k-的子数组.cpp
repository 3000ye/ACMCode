#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=560 lang=cpp
 *
 * [560] 和为 K 的子数组
 */

// @castor solve=start
// 前缀和+哈希
// 1. 获取前缀和数组 preSum，即找 preSum[i] + k = preSum[j]
// 2. 从前往后遍历，只要发现 preSum[i] - k 存在，则累加个数
// @castor solve=end

// @lc code=start
class Solution {
public:
    int subarraySum(vector<int>& ls, int k) {
        vector<int> preSum(ls.size() + 1, 0);
        for (int i = 0, l = ls.size(); i < l; i ++) {
            preSum[i + 1] = preSum[i] + ls[i];
        }

        unordered_map<int, int> dic; int res = 0;
        for (auto i : preSum) {
            if (dic.find(i - k) != dic.end()) res += dic[i - k];
            dic[i] ++;
        }

        return res;
    }
};
// @lc code=end

