class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int dup = 0;
        for(int i=0;i<nums.size();i++){
            int num = abs(nums[i]);
            if(nums[num] < 0) return num;
            nums[num] *= -1;
        }
        return -1;
    }
};