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
    int solve(TreeNode* root,int &nodes){
        if(!root){
            return 0;
        }
        nodes = max(solve(root->left,nodes),solve(root->right,nodes)) + 1;
        return nodes;
    }
    int maxDepth(TreeNode* root) {
        int nodes = 0;
        return solve(root,nodes);
    }
};