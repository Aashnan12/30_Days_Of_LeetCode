class Solution {
public:
    int myAtoi(string s) {
        int i=0,n=s.size(),sign = 1,ans=0;
        bool pos = false,neg = false;
        while(i<n && s[i] == ' ')i++;
        if(i<n && s[i] == '+'){
            i++;
            pos = true;
        }
        if(i<n && s[i] == '-'){
            i++;
            neg = true;
        }
        if(pos && neg)return 0;
        while(i<n && s[i] >= '0' && s[i] <= '9'){
            if(ans >INT_MAX/10 || (ans==INT_MAX/10 && s[i] > '7')){
                return neg?INT_MIN : INT_MAX;
            }
            ans = ans*10 + (s[i]-'0');
            i++;
        } 
        return neg?-ans:ans;
    }
};