class Solution {
public:
    int eraseOverlapIntervals(vector<vector<int>>& intervals) {
        sort(intervals.begin(),intervals.end());
        int j = 1;
        int i = 0;
        int ans = 0;
        while(j<intervals.size()){
            if(intervals[i][1] <= intervals[j][0]){ 
                i = j;
                j++;
            }
            else if(intervals[i][1] <= intervals[j][1]){
                j++;
                ans++;
            }
            else if(intervals[i][1] > intervals[j][1]){
                i = j;
                j++;
                ans++;
            }
        }
        return ans;
    }
};