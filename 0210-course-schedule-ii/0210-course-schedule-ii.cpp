#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    vector<int> findOrder(int n, vector<vector<int>>& prerequisites) {
        unordered_map<int,vector<int>> map;
        vector<int> indegree(n,0);

        for(vector<int> &v : prerequisites){
            map[v[1]].push_back(v[0]);
        }
        for(int i=0;i<n;i++){
            for(int &v : map[i]){
                indegree[v]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        vector<int> topoSort;
        int courses = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            courses++;
            topoSort.push_back(u);
            for(int &v : map[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        if(courses == n){
            return topoSort;
        }
        return {};
    }
};