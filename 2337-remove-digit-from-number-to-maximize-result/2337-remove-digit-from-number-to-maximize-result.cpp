class Solution {
public:
    string removeDigit(string s, char digit) {
        int id=0;
        for(int i=0;i<s.size();i++){
            if(s[i] == digit ){
                id = i;
                if(i+1<s.size() && s[i] < s[i+1])break;
            }
        }
        return s.substr(0,id) + s.substr(id+1);
    }
};