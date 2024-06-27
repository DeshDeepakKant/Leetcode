class Solution {
public:
    bool check(long long mid, vector<int>& piles,int h) {
        long long ans = 0;
        for (auto it : piles) {
            ans += ceil((1.0 * it) / mid);
        }
        if (h >= ans) {
            return true;
        }
        return false;
    }
    int minEatingSpeed(vector<int>& piles, int h) {

        long long l = 1, r = 1e9;
        int ans=-1;
        while (l <= r) {
            long long mid = (l + r) / 2;
            if (check(mid, piles, h)) {
                ans=mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
        return ans;
    }
};