class Solution {
public:
    int maxScore(vector<int>& A, int k) {
        int l = 0,r = 0,sum = 0,maxsum = 0,n = A.size();

        for(l=0;l<k;l++){
            sum += A[l];
        }
        maxsum = sum;
        r = n-1;
        l = l-1;

        while(l>=0){
            cout<< l << " "<< r << endl;
            sum = sum + A[r--] - A[l--];
            maxsum = max(maxsum,sum);
        }
        
        return maxsum;
    }
};