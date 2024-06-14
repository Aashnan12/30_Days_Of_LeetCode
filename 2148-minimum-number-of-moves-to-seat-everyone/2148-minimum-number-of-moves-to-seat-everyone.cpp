class Solution {
public:
    int minMovesToSeat(vector<int>& a, vector<int>& b) {
        int n = a.size();
        vector<int> chairs(101,0);
        vector<int> stu(101,0);

        for(int i=0;i<n;i++){
            chairs[a[i]]++;
        }
        for(int i=0;i<n;i++){
            stu[b[i]]++;
        }
        int mini = 0;
        int i=0,j=0;
        while(i<101 && j<101){
            if(chairs[i] == 0){
                i++;
            }
            else if(stu[j] == 0){
                j++;
            }
            else{
                mini += abs(j-i);
                chairs[i]--;
                stu[j]--;
            }
        }
        return mini;
    }
};

// class Solution {
// public:
//     int minMovesToSeat(vector<int>& a, vector<int>& b) {
//         sort(a.begin(),a.end());
//         sort(b.begin(),b.end());
//         int mini = 0;
//         for(int i=0;i<a.size();i++){
//             mini += abs(a[i]-b[i]);
//         }
//         return mini;
//     }
// };