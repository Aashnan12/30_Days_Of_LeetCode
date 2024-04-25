class Solution {
public:
    // We have to calc no. of provinces....
    void dfs(unordered_map<int,vector<int>> &map,int u, vector<bool> &vis){

        vis[u] = true;

        for(int &v : map[u]){
            if(!vis[v]){
                dfs(map,v,vis);
            }
        }
        return ;
    }
    int findCircleNum(vector<vector<int>>& mat) {
        int n = mat.size();
        unordered_map<int,vector<int>> map;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++) {
                if(i!=j && mat[i][j] == 1){
                    map[i].push_back(j);
                    map[j].push_back(i);
                }
            }
        }
        int provinces = 0;
        vector<bool> vis(n+1,0);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                dfs(map,i,vis);
                provinces++;
            }
        }
        return provinces;
    }
};