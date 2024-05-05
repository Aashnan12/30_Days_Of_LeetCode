class Solution {
public:
    int CheckDivisor(int n){
        int count = 0,sum = 0;
        for(int i=2;i<=n/2;i++){
            if(n%i == 0){
                count++;
                sum += i;
            }
            if(count > 2){
                return 0;
            }
        }
        if(count == 2){
            return sum+n+1;
        }
        return 0;
    }
    int sumFourDivisors(vector<int>& nums) {
        int sum = 0;
        for(auto n : nums){
            sum += CheckDivisor(n);
        }
        return sum;
    }
};