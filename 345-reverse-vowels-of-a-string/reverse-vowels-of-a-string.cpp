class Solution {
public:
    string reverseVowels(string s) {
        int n = s.length();
        vector<pair<int, char>> v;
        string vowels = "aeiouAEIOU";
        for (int i = 0; i < n; i++) {
            if (vowels.find(s[i]) != -1) {
                v.push_back({i, s[i]});
            }
        }
        int nn = v.size();
        for (int i = 0; i < nn; i++) {
            s[v[i].first] = v[nn - i - 1].second;
        }
        return s;
    }
};