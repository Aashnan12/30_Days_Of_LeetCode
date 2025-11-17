class Solution {
public:
    int dp[46];
    int solve(int stairs){
        if(stairs < 0) return 0;
        if(stairs == 0) return 1;
        if(dp[stairs] != -1) return dp[stairs];
        int o = solve(stairs-1);
        int t = solve(stairs-2);
        return dp[stairs] = o + t;
    }
    int climbStairs(int n) {
        memset(dp,-1,sizeof(dp));
        solve(n);
        return dp[n];
    }
};