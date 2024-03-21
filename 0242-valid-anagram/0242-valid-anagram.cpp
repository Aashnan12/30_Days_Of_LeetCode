class Solution {
public:
    bool isAnagram(string s, string t) {
        // if(s.size() != t.size()) return false;
        // sort(s.begin(),s.end());
        // sort(t.begin(),t.end());
        // for(int i=0;i<s.size();i++){
        //     if(s[i] != t[i]){
        //         return false;
        //     }
        // }
        // return true;

        int freqtable[125] = {0};
        for(int i:s){
            freqtable[i]++;
        }
        for(int i:t){
            freqtable[i]--;
        }
        for(int i=0;i<125;i++){
            if(freqtable[i] != 0){
                return false;
            }
        }
        return true;
    }
};