class Solution {
public:
    bool magicSq(vector<vector<int>>& grid,int r,int c){
        unordered_set<int> s;

        //Checking duplicates
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                int num = grid[r+i][c+j];
                if(num < 1 || num > 9 || s.count(num)) return false;
                else s.insert(num);
            }
        }

        //Rows and Cols
        int sum = grid[r][c] + grid[r][c+1] + grid[r][c+2];
        for(int i=0;i<3;i++){
            if(grid[r+i][c] + grid[r+i][c+1] + grid[r+i][c+2] != sum) return false;
            if(grid[r][c+i] + grid[r+1][c+i] + grid[r+2][c+i] != sum) return false;
        }

        //Diagonals
        if(grid[r][c] + grid[r+1][c+1] + grid[r+2][c+2] != sum) return false;
        if(grid[r+2][c] + grid[r+1][c+1] + grid[r][c+2] != sum) return false;

        return true;
    }
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int cnt = 0;
        int m  = grid.size();
        int n = grid[0].size();
        for(int i=0;i<m-2;i++){
            for(int j=0;j<n-2;j++){
                if(magicSq(grid,i,j)){
                    cnt++;
                }
            }
        }
        return cnt;
    }
};