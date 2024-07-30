#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=129 lang=cpp
 *
 * [129] 求根节点到叶节点数字之和
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
    long long res = 0;
    int sumNumbers(TreeNode* root) {
        if (!root) return res;
        dfs(root, (long long)0);

        return res;
    }

    void dfs(TreeNode* root, long long curSum) {
        curSum = curSum * 10 + root->val;
        if (!root->left and !root->right) res += curSum;

        if (root->left) dfs(root->left, curSum);
        if (root->right) dfs(root->right, curSum);
    }
};
// @lc code=end

