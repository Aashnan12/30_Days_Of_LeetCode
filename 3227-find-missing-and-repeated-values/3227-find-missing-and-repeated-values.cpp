// Math Approach
#define ll long long
class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        vector<int> arr;
        ll n = grid.size();
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[i].size();j++){
                arr.push_back(grid[i][j]);
            }
        }
        n = n*n;
        ll sum_n = 0, sum_f = n*(n+1)/2;
        for(int i=0;i<n;i++){
            sum_n += arr[i];
        }
        ll val_n = sum_f - sum_n; // x - y value

        sum_n = 0, sum_f = n*(n+1)*(2*n+1)/6;
        for(int i=0;i<n;i++){
            sum_n += (arr[i]*arr[i]);
        }
        
        ll val_2n = sum_f - sum_n; // x^2 - y^2 = val_2n;
        val_2n = val_2n / val_n;  // x + y value
        ll x = (val_n + val_2n)/2;
        ll y = x - val_n;

        return {(int)y,(int)x};

    }
};

// frequency approach

// class Solution {
// public:
//     vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
//         vector<int> arr;
//         int n = grid.size();
//         vector<int> freq(n*n+1,0);
        
//         for(int i=0;i<grid.size();i++){
//             for(int j=0;j<grid[i].size();j++){
//                 arr.push_back(grid[i][j]);
//                 freq[grid[i][j]]++;
//             }
//         }
//         int rep,mis;
//         for(int i=1;i<=n*n;i++){
//             if(freq[i] == 2){
//                 rep = i;
//             }
//             else if(freq[i] == 0){
//                 mis = i;
//             }
//         }

//         return {rep,mis};
//     }
// };