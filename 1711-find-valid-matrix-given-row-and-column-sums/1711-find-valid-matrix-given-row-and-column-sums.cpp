class Solution {
public:
    vector<vector<int>> restoreMatrix(vector<int>& rowSum, vector<int>& colSum) {
        int n = rowSum.size();
        int m = colSum.size();
        vector<vector<int>> mat(n,vector<int>(m,0));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(rowSum[i] <= colSum[j]){
                    mat[i][j] = rowSum[i];
                    colSum[j] -= rowSum[i];
                    rowSum[i] = 0;
                }
                else{
                    mat[i][j] = colSum[j];
                    rowSum[i] -= colSum[j];
                    colSum[j] = 0;
                }
            }
        }



        // int i = 0, j = 0;

        // while(i<n && j<m){
        //     mat[i][j] = min(rowSum[i],colSum[j]);
        //     rowSum[i] -= mat[i][j];
        //     colSum[j] -= mat[i][j];

        //     if(rowSum[i] == 0){
        //         i++;
        //     }
        //     else{
        //         j++;
        //     }
        // }


        return mat;
    }
};