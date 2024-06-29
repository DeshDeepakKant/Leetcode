class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n = matrix.size();
        vector<int> dp(n + 2, INT_MAX);
        for (int i = 1; i <= n; i++) {
            dp[i] = matrix[0][i - 1];
        }
        for (int i = 1; i < n; i++) {
            vector<int> temp(n + 2, INT_MAX);
            for (int j = 1; j <= n; j++) {
                temp[j] = min({dp[j - 1], dp[j], dp[j + 1]}) + matrix[i][j - 1];
            }
            dp = temp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};