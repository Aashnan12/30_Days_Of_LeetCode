class Solution {
public:
    int dp[1001][1001];
    int solve(int i,int j,string& s,string& t){
        if(i >= s.size() || j >= t.size()){
            return 0;
        }
        if(dp[i][j] != -1){
            return dp[i][j];
        }
        int take = 0,skip = 0;
        //take
        if(s[i] == t[j]){
            take = 1 + solve(i+1,j+1,s,t);
        }

        //skip
        skip = max(solve(i+1,j,s,t),solve(i,j+1,s,t));

        return dp[i][j] = max(take,skip);
    }
    int longestCommonSubsequence(string s, string t) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,s,t);
    }
};