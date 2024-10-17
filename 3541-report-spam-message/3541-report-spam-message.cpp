class Solution {
public:
    bool reportSpam(vector<string>& message, vector<string>& bannedWords) {
        unordered_set<string> s;
        for(auto w : bannedWords){
            s.insert(w);
        }
        int cnt = 0;

        for(auto w : message){
            if(s.find(w) != s.end()){
                cnt++;
            }
            if(cnt >= 2){
                return true;
            }
        }
        return false;
    }
};