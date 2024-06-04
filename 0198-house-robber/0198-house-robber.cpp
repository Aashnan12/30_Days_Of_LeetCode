class Solution {
public:
    int t[401];
    int solve(int i,vector<int>& nums){
        if(i >= nums.size()){
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        int take = solve(i+2,nums) + nums[i];
        int skip = solve(i+1,nums);

        return t[i] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        return solve(0,nums);
    }
};