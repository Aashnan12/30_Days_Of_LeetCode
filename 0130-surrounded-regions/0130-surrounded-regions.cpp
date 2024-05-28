class Solution {
public:
    int m,n;

    void dfs(int i,int j,vector<vector<char>>& grid){
        if(i<0 || j<0 || i>=m || j>=n || grid[i][j] != 'O') return;

        grid[i][j] = '$';

        dfs(i+1,j,grid);
        dfs(i-1,j,grid);
        dfs(i,j+1,grid);
        dfs(i,j-1,grid);
    }
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;

        m = board.size();
        n = board[0].size();

        //Top - Row
        for(int i=0;i<n;i++){
            if(board[0][i] == 'O'){
                dfs(0,i,board);
            }
        }
        //Botton - Row
        for(int i=0;i<n;i++){
            if(board[m-1][i] == 'O'){
                dfs(m-1,i,board);
            }
        }
        //Left - Column
        for(int i=0;i<m;i++){
            if(board[i][0] == 'O'){
                dfs(i,0,board);
            }
        }
        //Right - Column
        for(int i=0;i<m;i++){
            if(board[i][n-1] == 'O'){
                dfs(i,n-1,board);
            }
        }

        //Can be Converted
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == 'O'){
                    board[i][j] = 'X';
                }
            }
        }
        //Cannot be converted
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(board[i][j] == '$'){
                    board[i][j] = 'O';
                }
            }
        }
    }
};