#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

// class Solution {
// public:
//     bool canFinish(int n, vector<vector<int>>& adj) {
//         unordered_map<int,vector<int>> map;

//         for(vector<int> &v : adj){
//             map[v[1]].push_back(v[0]);
//         }

//         vector<bool> inRecursion(n,0);
//         vector<bool> vis(n,0);
//         for(int i=0;i<n;i++){
            
//         }
//     }
// };


class Solution {
public:
    bool canFinish(int n, vector<vector<int>>& adj) {
        unordered_map<int,vector<int>> map;

        for(vector<int> &v : adj){
            map[v[1]].push_back(v[0]);
        }

        vector<int> indegree(n,0);

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

        int courses = 0;

        while(!q.empty()){
            int u = q.front();
            q.pop();
            courses++;
            for(int &v : map[u]){
                indegree[v]--;
                if(indegree[v] == 0){
                    q.push(v);
                }
            }
        }
        return courses >= n;
    }
};