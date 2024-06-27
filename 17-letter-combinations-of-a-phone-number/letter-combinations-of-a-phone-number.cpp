class Solution {
public:
    void f(int i, string digits, vector<string>& ans, int n, vector<string>& v,
           string& s) {
        if (i == n) {
            ans.push_back(s);
            return;
        }
        for (char it : v[(digits[i] - '0')]) {
            s.push_back(it);
            f(i + 1, digits, ans, n, v, s);
            s.pop_back();
        }
        return;
    }
    vector<string> letterCombinations(string digits) {
        if (digits.empty()) return {};
        vector<string> v = {"0",   "0",   "abc",  "def", "ghi",
                            "jkl", "mno", "pqrs", "tuv", "wxyz"};
        int n = digits.size();
        vector<string> ans;
        string s="";
        f(0, digits, ans, n, v, s);
        return ans;
    }
};