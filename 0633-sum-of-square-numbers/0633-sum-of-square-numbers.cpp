class Solution {
public:
    bool judgeSquareSum(int c) {
        long long start = 0,end = sqrt(c);

        while(start <= end){
            long long mid = start*start + end*end;
            if(mid == c)return true;
            else if(mid < c) start += 1;
            else end -= 1;
        }
        return false;
    }
};