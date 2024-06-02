class Solution {
public:
    int dp[46];
    int solve(int stairs){
        if(stairs < 0) return 0;
        if(stairs ==  0) return 1;
        if(dp[stairs] != -1) return dp[stairs];
        int one_step = solve(stairs-1);
        int two_step = solve(stairs-2);
        return dp[stairs] = one_step + two_step;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        solve(n);
        return dp[n];
    }
};