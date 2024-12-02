class Solution {
public:
    int isPrefixOfWord(string s, string t) {
        s = " " + s;
        t = " " + t;
        int k = s.find(t);
        if(k == -1) return -1;
        return 1 + count(s.begin(),s.begin()+k,' ');
    }
};