#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=112 lang=cpp
 *
 * [112] 路径总和
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
    bool hasPathSum(TreeNode* root, int targetSum) {
        if (!root) return false;
        return dfs(root, targetSum, 0);
    }

    bool dfs(TreeNode* root, int targetSum, int curSum) {
        curSum += root->val;

        // 只有叶子节点才判断
        if (!root->left and !root->right) return targetSum == curSum;
        else if (root->left and !root->right) return dfs(root->left, targetSum, curSum);
        else if (!root->left and root->right) return dfs(root->right, targetSum, curSum);
        else return dfs(root->left, targetSum, curSum) or dfs(root->right, targetSum, curSum);
    }
};
// @lc code=end

