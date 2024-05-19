class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        if(nums.size() == 1) return true;

        for(int i=1;i<nums.size();i++){
            bool left = (nums[i-1] & 1);
            bool right = (nums[i] & 1);
            if(left == right) return false;
        }
        return true;
    }
};