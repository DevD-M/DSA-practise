class Solution {
public:
    //LC 84 code
    int largestRectangleArea(vector<int>& heights){
        stack<int> st;
        int n = heights.size();
        vector<int> pse(n, 0);
        vector<int> nse(n, 0);
        for (int i=0; i<n; i++){
            while (!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if (st.empty()){
                pse[i] = -1;
            }
            else    pse[i] = st.top();
            st.push(i);
        }
        
        st = stack<int>();
        for (int i = n-1; i>=0 ; i--){
            while (!st.empty() && heights[st.top()] >= heights[i]){
                st.pop();
            }
            if (st.empty()) nse[i] = n;
            else nse[i] = st.top();
            st.push(i);
        }
        
        int ans=0;
        for (int i =0; i<n; i++){
            int width = nse[i] - pse[i] - 1;
            int area = heights[i] * width;
            ans = max(ans, area);

        }
        return ans;
    }


    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int rows = matrix.size();
        int cols = matrix[0].size();
        vector<int> heights(cols, 0);
        int maxi =0;
        for (int row=0; row<rows; row++){
            for (int col=0; col< cols; col++){
                if (matrix[row][col] == '1'){
                    heights[col]++;
                }
                else heights[col] =0;
            }
            maxi= max(maxi, largestRectangleArea(heights));
        }
        return maxi;
    }
};
