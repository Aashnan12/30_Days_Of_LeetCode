class Solution {
public:
    int dp[46];
    int solve(int stair,int top){
        if(stair > top){
            return 0;
        }
        if(dp[stair] != -1) {
            return dp[stair];
        }
        if(stair == top){
            return 1;
        }
        int one_step = solve(stair+1,top);
        int two_step = solve(stair+2,top);
        return dp[stair] = one_step + two_step;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        solve(0,n);
        for(int i=0;i<=n;i++){
            cout<<dp[i]<<" ";
        }
        return dp[0];
    }
};