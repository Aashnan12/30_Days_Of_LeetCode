class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int x;
        int count = 0;
        for(int i : nums){
            if(count == 0){
                x = i;
                count = 1;
            }
            else if(i==x){
                count++;
            }
            else{
                count--;
            }
        }
        return x;
    }
};