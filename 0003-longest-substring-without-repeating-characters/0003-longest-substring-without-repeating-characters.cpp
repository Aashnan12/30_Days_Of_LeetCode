class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int freq[256] = {0};
        int i = 0,j = 0;
        int n = s.size();
        if(n==0)return 0;
        int maxi = INT_MIN;

        while(j<n){
            if(freq[s[j]] == 0){
                freq[s[j]]++;
                maxi = max(maxi,j-i+1);
                j++;
            }
            else{
                freq[s[i]]--;
                i++;
            }
        }
        return maxi;
    }
};