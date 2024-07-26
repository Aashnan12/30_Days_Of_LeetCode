// Count Sort
class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        unordered_map<int, int> freq;
        int maxi = INT_MIN;
        int mini = INT_MAX;

        for (int num : nums) {
            freq[num]++;
            maxi = max(maxi, num);
            mini = min(mini, num);
        }
        int idx = 0;

        for (int i = mini; i <= maxi; i++) {
            while(freq[i] > 0){
                nums[idx++] = i;
                freq[i]--;
            }
        }
        return nums;
    }
};

// Heap sort
// class Solution {
// public:
//     void BuildHeap(vector<int>& nums, int parent, int n) {
//         int maxi = parent;
//         int c1 = parent * 2 + 1;
//         int c2 = parent * 2 + 2;

//         if (c1 < n && nums[maxi] < nums[c1]) {
//             maxi = c1;
//         }
//         if (c2 < n && nums[maxi] < nums[c2]) {
//             maxi = c2;
//         }

//         if (parent != maxi) {
//             swap(nums[maxi], nums[parent]);
//             BuildHeap(nums, maxi, n);
//         }
//     }
//     void Heapify(vector<int>& nums, int n) {
//         for (int i = n / 2 - 1; i >= 0; i--) {
//             BuildHeap(nums, i, n);
//         }
//     }
//     void HeapSort(vector<int>& nums, int n) {
//         Heapify(nums, n);
//         int size = n - 1;
//         while (size > 0) {
//             swap(nums[0], nums[size]);
//             BuildHeap(nums, 0, size);
//             size--;
//         }
//     }
//     vector<int> sortArray(vector<int>& nums) {
//         HeapSort(nums, nums.size());
//         return nums;
//     }
// };

// Merge sort
//  class Solution {
//  public:
//      void Merge(vector<int>& nums,int s,int mid,int e){
//          int i = s;
//          int j = mid+1;
//          vector<int> arr(e-s+1);
//          int idx = 0;

//         while(i <= mid && j <= e){
//             if(nums[i] <= nums[j]){
//                 arr[idx++] = nums[i++];
//             }
//             else{
//                 arr[idx++] = nums[j++];
//             }
//         }

//         while(i<=mid){
//             arr[idx++] = nums[i++];
//         }
//         while(j<=e){
//             arr[idx++] = nums[j++];
//         }
//         for(int a = s; a <= e; a++){
//             nums[a] = arr[a-s];
//         }
//         return;
//     }
//     void MergeSort(vector<int>& nums,int s,int e){
//         if(s >= e){
//             return;
//         }
//         int mid = s + (e-s)/2;
//         MergeSort(nums,s,mid);
//         MergeSort(nums,mid+1,e);
//         Merge(nums,s,mid,e);
//         return;
//     }
//     vector<int> sortArray(vector<int>& nums) {
//         MergeSort(nums,0,nums.size()-1);
//         return nums;
//     }
// };

// Quick Sort
//  class Solution {
//  public:
//      int partition(vector<int>& nums,int s,int e){
//          int i = s;
//          int j = e;
//          int pivot = nums[s];

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