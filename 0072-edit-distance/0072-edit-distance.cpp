class Solution {
public:
    int dp[501][501];
    int solve(int i,int j,string& s,string& t,int n,int m){
        if(i >= n) return m-j;
        if(j >= m) return n-i;
        if(dp[i][j] != -1) return dp[i][j];
        int ans = 0;
        if(s[i] == t[j]){
            ans = 0 + solve(i+1,j+1,s,t,n,m);
        }
        else{//Mis Match
            int opt1 = 1 + solve(i,j+1,s,t,n,m); // insert
            int opt2 = 1 + solve(i+1,j,s,t,n,m); // remove
            int opt3 = 1 + solve(i+1,j+1,s,t,n,m); // replace
            ans = min(opt1,min(opt2,opt3));
        }
        return dp[i][j] = ans;
    }
    int minDistance(string word1, string word2) {
        memset(dp,-1,sizeof(dp));
        return solve(0,0,word1,word2,word1.size(),word2.size());
    }
};