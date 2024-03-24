class Solution {
public:
    unordered_set<string> st;
    int n;
    int t[301];
    bool solve(int index,string &s){
        if(index >= n){
            return true;
        }
        if(t[index] != -1){
            return t[index];
        }
        if(st.find(s) != st.end()){
            return t[index] = true;
        }
        for(int l=1;l<=n;l++){
            string temp = s.substr(index,l);
            if(st.find(temp) != st.end() && solve(index+l,s)){
                return t[index] = true;
            }
        }
        return t[index] = false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        n = s.length();
        memset(t,-1,sizeof(t));
        for(string &word :wordDict){
            st.insert(word);
        }
        return solve(0,s);
    }
};