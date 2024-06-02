class Solution {
public:
    int minimumChairs(string s) {
        int chairs = 0;
        int e = 0;

        for(int i=0;i<s.size();i++){
            if(s[i] == 'E')e++;
            if(s[i] == 'L')e--;
            if(chairs < e){
                chairs++;
            }
        }
        return chairs;
    }
};