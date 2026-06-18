class Solution {
public:
    string removeOuterParentheses(string s) {
        int currDepth = 0;
        string ans;

        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(') {
                if (currDepth > 0) {
                    ans += '(';
                }
                currDepth++;

            } else if (s[i] == ')') {
                currDepth--;
                if (currDepth > 0) {
                    ans += ')';
                }
            }
        }
        return ans;
    }
};
