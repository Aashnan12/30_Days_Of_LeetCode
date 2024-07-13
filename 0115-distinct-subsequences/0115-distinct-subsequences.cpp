class Solution {
public:
    int dp[1001][1001];

    int solve(string &s, string &t, int i, int j){
        if(dp[i][j] != -1)
            return dp[i][j];

        if(j == t.length())
            return 1;

        if(i == s.length())
            return 0;

        int ans = 0;

        if(s[i] == t[j]) {
            ans = ans + solve(s, t, i + 1, j + 1);
        }
        
        ans = ans + solve(s, t, i + 1, j);

        return dp[i][j] = ans;
    }


    int numDistinct(string s, string t) {
        memset(dp,-1,sizeof(dp));
        int i = 0; 
        int j = 0;   

        return solve(s, t, i, j);
    }
};