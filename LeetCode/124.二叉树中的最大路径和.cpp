#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=124 lang=cpp
 *
 * [124] 二叉树中的最大路径和
 */

// Definition for a binary tree node.
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
    int func(TreeNode* root, int &val) {
        if (!root) return 0;
        int l = func(root->left, val);
        int r = func(root->right, val);
        int temp = root->val + max(0, l) + max(0, r);
        int res = root->val + max(0, max(l, r));
        val = max(val, max(temp, res));
        return res;
    }

    int maxPathSum(TreeNode* root) {
        int val = INT_MIN;
        func(root, val);
        return val;
    }
};
// @lc code=end

