class Solution {
public:
    int passThePillow(int n, int time) {
        int res=0,direction;
        while(time--){
            if(res == 0){
                direction = 1;
            }
            else if(res == n-1){
                direction = -1;
            }
            res += direction;
        }
        return res+1;
    }
};