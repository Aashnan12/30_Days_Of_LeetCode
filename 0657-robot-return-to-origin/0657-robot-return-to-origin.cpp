class Solution {
public:
    bool judgeCircle(string moves) {
        int hash[4] = {0};
        for(auto &i : moves){
            if(i == 'U'){
                hash[0]++;
            }
            else if(i == 'D'){
                hash[1]++;
            }
            else if(i == 'R'){
                hash[2]++;
            }
            else{
                hash[3]++;
            }
        }
        return hash[0]==hash[1] && hash[2]==hash[3];
    }
};