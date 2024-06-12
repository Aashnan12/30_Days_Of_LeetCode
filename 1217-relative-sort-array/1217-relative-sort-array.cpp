class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        vector<int> freq(1001,0);
        for(int num : arr1){
            freq[num]++;
        }

        vector<int> ans;
        for(int num : arr2){
            if(freq[num] > 0){
                while(freq[num] > 0){
                    ans.push_back(num);
                    freq[num]--;
                }
            }
        }
        for(int i=0;i<1001;i++){
            while(freq[i] > 0){
                ans.push_back(i);
                freq[i]--;
            }
        }
        return ans;
    }
};