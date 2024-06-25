class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int i = 0, j = 0;
        int sum = 0;

        while (k > 0 && j < n) {
            if (nums[j] == 1) {
                sum++;
            } else {
                sum++;
                k--;
            }
            j++;
        }
        int maxsum = sum;
        cout<<sum<<k;
        while (j < n) {
            if (k <= 0) {
               
                if (nums[j] == 1) {
                    sum++;
                } else {
                    sum++;
                    k++;
                }
                 j++;

            } else if (k > 0) {
              
                if (nums[i] == 1) {
                    sum--;
                } else {
                    sum--;
                    k--;
                }
                  i++;
            }

            if (k <= 0) {
                maxsum = max(sum, maxsum);
            }
        }
        return maxsum;
    }
};