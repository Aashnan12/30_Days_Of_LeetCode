class Solution {
public:
    int largestRectangleArea(vector<int>& height) {
        int maxi = 0;
        stack<int> stack;
        for(int i=0;i<=height.size();i++){
            while(!stack.empty() && (i==height.size() || height[stack.top()] > height[i])){
                const int m = height[stack.top()];
                stack.pop();
                const int v = stack.empty() ? i : i-stack.top()-1;
                maxi = max(maxi,m*v);
            }
            stack.push(i);
        }
        return maxi;
    }
};