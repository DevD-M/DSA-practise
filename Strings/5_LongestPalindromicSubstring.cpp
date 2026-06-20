class Solution {
    string s;
    int startIndex = 0;
    int maxLen = 0;

    void expand(int left, int right)
    {
        while (left>=0 && right<s.size() && s[left]== s[right] )
        {
            int currLen = right - left +1;

            if (currLen > maxLen)
            {
                maxLen = currLen;
                startIndex = left;
            }

            left--;
            right++;
        }
    }

public:
    string longestPalindrome(string str)
    {
        s = str;
        int n = s.size();

        for (int i = 0; i < n; i++)
        {
            expand(i, i);      // odd
            expand(i, i+1);    // even
        }

        return s.substr(startIndex, maxLen);
    }
};
