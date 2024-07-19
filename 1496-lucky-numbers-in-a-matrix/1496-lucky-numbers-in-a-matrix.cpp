class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        vector<int> result;
        int m = matrix.size();
        int n = matrix[0].size();
        
        // Find the minimum in each row
        vector<int> rowMin(m, INT_MAX);
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                rowMin[i] = min(rowMin[i], matrix[i][j]);
            }
        }
        
        // Find the maximum in each column
        vector<int> colMax(n, INT_MIN);
        for (int j = 0; j < n; ++j) {
            for (int i = 0; i < m; ++i) {
                colMax[j] = max(colMax[j], matrix[i][j]);
            }
        }
        
        // Find all lucky numbers
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                if (matrix[i][j] == rowMin[i] && matrix[i][j] == colMax[j]) {
                    result.push_back(matrix[i][j]);
                }
            }
        }
        
        return result;
    }
};
