class Solution {
public:
    long long subArrayMins(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> pse(n);
        vector<int> nse(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] >= nums[i]) {
                st.pop();
            }
            if (st.empty())
                pse[i] = -1;
            else
                pse[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] > nums[i]) {
                st.pop();
            }
            if (st.empty())
                nse[i] = n;
            else
                nse[i] = st.top();
            st.push(i);
        }
        long long sumMin = 0;
        for (int i = 0; i < n; i++) {
            long long leftmin = i - pse[i];
            long long rightmin = nse[i] - i;
            sumMin = sumMin + (1LL * leftmin * rightmin * nums[i]);
        }
        return sumMin;
    }
    long long subArrayMax(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        vector<int> pge(n);
        const int MOD = 1e9 + 7;
        vector<int> nge(n);
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[st.top()] <= nums[i]) {
                st.pop();
            }
            if (st.empty())
                pge[i] = -1;
            else
                pge[i] = st.top();
            st.push(i);
        }
        st = stack<int>();
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[st.top()] < nums[i]) {
                st.pop();
            }
            if (st.empty())
                nge[i] = n;
            else
                nge[i] = st.top();
            st.push(i);
        }
        long long sumMax = 0;
        for (int i = 0; i < n; i++) {
            long long leftmax = i - pge[i];
            long long rightmax = nge[i] - i;
            sumMax = sumMax + (1LL * leftmax * rightmax * nums[i]);
        }
        return sumMax;
    }
    long long subArrayRanges(vector<int>& nums) { return subArrayMax(nums) - subArrayMins(nums); }
};
