class Solution {
public:
    bool ok(string &s, int k){
        int hash[26] = {0};
        for(int i = 0; i < k; i++){
            hash[s[i] - 'a']++;
        }
        for(int i = k; i < s.size(); i += k){
            int hash2[26] = {0};
            for(int j = i; j < i+k ; j++){
                hash2[s[j] - 'a']++;
            }
            for(int i=0;i<26;i++){
                if(hash[i] != hash2[i]){
                    return false;
                }
            }
        }
        return true;
    }
    int minAnagramLength(string s) {
        int n  = s.size();
        for(int i = 1; i <= n/2; i++){
            if(n % i == 0 && ok(s,i)){
                return i;
            }
        }
        return n;
    }
};