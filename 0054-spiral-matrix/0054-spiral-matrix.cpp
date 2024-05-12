class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();

        int size = m*n;
        int count = 0;

        int rowstart = 0;
        int rowend = m-1;
        int colstart = 0;
        int colend = n-1;

        vector<int> ans;

        while(count < size){
            for(int i=colstart;i<=colend && count<size ;i++){
                ans.push_back(matrix[rowstart][i]);
                count++;
            }
            rowstart++;

            for(int i=rowstart;i<=rowend && count<size ;i++){
                ans.push_back(matrix[i][colend]);
                count++;
            }
            colend--;

            for(int i=colend;i>=colstart && count<size ;i--){
                ans.push_back(matrix[rowend][i]);
                count++;
            }
            rowend--;

            for(int i=rowend;i>=rowstart && count<size ;i--){
                ans.push_back(matrix[i][colstart]);
                count++;
            }
            colstart++;
        }
        return ans;
    }
};