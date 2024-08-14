#include <bits/stdc++.h>
#include <unordered_map>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=525 lang=cpp
 *
 * [525] 连续数组
 */

// @lc code=start
class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        unordered_map<int, int> dic;
        dic[0] = {-1};
        
        int sum = 0, res = 0;
        for (int i = 0, l = nums.size(); i < l; i ++) {
            if (nums[i] == 1) sum ++;
            else sum --;

            cout << sum << " " << nums[i] << endl;
            if (dic.count(sum)) res = max(res, i - dic[sum]);
            else dic[sum] = i;
        }

        return res;
    }
};
// @lc code=end

