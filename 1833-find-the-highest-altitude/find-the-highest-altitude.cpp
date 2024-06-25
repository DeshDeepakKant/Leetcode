class Solution {
public:
    int largestAltitude(vector<int>& gain) {
        int n = gain.size();
        for (int i = 1; i < n; i++) {
            gain[i] += gain[i - 1];
        }
        int m = *max_element(gain.begin(), gain.end());
        return max(0, m);
    }
};