class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n = nums.size(),index=0,i=0,j=n-1;
        while(index <= j){
            if(nums[i] == 0){
                i++;
                index++;
            }
            else if(nums[j] == 2){
                j--;
            }
            else if(nums[index]==0){
                swap(nums[i],nums[index]);
                i++;
                index++;
            }
            else if(nums[index]==2){
                swap(nums[j],nums[index]);
                j--;
            }
            else{
                index++;
            }
        }
    }
};