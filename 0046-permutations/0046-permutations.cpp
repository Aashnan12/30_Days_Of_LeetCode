class Solution {
public:
    void solve(int i,vector<int> nums,vector<vector<int>>& res,int n){
        if(i >= n){
            res.push_back(nums);
            return;
        }
        
        for(int idx = i; idx < n; idx++){
            swap(nums[i],nums[idx]);
            solve(i+1,nums,res,n);
            swap(nums[i],nums[idx]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        solve(0,nums,res,nums.size());
        return res;
    }
};