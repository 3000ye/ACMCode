#include <bits/stdc++.h>
#include <climits>
using namespace std;

/*
 * @lc app=leetcode.cn id=98 lang=cpp
 *
 * [98] 验证二叉搜索树
 */

// @castor solve=start
// 使用中根序遍历，只要序列是升序则为二叉搜索树
// @castor solve=end

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
    long long pre = LONG_MIN;
    bool isValidBST(TreeNode* root) {
        if (!root) return true;

        bool l = isValidBST(root->left);
        bool mid = (root->val > pre);
        pre = root->val;
        bool r = isValidBST(root->right);

        return l and mid and r;
    }
};
// @lc code=end

