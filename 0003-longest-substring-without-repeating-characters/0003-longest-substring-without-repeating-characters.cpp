class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> freq;
        int maxlen = 0;
        int left = 0;
        for(int i=0;i<s.size();i++){
            freq[s[i]]++;

            while(freq[s[i]] > 1){
                freq[s[left]]--;
                left++;
            }

            maxlen = max(maxlen,i - left + 1);
        }
        return maxlen;
    }
};