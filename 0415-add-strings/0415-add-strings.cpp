class Solution {
public:
    string addStrings(string a, string b) {
        string ans = "";
        int m=a.size() , n=b.size(),sum=0,carry=0;
        int i=m-1 , j=n-1;

        while(i>=0 && j>=0){ 
            sum = (a[i--]-'0') + (b[j--]-'0') + carry;
            ans.push_back(sum%10 + '0');
            carry = sum/10;
        }
        while(i>=0){ 
            sum = (a[i--]-'0') + carry;
            ans.push_back(sum%10 + '0');
            carry = sum/10;
        }
        while(j>=0){ 
            sum = (b[j--]-'0') + carry;
            ans.push_back(sum%10 + '0');
            carry = sum/10;
        }
        if(carry) ans.push_back('1');
        reverse(ans.begin(),ans.end());
        return ans;
    }
};