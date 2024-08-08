#include <bits/stdc++.h>
#include <vector>
using namespace std;

/*
 * @lc app=leetcode.cn id=1373 lang=cpp
 *
 * [1373] 二叉搜索子树的最大键值和
 */

struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

// @lc code=start
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int ans = 0;
        const int inf = 1 << 30;
        dfs(root, ans, inf);
        return ans;
    }

    vector<int> dfs(TreeNode* root, int &ans, const int inf) {
        if (!root) {
            return vector<int>{1, inf, -inf, 0};
        }
        auto l = dfs(root->left, ans, inf);
        auto r = dfs(root->right, ans, inf);
        int v = root->val;
        if (l[0] && r[0] && l[2] < v && v < r[1]) {
            int s = l[3] + r[3] + v;
            ans = max(ans, s);
            return vector<int>{1, min(l[1], v), max(r[2], v), s};
        }
        return vector<int>(4);
    }
};
// @lc code=end

