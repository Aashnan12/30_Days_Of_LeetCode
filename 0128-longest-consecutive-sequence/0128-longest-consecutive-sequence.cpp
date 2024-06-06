class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_map<int,int> mp;
        int n = nums.size();
        if(n <= 1){
            return n;
        }

        for(int i=0;i<n;i++){
            mp[nums[i]]++;
        }
        int maxi = INT_MIN;
        for(auto &[a,b] : mp){
            if(mp.find(a-1) == mp.end()){
                int count = 1;
                while(mp.find(a+count) != mp.end()){
                    count++;
                }
                maxi = max(maxi,count);
            }
        }
        return maxi;
    }
};