class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int i = 0, j = 0;
        while (j < nums.size()) {
            if (nums[i]) {
                i++;
                j=i;
            } else if (!nums[j]) {
                j++;
            } else if (!nums[i] && nums[j]) {
                swap(nums[i], nums[j]);
            }
        }
    }
};