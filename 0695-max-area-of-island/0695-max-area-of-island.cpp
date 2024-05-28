class Solution {
public:
    int m,n;

    void dfs(int i,int j,vector<vector<int>>& grid,int &area){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0) return;

        area++;
        grid[i][j] = 0;

        dfs(i+1,j,grid,area);
        dfs(i-1,j,grid,area);
        dfs(i,j+1,grid,area);
        dfs(i,j-1,grid,area);
    }

    int maxAreaOfIsland(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int maxArea = 0;
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    int area = 0;
                    dfs(i,j,grid,area);
                    maxArea = max(maxArea,area);
                }
            }
        }
        return maxArea;
    }
};