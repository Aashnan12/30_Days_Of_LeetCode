class Solution {
public:
    int m,n;

    void dfs(int i,int j,vector<vector<int>>& grid,int &walls){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] == 0){
            walls++;
            return;
        }
        if(grid[i][j] == -1){
            return;
        }

        grid[i][j] = -1;

        dfs(i+1,j,grid,walls);
        dfs(i-1,j,grid,walls);
        dfs(i,j+1,grid,walls);
        dfs(i,j-1,grid,walls);
    }
    int islandPerimeter(vector<vector<int>>& grid) {
        m = grid.size();
        n = grid[0].size();
        int walls = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    dfs(i,j,grid,walls);
                    return walls;
                }
            }
        }
        return -1;
    }
};