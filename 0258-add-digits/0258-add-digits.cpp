class Solution {
public:
    int addDigits(int num) {
        // while(num > 9){
        //     int temp = num;
        //     int sum = 0;
        //     while(temp != 0){
        //         sum += temp%10;
        //         temp = temp/10;
        //     }
        //     num = sum;
        // }
        // return num;
        if(num==0)return num;
        if(num%9 == 0) return 9;
        return num%9;
    }
};