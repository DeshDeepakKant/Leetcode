class Solution {
public:
    bool canPlaceFlowers(vector<int>& flowerbed, int n) {
        int length = flowerbed.size();
        int i = 0;
        int j = length - 1;
        int ans = 0;
        int current = 0;
        while (i <= j) {
            if (flowerbed[i] == 0) {
                current++;
                i++;
            } else {
                break;
            }
        }
        if (i > j) {
            return (n <= (current + 1) / 2);
        }
        ans += (current / 2);
        current = 0;
        while (i <= j) {
            if (flowerbed[j] == 0) {
                current++;
                j--;
            } else {
                break;
            }
        }
        ans += (current / 2);
        current = 0;
        for (int k = i; k <= j; k++) {
            if (flowerbed[k] == 0) {
                current++;
            } else {
                ans += ((current - 1) / 2);
                current = 0;
            }
        }
        ans += ((current - 1) / 2);
        cout<<ans;
        return (n<=ans);
    }
};