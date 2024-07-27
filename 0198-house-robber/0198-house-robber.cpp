class Solution {
public:
    int t[401];
    int solve(int idx,vector<int>& nums,int n) {
        if(idx >= n){
            return 0;
        }
        if(t[idx] != -1){
            return t[idx];
        }
        int take = solve(idx+2,nums,n) + nums[idx];
        int skip = solve(idx+1,nums,n) + 0;
        return t[idx] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,nums,nums.size());
    }
};