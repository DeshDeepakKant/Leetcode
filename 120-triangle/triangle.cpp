class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<int> dp(3, INT_MAX);
        dp[1] = triangle[0][0];
        for (int i = 1; i < n; i++) {
            vector<int> temp(i + 3, INT_MAX);
            for (int j = 1; j <= i + 1; j++) {
                temp[j] = min(dp[j - 1], dp[j]) + triangle[i][j - 1];
            }
            dp = temp;
        }
        return *min_element(dp.begin(), dp.end());
    }
};