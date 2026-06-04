class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int lo=1, hi = *max_element(piles.begin(), piles.end());
        int ans = hi;

        while (lo <= hi){
            int mid = lo + (hi-lo)/2;
            long long hours = 0;
            for (int i =0; i < piles.size(); i++){
                hours += (piles[i] +mid-1)/mid;  //this is formula for ceil(pile/mid), ceil(a/b)= (a+b-1)/b

            }
            if (hours <= h){
                hi = mid-1;
                ans= mid;
            }
            else lo = mid+1;
        }
        return ans;
    }
};
