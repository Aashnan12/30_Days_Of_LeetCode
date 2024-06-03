class Solution {
public:
    int n;
    int t[2501][2501];

    int solve(int i,int pre,vector<int>& nums){
        if(i >= n){
            return 0;
        }
        if(pre != -1 && t[i][pre] != -1) {
            return t[i][pre];
        }
        int take = 0,skip = 0;
        //take
        if(pre == -1 || nums[pre] < nums[i]){
            take = 1 + solve(i+1,i,nums);
        }
        skip = solve(i+1,pre,nums);
        if(pre != -1){
            t[i][pre] = max(take,skip);
        }
        return max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        memset(t,-1,sizeof(t));
        n = nums.size();
        return solve(0,-1,nums);
    }
};