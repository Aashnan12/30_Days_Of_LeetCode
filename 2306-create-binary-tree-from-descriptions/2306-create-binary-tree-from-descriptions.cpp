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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*> map;
        unordered_set<int> childs;

        for(auto& arr : descriptions){
            int parent = arr[0];
            int child = arr[1];
            int pos = arr[2];
            
            if(map.find(parent) == map.end()){
                map[parent] = new TreeNode(parent);
            }
            if(map.find(child) == map.end()){
                map[child] = new TreeNode(child);
            }

            if(pos == 1){
                map[parent]->left = map[child];
            }
            else{
                map[parent]->right = map[child];
            }

            childs.insert(child);
        }

        for(auto &it : descriptions){
            if(childs.find(it[0]) == childs.end()){
                return map[it[0]];
            }
        }
        return NULL;
    }
};