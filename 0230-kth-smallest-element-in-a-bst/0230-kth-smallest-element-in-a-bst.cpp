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
    int kthSmallest(TreeNode* root, int k) {
        if(!root) return 0;
        queue<TreeNode*> q;
        q.push(root);
        vector<int> v;
        while(!q.empty()){
            root = q.front();
            q.pop();
            v.push_back(root->val);
            if(root->left) q.push(root->left);
            if(root->right) q.push(root->right);
        }
        sort(v.begin(),v.end());
        if(v.size() < k) return 0;
        return v[k-1];
    }
};