class Solution {
public:
    int reverseno(int num){
        int n=0,d=0;
        while(num!=0){
            d = num % 10;
            if(n > INT_MAX/10)return n;
            n = n*10+d;
            num = num/10;
        }
        return n;
    }
    bool isPalindrome(int x) {
        if(x<0)return false;
        if(x>=0 && x<=9)return true;
        int copy = reverseno(x);
        return copy==x;
    }
};