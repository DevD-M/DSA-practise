class Solution {
public:
    bool isPossible(vector<int>& nums, int k, int maxSum) {
        int parts = 1;
        int currSum = 0;
        for (int i = 0; i < nums.size(); i++) {
            if (currSum + nums[i] <= maxSum) {
                currSum += nums[i];

            } else {
                parts++;
                currSum = nums[i];
            }
        }
        return parts <= k;
    }
    int splitArray(vector<int>& nums, int k){
        int lo = *max_element(nums.begin(), nums.end());
        int hi = 0;
        for (int i=0; i <nums.size(); i++){
            hi += nums[i];
        }
        while (lo <hi){
            int mid = lo + (hi -lo)/2;
            if (isPossible(nums, k , mid)){
                hi = mid;
            }else lo = mid +1;
        }
        return lo;
    }
};
