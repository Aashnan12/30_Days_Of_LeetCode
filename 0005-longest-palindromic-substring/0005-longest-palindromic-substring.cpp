class Solution {
public:
    string expand(string s,int i,int j,int n){
        while(i>=0 && j<n && s[i]==s[j]){
            i--,j++;
        }
        return s.substr(i+1,j-i-1);
    }
    string longestPalindrome(string s) {
        int n = s.size(),count = 0;
        string even,odd,ans="";
        for(int i=0;i<n;i++){
            even = expand(s,i,i,n);
            odd = expand(s,i,i+1,n);
            if(even.size() > ans.size()){
                ans = even;
            }
            if(odd.size() > ans.size()){
                ans = odd;
            }
        }
        return ans;
    }
};