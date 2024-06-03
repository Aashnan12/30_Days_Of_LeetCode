class Solution {
public:
    int t[10010];
    int solve(int amt,vector<int>& coins){
        if(amt == 0){
            return 0;
        }
        if(t[amt] != -1){
            return t[amt];
        }
        int ans = INT_MAX;
        for(int coin : coins){
            if(amt - coin >= 0){
                ans = min(ans + 0LL ,solve(amt-coin,coins) + 1LL);
            }
        }
        return t[amt] = ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        memset(t,-1,sizeof(t));
        int ans = solve(amount,coins);
        return ans == INT_MAX ? -1 : ans;
    }
};