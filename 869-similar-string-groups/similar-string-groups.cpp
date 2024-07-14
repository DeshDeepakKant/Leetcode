class Solution {
public:
    int l;
    int n;
    bool check(string& a, string& b) {
        int diff = 0;
        for (int i = 0; i < l; i++) {
            if (a[i] != b[i]) {
                diff++;
            }
        }
        if (diff == 0 || diff == 2) {
            return true;
        }
        return false;
    }
    void dfs(int i, vector<int>& vis, vector<string>& strs) {
        vis[i] = 1;
        for (int k = 0; k < n; k++) {
            // if (k != i) {
            if (check(strs[i], strs[k]) && k != i && (!vis[k])) {
                dfs(k, vis, strs);
                // }
            }
        }
        return;
    }
    int numSimilarGroups(vector<string>& strs) {
        n = strs.size();
        l = strs[0].length();
        vector<int> vis(n, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (!vis[i]) {
                dfs(i, vis, strs);
                ans++;
            }
        }
        return ans;
    }
};