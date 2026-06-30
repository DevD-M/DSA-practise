class Solution {
public:
    string minWindow(string s, string t) {

        unordered_map<char,int> need;
        unordered_map<char,int> window;
        for (int i =0; i<t.size(); i++){
            char ch = t[i];
            need[ch]++;
        }

        int left = 0;
        int matchedChar = 0;
        int minLen = INT_MAX;
        int start = 0;

        for(int right = 0; right < s.size(); right++){
            char ch = s[right];

            window[ch]++;
            if (need.count(ch) && window[ch] == need[ch]){
                matchedChar++;
            }
            while (matchedChar == need.size()){
                int windowSize = right - left +1;
                if (right - left +1 < minLen){
                    minLen  = windowSize;
                    start = left;
                }
                char leftChar = s[left];
                if (need.count(leftChar) && window[leftChar] == need[leftChar]){
                    matchedChar--;
                }
                window[leftChar]--;
                left++;
            }

        }
        if (minLen == INT_MAX)  return "";
        return s.substr(start, minLen);

    }
};

