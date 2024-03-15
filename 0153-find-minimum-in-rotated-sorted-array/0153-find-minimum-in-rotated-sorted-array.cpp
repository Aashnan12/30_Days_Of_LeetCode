class Solution {
public:
    int findMin(vector<int>& nums) {
        int s = 0;
        int e = nums.size()-1;
        while(s<=e){
            int mid = s + (e-s)/2;
            if(s==e){
                return nums[s];
            }
            else if(mid-1 >= 0 && nums[mid] < nums[mid-1]){
                return nums[mid];
            }
            else if(mid+1 < nums.size() && nums[mid] > nums[mid+1]){
                return nums[mid+1];
            }
            else if(nums[mid] > nums[e]){
                s = mid+1;
            }
            else {
                e = mid;
            }
        }
        return -1;
    }
};