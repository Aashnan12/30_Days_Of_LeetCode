class Solution {
public:
    int LowerBound(vector<int> &arr,int target){
        int s = 0,e = arr.size()-1,ans=-1,mid;
        while(s<=e){
            mid = s+(e-s)/2;
            if(arr[mid] == target){
                ans = mid;
                e = mid-1;
            }
            else if(arr[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
    int UpperBound(vector<int> &arr,int target){
        int s = 0,e = arr.size()-1,ans=-1,mid;
        while(s<=e){
            mid = s+(e-s)/2;
            if(arr[mid] == target){
                ans = mid;
                s= mid+1;
            }
            else if(arr[mid] < target){
                s = mid+1;
            }
            else{
                e = mid-1;
            }
        }
        return ans;
    }
    vector<int> searchRange(vector<int>& nums, int target) {
        if(nums.size() == 0){
            return {-1,-1};
        }
        int lb = LowerBound(nums,target);
        if(lb == -1){
            return {-1,-1};
        }
        int ub = UpperBound(nums,target);
        return {lb,ub};
    }
};