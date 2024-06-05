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
    long long kthLargestLevelSum(TreeNode* root, int k) {
        ll sum = 0;
        priority_queue<ll> pq;
        queue<TreeNode*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();
            if(node == NULL){
                pq.push(sum);
                sum = 0;
                if(!q.empty()){
                    q.push(NULL);
                }
            }
            if(node) {
                sum += node->val;
                if(node->left){
                    q.push(node->left);
                }
                if(node->right){
                    q.push(node->right);
                }
            }
            
        }
        while(!pq.empty()){
            k--;
            if(k==0) return pq.top();
            pq.pop();
        }
        return -1;
    }
};