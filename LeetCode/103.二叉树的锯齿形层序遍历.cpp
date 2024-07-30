#include <bits/stdc++.h>
using namespace std;

/*
 * @lc app=leetcode.cn id=103 lang=cpp
 *
 * [103] 二叉树的锯齿形层序遍历
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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        if (!root) return res;

        bfs(root, 0, res);
        // reverse(res.begin(), res.end());
        for (int i = 0, l = res.size(); i < l; i ++) {
            if (i & 1) reverse(res[i].begin(), res[i].end());
        }
        return res;
    }

    void bfs(TreeNode* root, int floor, vector<vector<int>>& res) {
        if (floor + 1 > res.size()) res.resize(floor + 1);
        res[floor].push_back(root->val);
        if (root->left) bfs(root->left, floor + 1, res);
        if (root->right) bfs(root->right, floor + 1, res);
    }
};
// @lc code=end

