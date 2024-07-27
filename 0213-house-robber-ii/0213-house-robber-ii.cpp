class Solution {
public:
    int t[1001];
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
        int n = nums.size();
        if(n==1) return nums[0];
        memset(t,-1,sizeof(t));
        int possibility1 = solve(0,nums,n-1);
        memset(t,-1,sizeof(t));
        int possibility2 = solve(1,nums,n);
        return max(possibility1,possibility2);
    }
};