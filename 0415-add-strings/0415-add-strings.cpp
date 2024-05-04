class Solution {
public:
    string addStrings(string a, string b) {
        string ans = "";
        int i=a.size()-1, j=b.size()-1,sum=0;

        while(i>=0 || j>=0 || sum){ 
            if(i>=0){
                sum += a[i--] - '0' ;
            }
            if(j>=0){
                sum += b[j--] - '0';
            }
            ans += sum%10 + '0';
            sum = sum/10;
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};