class Solution {
public:
    vector<int> majorityElement(vector<int>& nums) {
        unordered_map<int,int> mp;
        vector<int> ans;
        int n = nums.size();
        for(int i=0;i<n;i++){
            mp[nums[i]]++;
            if(mp[nums[i]] * 3 > n){
                ans.push_back(nums[i]);
                mp[nums[i]] = -1;
            }
        }
        return ans;
    }
};