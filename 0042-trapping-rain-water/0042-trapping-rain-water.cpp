class Solution {
public:
    int trap(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n,0);
        vector<int> suffix(n,0);
        int maxi = INT_MIN;
        for(int i=0;i<n;i++){
            maxi = max(maxi,arr[i]);
            prefix[i] = maxi;
        }
        maxi = INT_MIN;
        for(int i=n-1;i>=0;i--){
            maxi = max(maxi,arr[i]);
            suffix[i] = maxi;
        }
        int maxwater = 0;
        for(int i=0;i<n;i++){
            maxwater += min(prefix[i],suffix[i]) - arr[i];
        }
        return maxwater;
    }
};