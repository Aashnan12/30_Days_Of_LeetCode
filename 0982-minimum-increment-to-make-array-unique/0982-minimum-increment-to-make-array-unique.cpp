class Solution {
public:
    int minIncrementForUnique(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        int mini = 0;
        for(int i=1;i<nums.size();i++){
            if(nums[i] <= nums[i-1]){
                int change = 
                abs(nums[i] - nums[i-1]) + 1;
                mini += change;
                nums[i] += change;
            }
        }
        return mini;
    }
};