#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    void bfs(unordered_map<int,vector<int>> &map,vector<bool> &vis,int src){
        queue<int> q;
        q.push(src);
        vis[src] = true;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int &v : map[u]){
                if(!vis[v]){
                    q.push(v);
                    vis[v] = true;
                }
            }
        }
        return;
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        unordered_map<int,vector<int>> map;
        int n = isConnected.size();

        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i != j && isConnected[i][j] == 1){
                    map[i].push_back(j);
                    map[j].push_back(i);
                }
            }
        }
        int pro = 0;
        vector<bool> vis(n+1,false);
        for(int i=0;i<n;i++){
            if(!vis[i]){
                pro++;
                bfs(map,vis,i);
            }
        }
        return pro;
    }
};