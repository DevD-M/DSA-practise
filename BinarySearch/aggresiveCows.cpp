class Solution {
  public:
    int aggressiveCows(vector<int> &stalls, int k) {
        int lo = 1;
        int ans=0;
        sort(stalls.begin(), stalls.end());
        int hi = stalls[stalls.size()-1] - stalls[0];
        while (lo < hi){
            int mid= lo +(hi-lo)/2;
            
            if (canPlace(stalls, k, mid)){
                ans= mid;
                lo = mid+1;
            }
            else hi = mid-1;
        }
        return ans;
    }
    bool canPlace(vector<int>& stalls, int k, int minDist){
        int cowsPlaced =1; 
        int lastPos = stalls[0];
        for (int i=1; i< stalls.size(); i++){
            if (stalls[i]- lastPos >= minDist){
                cowsPlaced++;
                lastPos = stalls[i];
            }
            if (cowsPlaced == k ) return true;
        }
        return false;
    }
};


//bhot hard qiues dubara revise krna 
// this is not on lc but gfg 
// https://www.geeksforgeeks.org/problems/aggressive-cows/1
