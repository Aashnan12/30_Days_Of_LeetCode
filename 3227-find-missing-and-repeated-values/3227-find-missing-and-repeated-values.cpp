class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> arr;
        int n = grid.size();
        vector<int> freq(n*n+1,0);
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                arr.push_back(grid[i][j]);
                freq[grid[i][j]]++;
            }
        }
        int rep,mis;
        for(int i=1;i<=n*n;i++){
            if(freq[i] == 2){
                rep = i;
            }
            else if(freq[i] == 0){
                mis = i;
            }
        }

        return {rep,mis};
    }
};