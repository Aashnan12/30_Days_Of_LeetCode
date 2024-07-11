class Solution {
public:
    string reverseParentheses(string str) {
        stack<int> st;
        string s = str;
        int n = s.size();
        
        for(int i = 0;i<n ;i++){
            char ch = s[i];
            if(ch == '('){
                st.push(i);
            }
            else if(ch == ')'){
                int idx = st.top();
                st.pop();
                reverse(s.begin() + idx, s.begin() + i + 1);
            }
        }
        string ans = "";
        for(int i=0;i<n;i++){
            if(s[i] != '(' && s[i] != ')'){
                ans += s[i];
            }
        }
        return ans;
    }
};