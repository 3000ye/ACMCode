#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=1157 lang=cpp
 *
 * [1157] 子数组中占绝大多数的元素
 */

// @lc code=start
const int MAXN = 20050;
const int MAXM = 20000;

struct BTree { int ch[2], sum; } node[MAXN * 100];
int root[MAXN], numn, PL, PR;

inline int lowbit(int x) { return x & -x; }

void init() {
    numn = 0;
    memset(root, 0, sizeof(root));
}

void insNode(int &x, int l, int r, int p) {
    if (!x) {
        x = ++numn;
        node[x].ch[0] = node[x].ch[1] = node[x].sum = 0;
    }

    ++node[x].sum;

    if (l < r) {
        int m = (l + r) / 2;
        if (p <= m) {
            insNode(node[x].ch[0], l, m, p);
        } else {
            insNode(node[x].ch[1], m + 1, r, p);
        }
    }
}

void insT(int p, int v) {
    for (int i = v; i <= MAXM; i += lowbit(i)) 
        insNode(root[i], PL, PR, p);
}

int qN(int x, int l, int r, int left, int right) {
    if (!x) return 0;
    if (left <= l && r <= right) return node[x].sum;

    int m = (l + r) / 2, ret = 0;
    if (left <= m) ret += qN(node[x].ch[0], l, m, left, right);
    if (m + 1 <= right) ret += qN(node[x].ch[1], m + 1, r, left, right);

    return ret;
}

int qT(int left, int right, int v) {
    int ret = 0;
    for (int i = v; i > 0; i -= lowbit(i))
        ret += qN(root[i], PL, PR, left, right);
    return ret;
}

class MajorityChecker {
public:
    MajorityChecker(vector<int>& a) {
        PL = 0, PR = a.size() - 1;
        init();
        for (int i = PL; i <= PR; i++) insT(i, a[i]);
    }

    int query(int left, int right, int threshold) {
        int res = 0, cur = 32768 / 2, k = threshold;
        while (cur) {
            if (cur + res > MAXM) {
                cur /= 2;
                continue;
            }
            int v = qN(root[res + cur], PL, PR, left, right);
            if (v < k) { k -= v; res += cur; }
            cur /= 2;
        }

        int cnt = qT(left, right, res + 1) - qT(left, right, res);
        return cnt >= threshold ? res + 1 : -1;
    }
};
/**
 * Your MajorityChecker object will be instantiated and called as such:
 * MajorityChecker* obj = new MajorityChecker(arr);
 * int param_1 = obj->query(left, right, threshold);
 */
// @lc code=end
