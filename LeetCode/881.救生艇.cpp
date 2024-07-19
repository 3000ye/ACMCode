#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=881 lang=cpp
 *
 * [881] 救生艇
 */

// @lc code=start
class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(), people.end());

        int l = 0; int r = people.size() - 1;
        int cnt = 0;
        while (l <= r) {
            if (people[l] + people[r] > limit) { cnt++; r--; }
            else { cnt++;l++; r--; }
        }

        return cnt;
    }
};
// @lc code=end

