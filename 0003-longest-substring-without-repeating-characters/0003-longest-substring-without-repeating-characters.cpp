class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> mp;
        int l=0,r=0,n=s.size();
        int maxlen = 0;
        while(r < n){
            if(mp.find(s[r]) != mp.end() &&  mp[s[r]] >= l){
                l = mp[s[r]] + 1;
            }
            maxlen = max(maxlen,r-l+1);
            mp[s[r]] = r;
            r = r+1;
        }
        return maxlen;
    }
};