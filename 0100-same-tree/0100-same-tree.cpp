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
    bool isSameTree(TreeNode* p, TreeNode* q) {

        //if both pointers reach Null it means we have fully traversed the tree and all nodes where equal.
        if(p == NULL && q == NULL)return true;

        //if any one of them points to Null it means other pointer has not fully traversed its tree i.e not equal.
        if(p == NULL || q == NULL)return false;

        // if both values are equal then check its left && right i.e return true if left subtree and right subtree returns tree
        if(p->val == q->val){
            return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
        }

        // if we reached here it means value pointed by pointers are not equal
        return false;
    }
};