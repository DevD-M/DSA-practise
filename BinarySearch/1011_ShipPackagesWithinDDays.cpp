class Solution {
public:
    int shipWithinDays(vector<int>& weights, int days) {
        int lo = *max_element(weights.begin(), weights.end());;  //min possible cap

        int hi = accumulate(weights.begin(), weights.end(), 0); // max possible cap all in 1 day

        int ans= hi;

        while (lo <= hi){
            int mid = lo + (hi-lo)/2;
            int currD =0;
            int daysNeeded = 1;
            for (int i =0; i<weights.size(); i++){
                
                
                if (currD + weights[i] > mid){
                    daysNeeded++;
                    currD = weights[i];
                }
                else{
                    currD += weights[i];
                }
                
            }
            if (daysNeeded <=days){
                hi = mid-1;
                ans = mid;
            }
            else lo = mid +1;
        } 
        return ans;
    }
};
