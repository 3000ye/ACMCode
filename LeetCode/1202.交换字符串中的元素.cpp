#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1202 lang=cpp
 *
 * [1202] 交换字符串中的元素
 */

// @lc code=start
class Djset {
public:
    vector<int> par; vector<int> rank;
    Djset(int n ) {
        for (int i = 0; i < n; i++) {
            par.push_back(i);
            rank.push_back(0);
        }
    }

    int find(int x) {
        if (par[x] != x) {
            par[x] = find(par[x]);
        }
        return par[x];
    }

    void merge(int x, int y) {
        int rx = find(x);
        int ry = find(y);
        if (rx != ry) {
            if (rank[rx] < rank[ry]) {
                swap(rx, ry);
            }
            par[ry] = rx;
            if (rank[rx] == rank[ry]) rank[rx] += 1;
        }
    }
};

class Solution {
public:
    string smallestStringWithSwaps(string s, vector<vector<int>>& pairs) {
        int n = s.size(); vector<char> res(n);
        Djset ds(n);

        for (const auto& e : pairs) ds.merge(e[0], e[1]);
        
        unordered_map<int, vector<int> > dic;
        for (int i = 0; i < n; i++) dic[ds.find(i)].push_back(i);
        
        for (auto& [k, v] : dic) {
            vector<int> c = v;
            sort(v.begin(), v.end(), [&](auto a, auto b) {
                return s[a] < s[b];
            });
            
            for (int i = 0; i < c.size(); i++) res[c[i]] = s[v[i]];
        }
        
        s = "";
        for (const auto& e : res) s += e;
        return s;
    }
};
// @lc code=end

