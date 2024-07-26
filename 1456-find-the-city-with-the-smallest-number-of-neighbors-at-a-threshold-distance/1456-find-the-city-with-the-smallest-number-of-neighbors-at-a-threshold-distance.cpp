class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> vec(n, vector<int>(n, 1e9+7));

        for(int i=0;i<n;i++){
            vec[i][i] = 0;
        }

        for(auto &edge : edges){
            int u = edge[0];
            int v = edge[1];
            int wt = edge[2];

            vec[u][v] = wt;
            vec[v][u] = wt;
        }

        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    vec[i][j] = min(vec[i][j], vec[i][via] + vec[via][j]);
                }
            }
        }

        //Finding result city
        int resultcity = -1;
        int leastReachedcount = INT_MAX;

        for(int i=0;i<n;i++){
            int countcity = 0;
            for(int j=0;j<n;j++){
                if(i != j && vec[i][j] <= distanceThreshold){
                    countcity++;
                }
            }

            if(countcity <= leastReachedcount){
                leastReachedcount = countcity;
                resultcity = i;
            }
        }
        return resultcity;
    }
};