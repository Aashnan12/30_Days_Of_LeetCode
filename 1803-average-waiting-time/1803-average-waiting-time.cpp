class Solution {
public:
    double averageWaitingTime(vector<vector<int>>& arr) {
        ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
        int waiting = 0;
        double ans = 0;
        int n = arr.size();

        for(int i = 0; i<n ; i++){
            int start = arr[i][0];
            int end = arr[i][1];

            if(waiting > start){
                waiting += end;
            }
            else{
                waiting = start + end;
            }
            ans += waiting - start;
        }
        cout<<ans << " "<< n;
        return ans/n;
    }
};