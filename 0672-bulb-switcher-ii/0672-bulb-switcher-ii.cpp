class Solution {
public:
    int flipLights(int n, int p) {
        if(n==1){
            if(p==0){
                return 1;
            }
            else{
                return 2;   
            }
        }
        if(n==2){
            if(p==0){
                return 1;
            }
            else if(p==1) {
                return 3;
            }
            else{
                return 4;
            }
        }
        if(n >= 3){
            if(p==0){
                return 1;
            }
            else if(p==1){
                return 4;
            }
            else if(p==2){
                return 7;
            }
            else{
                return 8;
            }
        }
        return 8;
    }
};