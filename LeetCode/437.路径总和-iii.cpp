#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=437 lang=cpp
 *
 * [437] 路径总和 III
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
    int res = 0;

    int pathSum(TreeNode* root, int targetSum) {
        if (!root) return res;
        // 每一个节点都可以作为起点
        stack<TreeNode*> stk; stk.push(root);
        while (!stk.empty()) {
            auto temp = stk.top(); stk.pop();
            dfs(temp, (long long)0, targetSum);

            if (temp->left) stk.push(temp->left);
            if (temp->right) stk.push(temp->right);
        }

        return res;
    }

    void dfs(TreeNode* root, long long curSum, int targetSum) {
        curSum += root->val;
        if (curSum == targetSum) res ++;

        // 开始搜索
        if (root->left) dfs(root->left, curSum, targetSum);
        if (root->right) dfs(root->right, curSum, targetSum);
    }
};
// @lc code=end

