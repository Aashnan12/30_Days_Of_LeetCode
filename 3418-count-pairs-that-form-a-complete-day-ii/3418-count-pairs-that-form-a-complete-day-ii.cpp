#define ll long long
class Solution {
public:
    long long countCompleteDayPairs(vector<int>& A) {
        int n = A.size();
        ll ans = 0;
        unordered_map<ll,ll> mp;
        for(int i=0;i<n;i++){
            int x = A[i] % 24;
            int y = 24 - x;
            y = y % 24;
            ans += mp[y];
            mp[x]++;
        }
        return ans;
    }
};