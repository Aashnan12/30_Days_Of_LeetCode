class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> stk;

        int n = asteroids.size();

        for(int i=0;i<n;i++){
            bool flag = true;

            while(!stk.empty() && asteroids[i] < 0 && asteroids[stk.top()] > 0){
                if(asteroids[stk.top()] < -asteroids[i]){ 
                    stk.pop();
                }
                else if(asteroids[stk.top()] == -asteroids[i]){
                    stk.pop();
                    flag = false;
                    break;
                }
                else{
                    flag = false;
                    break;
                }
            }
            if(flag){
                stk.push(i);
            }
            
        }

        vector<int> ans;
        while(!stk.empty()){
            ans.push_back(asteroids[stk.top()]);
            stk.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};