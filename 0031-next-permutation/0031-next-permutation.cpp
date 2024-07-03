class Solution {
public:
    void nextPermutation(vector<int>& nums) {
        int inf_point = -1;
        int n = nums.size();

        for(int i=n-1;i>0;i--){
            if(nums[i-1] < nums[i]){
                inf_point = i-1;
                break;
            }
        }
        if(inf_point != -1){
            int to_swap = inf_point;

            for(int i = n-1;i > inf_point ;i--){
                if(nums[i] > nums[to_swap]){
                    to_swap = i;
                    break;
                }
            }
            swap(nums[to_swap],nums[inf_point]);
        }
        reverse(nums.begin() + inf_point + 1,nums.end());
        
    }
};