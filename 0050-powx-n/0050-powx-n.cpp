class Solution {
public:
    double myPow(double x, int n) {
        bool flag = n>0;
        n = abs(n);
        double ans=1;
        while(n>0){
            if((n&1)==1){
                ans = ans*x;
            }
            x = x*x;
            n = n>>1;
        }
        return flag == true?ans:1.00000/ans;
    }
};