class Solution {
public:
    int numberOfSpecialChars(string word) {
        vector<bool> small(26,false);
        vector<bool> caps(26,false);
        
        for(char &ch : word){
            if(ch >= 'A' && ch <= 'Z'){
                caps[ch - 'A'] = true;
            }
            else{
                small[ch - 'a'] = true;
            }
        }
        int ans = 0;
        for(int i=0;i<26;i++){
            if(small[i] && caps[i] && word.find_last_of(i+'a')  < word.find(i+'A')) ans++;
        }
        return ans;
    }
};