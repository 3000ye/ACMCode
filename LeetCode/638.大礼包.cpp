#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=638 lang=cpp
 *
 * [638] 大礼包
 */

// @lc code=start
class Solution {
public:
    map<vector<int>, int> dic;
    int shoppingOffers(vector<int>& price, vector<vector<int>>& special, vector<int>& needs) {
        return dfs(needs, price, special);
    }

    int dfs(vector<int> needs, vector<int>& p, vector<vector<int>>& sp) {
        if (dic[needs]) return dic[needs];

        int res = 0;
        for (int i = 0, l = needs.size(); i < l; i ++) res += needs[i] * p[i];

        for (int i = 0, l = sp.size(); i < l; i ++) {
            vector<int> temp = needs;
            bool flag = true;

            for (int j = 0, k = p.size(); j < k; j ++) {
                if (sp[i][j] > needs[j]) {
                    flag = false; break;
                }
            }

            if (!flag) continue;
            for (int j = 0, k = p.size(); j < k; j ++) {
                temp[j] -= sp[i][j];
            }

            res = min(res, dfs(temp, p, sp) + sp[i].back());
        }

        dic[needs] = res;

        return res;
    }
};
// @lc code=end

