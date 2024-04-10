class Solution {
public:
    bool isValid(string s){
        stack<int> stk;
        for(char c : s){
            if(c=='('){
                stk.push(c);
            }
            else{
                if(stk.empty() || (c==')' && stk.top()!= '(')){
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
    void backtracking(vector<string> &result, string &temp,int n){
        if(temp.size() == 2*n){
            if(isValid(temp))result.push_back(temp);
            return;
        }
        temp.push_back('(');
        backtracking(result,temp,n);
        temp.pop_back();

        temp.push_back(')');
        backtracking(result,temp,n);
        temp.pop_back();
    }
    vector<string> generateParenthesis(int n) {
        vector<string> result;
        string temp = "";
        backtracking(result,temp,n);
        return result;
    }
};