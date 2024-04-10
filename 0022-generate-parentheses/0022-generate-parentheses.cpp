class Solution {
public:
    // bool isValid(string s){
    //     stack<int> stk;
    //     for(char c : s){
    //         if(c=='('){
    //             stk.push(c);
    //         }
    //         else{
    //             if(stk.empty() || (c==')' && stk.top()!= '(')){
    //                 return false;
    //             }
    //             stk.pop();
    //         }
    //     }
    //     return stk.empty();
    // }
    void backtracking(vector<string> &result, string &temp,int n,int open,int close){
        if(temp.size() == 2*n){
            // if(isValid(temp)
            result.push_back(temp);
            return;
        }
        if(open < n){
            temp.push_back('(');
            backtracking(result,temp,n,open+1,close);
            temp.pop_back();
        }

        if(close < open){
            temp.push_back(')');
            backtracking(result,temp,n,open,close+1);
            temp.pop_back();
        }
    }
    vector<string> generateParenthesis(int n) {
        // Better Approach
        int open=0,close=0;
        vector<string> result;
        string temp = "";
        backtracking(result,temp,n,open,close);
        return result;
    }
};