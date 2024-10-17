class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;

        int i=0,j=0;
        int n = s.size();
        int maxi = 0;

        while(i<n){
            if(mp.find(s[i]) != mp.end() && mp[s[i]] >= j){
                j = mp[s[i]] + 1;
            }
            maxi = max(maxi,i-j+1);
            mp[s[i]] = i;
            i++;
        }
        return maxi;
    }
};