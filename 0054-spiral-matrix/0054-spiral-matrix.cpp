class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        int size = m*n;
        int count = 0;

        int startrow = 0;
        int endrow = m-1;
        int startcol = 0;
        int endcol = n-1;
        vector<int> result;
        while(count < size){
            for(int i=startcol;i<=endcol && count<size;i++){
                result.push_back(matrix[startrow][i]);
                count++;
            }
            startrow++;
            for(int i=startrow;i<=endrow && count<size;i++){
                result.push_back(matrix[i][endcol]);
                count++;
            }
            endcol--;
            for(int i=endcol;i>=startcol && count<size;i--){
                result.push_back(matrix[endrow][i]);
                count++;
            }
            endrow--;
            for(int i=endrow;i>=startrow && count<size;i--){
                result.push_back(matrix[i][startcol]);
                count++;
            }
            startcol++;
        }
        return result;
    }
};