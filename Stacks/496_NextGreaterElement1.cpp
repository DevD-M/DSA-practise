class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> mp;
        stack<int> st;
        int nge;
        int i = 0;
        int n = nums2.size();
        vector<int> ans;
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && st.top() <= nums2[i]) {
                st.pop();
            }
            if (st.empty()) {
                nge[i] = -1;
            } else
                nge[i] = st.top();
            st.push(nums2[i]);
            mp[nums2[i]] = nge[i];
        }
        for (int i = 0; i < nums1.size(); i++) {
            ans.push_back(mp[nums1[i]]);
        }

        return ans;
    }
};

//revise - my 1st stack problem
