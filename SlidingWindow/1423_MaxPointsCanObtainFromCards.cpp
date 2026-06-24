class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int totalSum=0;
        int n = cardPoints.size();
        int windowSize = n-k;
        int windowSum=0;

        
        for (int x=0; x<n; x++){
            totalSum+=cardPoints[x];
        }
        if (windowSize ==0) return totalSum;

        for (int i=0;i<windowSize; i++){
            windowSum+= cardPoints[i];
        }
        int minWindowSum = windowSum;

        for (int right = windowSize; right <n; right++){
            windowSum -= cardPoints[right- windowSize];
            windowSum += cardPoints[right];

            minWindowSum = min(minWindowSum, windowSum);

        }
        return totalSum - minWindowSum;
    }
};
