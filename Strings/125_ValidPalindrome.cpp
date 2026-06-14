class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0;
        int n = s.size();
        int right = n-1;

        while (left < right){
            if (!isalnum(s[left])){
                left++;
                continue;
            }
            if (!isalnum(s[right])){
                right--;
                continue;
            }

            else if (tolower(s[left]) != tolower(s[right])){
                return false;
            }
            else {
                left++;
                right--;
            }
                
        }
        return true;
    }
};
