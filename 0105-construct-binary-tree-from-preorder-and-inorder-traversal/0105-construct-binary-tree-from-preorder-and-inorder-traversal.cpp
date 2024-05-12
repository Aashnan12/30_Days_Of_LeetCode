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


#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();
 
class Solution {
public:
    int findpos(vector<int> &inorder,int element,int n){
        for(int i=0;i<n;i++){
            if(inorder[i] == element){
                return i;
            }
        }
        return -1;
    }
    TreeNode* solve(vector<int>& preorder,vector<int>& inorder,int &index,int instart,int inend,int n){
        if(index >= n || instart > inend){
            return NULL;
        }
        int element = preorder[index++];
        TreeNode* root = new TreeNode(element);
        int pos = findpos(inorder,element,n);

        root->left = solve(preorder,inorder,index,instart,pos-1,n);
        root->right = solve(preorder,inorder,index,pos+1,inend,n);

        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int n = preorder.size();
        int index = 0;
        TreeNode* ans = solve(preorder,inorder,index,0,n-1,n);
        return ans;
    }
};