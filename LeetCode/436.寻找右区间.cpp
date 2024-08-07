#include <bits/stdc++.h>
#include <unordered_map>
#include <utility>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=436 lang=cpp
 *
 * [436] 寻找右区间
 */

// @lc code=start
class Solution {
public:
    vector<int> findRightInterval(vector<vector<int>>& intervals) {
        // pair<start, idx>
        vector<pair<int, int>> ls(intervals.size());
        for (int i = 0, l = intervals.size(); i < l; i ++) { ls[i] = pair<int, int> (intervals[i][0], i); }
        sort(ls.begin(), ls.end(), [](pair<int, int> a, pair<int, int> b) { return a.first < b.first; });

        vector<int> res;
        for (auto i : intervals) {
            int target = i[1];
            if (target > ls.back().first) res.push_back(-1);
            else {
                int l = 0, r = ls.size() - 1;
                while (l <= r) {
                    int mid = l + ((r - l) >> 1);
                    if (ls[mid].first >= target) {
                        if (mid == 0 or ls[mid - 1].first < target) {
                            res.push_back(ls[mid].second);
                            break;
                        }
                        else r = mid - 1;
                    }
                    else l = mid + 1;
                }
            }
        }

        return res;
    }
};
// @lc code=end

