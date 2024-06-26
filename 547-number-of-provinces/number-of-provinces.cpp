class Solution {
public:
    void dfs(vector<vector<int>>& isConnected, int i, vector<int>& vis, int n) {
        vis[i] = 1;
        for (int j = 0; j < n; j++) {
            if (isConnected[i][j]) {
                if (!vis[j]) {
                    dfs(isConnected, j, vis, n);
                }
            }
        }
        return;
    }

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(isConnected, i, vis, n);
                ans++;
            }
        }
        return ans;
    }
};