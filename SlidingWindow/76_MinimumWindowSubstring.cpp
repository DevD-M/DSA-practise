class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> need;
        unordered_map<char,int> window;

        // build need map
        for(char ch : t)
            need[ch]++;

        int left = 0;
        int matchedChars = 0;

        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++)
        {
            char ch = s[right];

            // expand
            window[ch]++;

            if(need.count(ch) &&
               window[ch] == need[ch])
            {
                matchedChars++;
            }

            // valid window
            while(matchedChars == need.size())
            {
                // update answer
                if(right - left + 1 < minLen)
                {
                    minLen = right - left + 1;
                    start = left;
                }

                char leftChar = s[left];

                // shrink
                if(need.count(leftChar) &&
                   window[leftChar] == need[leftChar])
                {
                    matchedChars--;
                }

                window[leftChar]--;
                left++;
            }
        }

        if(minLen == INT_MAX)
            return "";

        return s.substr(start, minLen);
    }
};
