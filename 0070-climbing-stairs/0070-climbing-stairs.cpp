class Solution {
public:
    int climbStairs(int n) {
        if(n==0 || n==1)return n;
        int a = 0;
        int b = 1;
        int num = 0;
        while(n--){
            num = a + b;
            a = b;
            b = num;
        }
        return num;
    }
};