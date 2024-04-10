class Solution {
public:

    int getQuotient(long long int a,long long int b) {
        long long int s = 0;
        long long int e = a;
        long long int ans = -1;

        while(s<=e){
            long long int mid = s+(e-s)/2;
    
            if(mid*b == a){
                return mid;
            }
            else if(mid*b < a){
                ans = mid;
                s = mid+1;
            }
            else {
                e = mid-1;
            }
        }
        return ans;
    }

    int divide(int dividend, int divisor) {
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;

        long long int ans = getQuotient(abs(dividend),abs(divisor));

        if(ans > INT_MAX) return INT_MAX;
        if(ans < INT_MIN) return INT_MIN;

        if((dividend<0 && divisor>0) || (dividend>0 && divisor<0)) {
            ans = -ans;
        }

        return ans;
    }
};