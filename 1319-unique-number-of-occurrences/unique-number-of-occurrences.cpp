class Solution {
public:
    bool uniqueOccurrences(vector<int>& arr) {
        map<int, int> mp;
        int n = arr.size();
        for (int i = 0; i < n; i++) {
            mp[arr[i]]++;
        }
        set<int> st;
        for (auto it : mp) {
            st.insert(it.second);
        }
        return (mp.size() == st.size());
    }
};