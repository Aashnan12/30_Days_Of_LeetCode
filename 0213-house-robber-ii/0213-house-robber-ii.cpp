class Solution {
public:
    int t[1001];
    int solve(int idx,int n,vector<int>& nums){
        if(idx >= n){
            return 0;
        }
        if(t[idx] != -1){
            return t[idx];
        }
        int take = nums[idx] + solve(idx+2,n,nums);
        int skip = 0 + solve(idx+1,n,nums);
        return t[idx] = max(take,skip);
    }
    int rob(vector<int>& nums) {
        int n = nums.size();
        if(n == 1){
            return nums[0];
        }
        memset(t,-1,sizeof(t));
        int first_case = solve(0,n-1,nums);
        memset(t,-1,sizeof(t));
        int second_case = solve(1,n,nums);
        return max(first_case,second_case);
    }
};