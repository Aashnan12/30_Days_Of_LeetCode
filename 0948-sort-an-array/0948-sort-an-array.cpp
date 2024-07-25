class Solution {
public:
    int partition(vector<int>& nums,int s,int e){
        int i = s;
        int j = e;
        int pivot = nums[s];
        
        while(i<j){
            while(i<e && nums[i] <= pivot) i++;
            while(j>s && nums[j] > pivot) j--;

            if(i<j){
                swap(nums[i],nums[j]);
            }
        }

        swap(nums[s],nums[j]);
        return j;
    }
    void QuickSort(vector<int>& nums,int s,int e){
        if(s >= e){
            return;
        }
        int j = partition(nums,s,e);
        QuickSort(nums,s,j-1);
        QuickSort(nums,j+1,e);
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        QuickSort(nums,0,nums.size()-1);
        return nums;
    }
};