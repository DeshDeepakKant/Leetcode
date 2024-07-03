class Solution {
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        if ((s - target) % 2 || (s < target)) {
            return 0;
        }
        s = (s - target) / 2;
        vector<vector<int>> dp(n, vector<int>(s + 1, 0));
        if(nums[0]==0)
        {
            dp[0][0]=2;
        }
        else
        {
            dp[0][0]=1;
        }
        if (nums[0] != 0 && nums[0] <= s)
         dp[0][nums[0]] = 1;

        for (int i = 1; i < n; i++) {
            for (int j = 0; j <= s; j++) {
                int a = dp[i - 1][j];
                int b = 0;
                if (j >= nums[i]) {
                    b = dp[i - 1][j - nums[i]];
                }
                dp[i][j]= a + b;
            }
        }
        return dp[n - 1][s];
    }
};