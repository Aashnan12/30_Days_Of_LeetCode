#pragma GCC optimize("Ofast")
static auto _ = [] () {ios_base::sync_with_stdio(false);cin.tie(nullptr);cout.tie(nullptr);return 0;}();

class Solution {
public:
    int minimumOperations(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        
        vector<int> dp(10, 0);
        for(int j=0; j<m; j++){
            vector<int> count(10, n);

            for(int i=0; i<n; i++)
                count[grid[i][j]]--;

            vector<int> temp(10, INT_MAX);

            for(int i=0; i<=9; i++){
                for(int k=0; k<=9; k++){
                    if(i!=k)
                        temp[i] = min(temp[i], count[i]+dp[k]);
                }
            }
            dp = temp;
        }
        
        return *min_element(dp.begin(), dp.end());
    }
};