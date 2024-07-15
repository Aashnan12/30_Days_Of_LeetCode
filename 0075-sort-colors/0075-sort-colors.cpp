class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size(),idx=0,i=0,j=n-1;

        while(idx <= j){
            if(nums[i] == 0){
                i++,idx++;
            }
            else if(nums[j] == 2){
                j--;
            }
            else if(nums[idx] == 0){
                swap(nums[i],nums[idx]);
                i++,idx++;
            }
            else if(nums[idx] == 2){
                swap(nums[j],nums[idx]);
                j--;
            }
            else{
                idx++;
            }
        }
        return;
    }
};