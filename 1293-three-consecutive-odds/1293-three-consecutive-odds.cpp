class Solution {
public:
    bool threeConsecutiveOdds(vector<int>& arr) {
        if(arr.size()==1 || arr.size()==2) return false;
        for(int i = 2; i < arr.size(); i++){
            if(arr[i]%2 && arr[i-1]%2 && arr[i-2]%2) return true;
        }
        return false;
    }
};