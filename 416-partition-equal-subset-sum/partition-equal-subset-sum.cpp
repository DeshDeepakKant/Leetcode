class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n = nums.size();
        int s = accumulate(nums.begin(), nums.end(), 0);
        if (s % 2) return false;
        s /= 2;

        vector<vector<bool>> dp(n, vector<bool>(s + 1, false));
        for (int i = 0; i < n; i++) {
            dp[i][0] = true;
        }
        
        if (s>= nums[0])  dp[0][nums[0]] = true;

        for (int i = 1; i < n; i++) {
            for (int j = 1; j <= s; j++) {
                bool nt = dp[i - 1][j];
                bool t = false;
                if (j >= nums[i]) {
                    t = dp[i - 1][j - nums[i]];
                }
                dp[i][j] = (t | nt);
            }
        }
        return dp[n-1][s];
    }
};