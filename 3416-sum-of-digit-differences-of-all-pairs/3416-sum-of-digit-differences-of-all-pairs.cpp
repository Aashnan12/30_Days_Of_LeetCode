class Solution {
public:
    long long sumDigitDifferences(vector<int>& nums) {
        int n = nums.size();
        vector<string> arr(n);
        for(int i=0;i<n;i++){
            arr[i] = to_string(nums[i]);
        }

        int k = arr[0].size();

        long long count = 0;
        for(int i=0;i<k;i++){
            map<char,long long> map;
            for(int j=0;j<n;j++){
                map[arr[j][i]]++;
            }
            for(auto &it : map){
                count += (n - it.second) * it.second;
            }
        }
        return count/2;
    }
};