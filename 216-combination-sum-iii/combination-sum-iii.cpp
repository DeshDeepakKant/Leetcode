class Solution {
public:
    void f(vector<vector<int>>& ans, vector<int>& v, int k, int n, int s,
           int x) {

        if (s == n && k == 0&&x>=0 ) {
            ans.push_back(v);
            return;
        }
        if (s > n || k < 0 || x < 1) {
            return;
        }

        f(ans, v, k, n, s, x - 1); // nt
        v.push_back(x);
        f(ans, v, k - 1, n, s + x, x - 1);
        v.pop_back();
        return;
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> v;
        f(ans, v, k, n, 0, 9);
        return ans;
    }
};