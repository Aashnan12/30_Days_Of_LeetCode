class Solution {
public:
    int characterReplacement(string s, int k) {
        int hash[26] = {0};
        int l=0,n=s.size();
        int res=0,maxi=0;
        for(int r=0;r<n;r++){
            hash[s[r]-'A']++;
            maxi = max(maxi,hash[s[r]-'A']);
            if(r-l+1-maxi > k){
                hash[s[l]-'A']--;
                l++;
            }
            res = max(res,r-l+1);
        }
        return res;
    }
};