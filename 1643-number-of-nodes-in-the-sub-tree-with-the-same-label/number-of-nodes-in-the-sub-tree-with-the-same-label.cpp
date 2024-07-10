class Solution {
public:
    int n;
    
    vector<int> dfs(int i, int j, vector<int> adj[], string& labels, vector<int>& result) {
        vector<int> temp(26, 0);
        temp[labels[i] - 'a']++;
        for (auto it : adj[i]) {
            if (it != j) {
                vector<int> v = dfs(it, i, adj, labels, result);
                for (int k = 0; k < 26; k++) {
                    temp[k] += v[k];
                }
            }
        }
        result[i] = temp[labels[i] - 'a'];
        return temp;
    }
    
    vector<int> countSubTrees(int n, vector<vector<int>>& edges, string labels) {
        vector<int> adj[n];
        for (auto it : edges) {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        vector<int> result(n, 0);
        dfs(0, -1, adj, labels, result);
        return result;
    }
};
