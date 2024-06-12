class Solution {
public:
    void sortColors(vector<int>& nums) {
        int left = 0,right = nums.size()-1, idx = 0;
        while(idx <= right){
            cout<<nums[idx]<<" ";
            if(nums[left] == 0)left++,idx++;
            else if(nums[right] == 2) right--;
            else if(nums[idx] == 0){
                swap(nums[idx],nums[left]);
                left++,idx++;
            }
            else if(nums[idx] == 2){
                swap(nums[idx],nums[right]);
                right--;
            }
            else{
                idx++;
            }
        }
    }
};