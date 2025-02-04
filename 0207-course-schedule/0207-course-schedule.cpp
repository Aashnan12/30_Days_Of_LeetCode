class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& pre) {
        unordered_map<int,vector<int>> mp;
        for(auto p : pre){
            mp[p[1]].push_back(p[0]);
        }
        vector<int> indegree(n+1,0);
        for(int i=0;i<n;i++){
            for(int &u : mp[i]){
                indegree[u]++;
            }
        }
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i] == 0){
                q.push(i);
            }
        }
        int courses = 0;
        while(!q.empty()){
            int v = q.front();
            q.pop();
            courses++;
            for(int &u : mp[v]){
                indegree[u]--;
                if(indegree[u] == 0){
                    q.push(u);
                }
            }
        }
        return courses>=n;
    }
};