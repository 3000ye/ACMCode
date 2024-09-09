#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=496 lang=cpp
 *
 * [496] 下一个更大元素 I
 */

// @lc code=start
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> dic;
        for (int i = 0, l = nums1.size(); i < l; i ++) {
            dic[nums1[i]] = i;
        }

        vector<int> res(nums1.size(), -1);
        stack<int> stk;

        for (int i = nums2.size() - 1; i >= 0; i --) {
            int cur = nums2[i];

            while (!stk.empty() and cur >= stk.top()) stk.pop();
            if (!stk.empty() and dic.count(cur)) res[dic[cur]] = stk.top();

            stk.push(cur);
        }

        return res;
    }
};
// @lc code=end

