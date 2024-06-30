class Solution {
public:
    void dfs(int u,int ancestor,vector<vector<int>>& result,unordered_map<int,vector<int>>& mp){
        for(int v : mp[u]){
            if(result[v].empty() || result[v].back() != ancestor){
                result[v].push_back(ancestor);
                dfs(v,ancestor,result,mp);
            }
        }
    }
    vector<vector<int>> getAncestors(int n, vector<vector<int>>& edges) {
        vector<vector<int>> result(n);
        unordered_map<int,vector<int>> mp;

        for(auto &vec : edges){
            int u = vec[0];
            int v = vec[1];

            mp[u].push_back(v); // u-->v directed edge.
        }

        for(int i=0;i<n;i++){
            //DFS
            int ancestor = i;
            dfs(i,ancestor,result,mp);
        }
        return result;
    }
};