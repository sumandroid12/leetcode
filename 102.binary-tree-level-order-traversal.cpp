/*
 * @lc app=leetcode id=102 lang=cpp
 *
 * [102] Binary Tree Level Order Traversal
 *
 * https://leetcode.com/problems/binary-tree-level-order-traversal/description/
 *
 * algorithms
 * Medium (47.41%)
 * Total Accepted:    347.4K
 * Total Submissions: 732.8K
 * Testcase Example:  '[3,9,20,null,null,15,7]'
 *
 * Given a binary tree, return the level order traversal of its nodes' values.
 * (ie, from left to right, level by level).
 * 
 * 
 * For example:
 * Given binary tree [3,9,20,null,null,15,7],
 * 
 * ⁠   3
 * ⁠  / \
 * ⁠ 9  20
 * ⁠   /  \
 * ⁠  15   7
 * 
 * 
 * 
 * return its level order traversal as:
 * 
 * [
 * ⁠ [3],
 * ⁠ [9,20],
 * ⁠ [15,7]
 * ]
 * 
 * 
 */
/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
};
#include<bits/stdc++.h>
#include<deque>
using namespace std;
class Solution {
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        vector<vector<int>> res;
        vector<int> lvl;
        deque<TreeNode*> q1;
        deque<TreeNode*> q2; 
        q1.emplace_back(root);
        while(1){
            if(q1.empty()){
                res.push_back(lvl);
                vector<int>().swap(lvl);
                if(q2.empty()) break; 
                copy(q2.begin(),q2.end(),q1.begin());
                deque<TreeNode*>().swap(q2);
            }
            auto parent = q1.front();
            if(parent->left != nullptr) q2.emplace_back(parent->left);
            if(parent->right != nullptr) q2.emplace_back(parent->right);
            q1.pop_front();
            lvl.push_back(parent->val);
        }
        return res;
    }
}; 