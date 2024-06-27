class Solution {
public:
    long long k;
    long long bs(vector<int>& arr, long long x) {

        long long n = arr.size();
        long long low = 0, high = n - 1;
        long long ans = n;

        while (low <= high) {
            long long mid = (low + high) / 2;
            // maybe an answer
            if (arr[mid] * x >= k) {
                ans = mid;
                // look for smaller index on the left
                high = mid - 1;
            } else {
                low = mid + 1; // look on the right
            }
        }
        return ans;
    }
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions,
                                long long success) {

        long long n = spells.size();
        k = success;
        sort(potions.begin(), potions.end());
        vector<int> ans(n);
        for (int i = 0; i < n; i++) {
            long long temp = spells[i];
            cout << temp << "  ";
            ans[i] = potions.size() - bs(potions, temp);
            // ans[i] = bs(potions, temp);
        }
        return ans;
    }
};