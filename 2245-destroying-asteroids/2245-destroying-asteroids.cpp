class Solution {
public:
    bool asteroidsDestroyed(int m, vector<int>& asteroids) {
        sort(asteroids.begin(),asteroids.end());
        long long int mass = m;
        for(int i=0;i<asteroids.size();i++){
            if(mass < asteroids[i]){
                return false;
            }
            else{
                mass += asteroids[i];
            }
        }
        return true;
    }
};