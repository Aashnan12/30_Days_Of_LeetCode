class Solution {
public:
    int t[1001];
    int solve(int i,int n,vector<int>& nums){
        if(i >= n){
            return 0;
        }
        if(t[i] != -1){
            return t[i];
        }
        int take = solve(i+2,n,nums) + nums[i];
        int skip = solve(i+1,n,nums);

        return t[i] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        if(nums.size() == 1) return nums[0];
        memset(t,-1,sizeof(t));
        int n = nums.size();
        int ans = solve(0,n-1,nums);
        memset(t,-1,sizeof(t));
        return max(ans,solve(1,n,nums));
    }
};