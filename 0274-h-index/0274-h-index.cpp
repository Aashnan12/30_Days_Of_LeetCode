class Solution {
public:
    int hIndex(vector<int>& arr) {
        int maxi = *max_element(arr.begin(),arr.end());

        int n = arr.size();
        vector<int> freq(n+1,0);

        for(int i=0;i<n;i++){
            if(arr[i] > n){
                freq[n]++;
            }
            else{
                freq[arr[i]]++;
            }
        }
        int total = 0;

        for(int i=n;i>=0;i--){
            total += freq[i];
            if(total >= i){
                return i;
            }
        }
        return 0;
    }
};