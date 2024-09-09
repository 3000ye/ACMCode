#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=850 lang=cpp
 *
 * [850] 矩形面积 II
 */

// @lc code=start
class Node {
public:
    int l, r, cnt, length;
};

class ST {
public:
    vector<Node*> tr;
    vector<int> nums;

    ST(vector<int>& nums) {
        this->nums = nums;
        int n = nums.size() - 1;
        tr.resize(n << 2);
        for (int i = 0; i < tr.size(); ++i) tr[i] = new Node();
        build(1, 0, n - 1);
    }

    void build(int u, int l, int r) {
        tr[u]->l = l;
        tr[u]->r = r;
        if (l != r) {
            int mid = (l + r) >> 1;
            build(u << 1, l, mid);
            build(u << 1 | 1, mid + 1, r);
        }
    }

    void modify(int u, int l, int r, int k) {
        if (tr[u]->l >= l && tr[u]->r <= r)
            tr[u]->cnt += k;
        else {
            int mid = (tr[u]->l + tr[u]->r) >> 1;
            if (l <= mid) modify(u << 1, l, r, k);
            if (r > mid) modify(u << 1 | 1, l, r, k);
        }
        pushup(u);
    }

    int query() {
        return tr[1]->length;
    }

    void pushup(int u) {
        if (tr[u]->cnt)
            tr[u]->length = nums[tr[u]->r + 1] - nums[tr[u]->l];
        else if (tr[u]->l == tr[u]->r)
            tr[u]->length = 0;
        else
            tr[u]->length = tr[u << 1]->length + tr[u << 1 | 1]->length;
    }
};

class Solution {
public:
    const int mod = 1e9 + 7;

    int rectangleArea(vector<vector<int>>& rectangles) {
        int len = rectangles.size();
        vector<vector<int>> ls(len << 1); set<int> ts;

        int i = 0;
        for (auto& e : rectangles) {
            int x1 = e[0], y1 = e[1], x2 = e[2], y2 = e[3];
            ls[i++] = {x1, y1, y2, 1}; ls[i++] = {x2, y1, y2, -1};
            ts.insert(y1); ts.insert(y2);
        }
        sort(ls.begin(), ls.end());
        unordered_map<int, int> dics;
        i = 0; for (int v : ts) dics[v] = i++;
        vector<int> nums(ts.begin(), ts.end());
        ST* tree = new ST(nums);
        long long res = 0;
        for (int i = 0; i < ls.size(); ++i) {
            auto e = ls[i];
            int x = e[0], y1 = e[1], y2 = e[2], k = e[3];
            if (i > 0) res += (long long) tree->query() * (x - ls[i - 1][0]);
            tree->modify(1, dics[y1], dics[y2] - 1, k);
        }
        
        return (int)(res %= mod);
    }
};
// @lc code=end

