class Solution {
    public boolean[] isArraySpecial(int[] nums, int[][] queries) {
        int n = queries.length;
        boolean[] ans = new boolean[n];
        int m = nums.length;
        
        int[] parity_diff = new int[m];
        for (int i = 1; i < m; i++) {
            parity_diff[i] = (nums[i] % 2 != nums[i - 1] % 2) ? 1 : 0;
        }
        
        int[] prefix_sum = new int[m];
        for (int i = 1; i < m; i++) {
            prefix_sum[i] = prefix_sum[i - 1] + parity_diff[i];
        }

        for (int i = 0; i < n; i++) {
            int left = queries[i][0];
            int right = queries[i][1];
            
            int parity_changes = prefix_sum[right] - prefix_sum[left];
            ans[i] = (parity_changes == (right - left));
        }
        
        return ans;
    }
}