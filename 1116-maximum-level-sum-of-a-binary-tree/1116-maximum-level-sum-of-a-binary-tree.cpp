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
#define ll long long
class Solution {
public:
    int maxLevelSum(TreeNode* root) {

        vector<int> arr;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);
        ll sum = 0;

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(node == NULL){
                arr.push_back(sum);
                sum = 0;
                if(!q.empty()) q.push(NULL);
            }
            if(node){
                sum += node->val;
                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
        }

        int maxi = INT_MIN;
        int level = 0;
        for(int i=0;i<arr.size();i++){
            if(maxi < arr[i]){
                maxi = arr[i];
                level = i+1;
            }
        }
        return level;
    }
};