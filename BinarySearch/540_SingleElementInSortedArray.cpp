// Agar even mid par nums[mid] == nums[mid+1], to single element right side mein hai; warna left side (including mid) mein hai.

class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0;
        int hi = nums.size() - 1;

        while (lo < hi) {
            int mid = lo + (hi - lo) / 2;

            if (mid % 2 == 1) {
                mid--;
            }

            if (nums[mid] != nums[mid + 1]) {
                hi =mid;
                
            } else{
                lo = mid+2;
                
            }
        }
        return nums[hi];
    }
};
