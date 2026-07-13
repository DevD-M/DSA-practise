class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        vector<int> ans;
        int n = asteroids.size();

        for (int i = 0; i < n; i++) {
            int x = asteroids[i];
            bool alive = true;
            while (!st.empty() && st.top() > 0 && x < 0) {
                if (abs(x) > st.top()) {
                    st.pop();
                    continue;
                } else if (abs(x) == st.top()) {
                    st.pop();
                    alive = false;
                    break;
                } else {
                    alive = false;
                    break;
                }
            }
            if (alive == true) {
                st.push(x);
            }
        }
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
