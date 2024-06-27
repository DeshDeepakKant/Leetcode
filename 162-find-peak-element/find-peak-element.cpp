class Solution {
public:
    int bs(vector<int>& nums) {
        int l = 0, h = nums.size() - 1;
        if (l == h) {
            return l;
        }
        while (l <= h) {
            int mid = (l + h) / 2;
            if (mid == 0 ) {
                if(nums[mid + 1] < nums[mid])
                {
                return mid;}
                l=mid+1;
            } else if (mid == nums.size() - 1) {
                if(nums[mid - 1] < nums[mid])
                {
                return mid;}
                h=mid-1;
            } else if (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid]) {
                return mid;
            } else if (nums[mid - 1] < nums[mid] && nums[mid + 1] > nums[mid]) {
                l = mid + 1;
            } else {
                h = mid - 1;
            }
        }
        return -1;
    }
    int findPeakElement(vector<int>& nums) { return bs(nums); }
};