class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
        int n = nums.size();
        vector<int> prefixsum(n,0);
        for(int i=1;i<n;i++){
            if(nums[i]%2 == nums[i-1]%2){
                prefixsum[i] = 1;
            }
            prefixsum[i] += prefixsum[i-1];
        }
        vector<bool> ans;
        for(int i=0;i<queries.size();i++){
            int x = queries[i][0];
            int y = queries[i][1];
            int val = prefixsum[y] - prefixsum[x];
            if(val==0) ans.push_back(true);
            else ans.push_back(false);
        }
        return ans;
    }
};