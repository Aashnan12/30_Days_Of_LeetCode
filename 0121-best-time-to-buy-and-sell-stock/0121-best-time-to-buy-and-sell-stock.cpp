class Solution {
public:
    int maxProfit(vector<int>& arr) {
        int profit = 0,mini = arr[0];
        for(int i=1;i<arr.size();i++){
            mini = min(mini,arr[i]);
            profit = max(profit,arr[i]-mini);
        }
        return profit;
    }
};