class Solution {
public:
    bool Check(int num)
    {
        if (num < 2) return false;
        if (num % 2 == 0) return (num == 2);
        for (int i = 3; i*i <= num; i += 2)
        {
            if (num % i == 0) return false;
        }
        return true;
    }
    int maximumPrimeDifference(vector<int>& nums) {
        int n = nums.size();
        int j=0,k=n-1;
        while(j<n && !Check(nums[j])) j++;
        while(k>=0 && !Check(nums[k])) k--;
        if(j>k) return 0;
        else return k-j;
    }
};