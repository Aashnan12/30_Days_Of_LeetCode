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
    void solve(TreeNode* root1, TreeNode* root2, int level) {
        if (!root1 || !root2) return;
        
        // Swap values at odd levels
        if (level % 2 == 1) {
            swap(root1->val, root2->val);
        }
        
        // Recur for children
        solve(root1->left, root2->right, level + 1);
        solve(root1->right, root2->left, level + 1);
    }
    
    TreeNode* reverseOddLevels(TreeNode* root) {
        if (!root) return nullptr;
        solve(root->left, root->right, 1);
        return root;
    }
};
