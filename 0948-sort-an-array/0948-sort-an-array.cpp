//Merge sort
class Solution {
public:
    void Merge(vector<int>& nums,int s,int mid,int e){
        int i = s;
        int j = mid+1;
        vector<int> arr(e-s+1);
        int idx = 0;

        while(i <= mid && j <= e){
            if(nums[i] <= nums[j]){
                arr[idx++] = nums[i++];
            }
            else{
                arr[idx++] = nums[j++];
            }
        }

        while(i<=mid){
            arr[idx++] = nums[i++];
        }
        while(j<=e){
            arr[idx++] = nums[j++];
        }
        for(int a = s; a <= e; a++){
            nums[a] = arr[a-s]; 
        }
        return;
    }
    void MergeSort(vector<int>& nums,int s,int e){
        if(s >= e){
            return;
        }
        int mid = s + (e-s)/2;
        MergeSort(nums,s,mid);
        MergeSort(nums,mid+1,e);
        Merge(nums,s,mid,e);
        return;
    }
    vector<int> sortArray(vector<int>& nums) {
        MergeSort(nums,0,nums.size()-1);
        return nums;
    }
};

//Quick Sort
// class Solution {
// public:
//     int partition(vector<int>& nums,int s,int e){
//         int i = s;
//         int j = e;
//         int pivot = nums[s];
        
//         while(i<j){
//             while(i<e && nums[i] <= pivot) i++;
//             while(j>s && nums[j] > pivot) j--;

//             if(i<j){
//                 swap(nums[i],nums[j]);
//             }
//         }

//         swap(nums[s],nums[j]);
//         return j;
//     }
//     void QuickSort(vector<int>& nums,int s,int e){
//         if(s >= e){
//             return;
//         }
//         int j = partition(nums,s,e);
//         QuickSort(nums,s,j-1);
//         QuickSort(nums,j+1,e);
//         return;
//     }
//     vector<int> sortArray(vector<int>& nums) {
//         QuickSort(nums,0,nums.size()-1);
//         return nums;
//     }
// };