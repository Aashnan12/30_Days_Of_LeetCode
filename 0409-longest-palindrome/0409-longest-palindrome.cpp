class Solution {
public:
    int longestPalindrome(string s) {
        int hash[128] = {0};

        for(char& ch : s){
            hash[ch]++;
        }

        int oddfreq = 0;
        for(int i=0;i<128;i++){
            if(hash[i] & 1){
                oddfreq++;
            }
        }
        if(oddfreq == 0) return s.size();
        return s.size() - oddfreq + 1; // Ek odd use kr lenge hum.
    }
};