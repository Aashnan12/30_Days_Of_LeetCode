class Solution {
public:
    int expand(string s,int i,int j){
        int count = 0;
        while(i>=0 && j<s.size() && s[i] == s[j]){
            count++;
            i--;
            j++;
        }
        return count;
    }
    int countSubstrings(string s) {
        int total = 0;
        for(int i=0;i<s.size();i++){
            total += expand(s,i,i) + expand(s,i,i+1);
        }
        return total;
    }
};