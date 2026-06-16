class Solution {
public:
    string reverseWords(string s) {
        vector<string> words;
        int n = s.size();
        int i = 0;
        string ans="";
        
        while ( i<n && s[i] == ' '){
            i++;
        }
        
        while (i<n){
            while (i<n && s[i]==' ')
                i++;
            string word = "";
            while ( i<n && s[i] != ' '){
            word += s[i];
            i++;
            
            }
            
            if (!word.empty())
                words.push_back(word);
        }
        
         
        for ( int i =words.size()-1; i >=0; i--){
            ans += words[i];
            if (i !=0){
                ans += " ";
            }
        }
        return ans;
    }
};

//revise
// tc = O(n) = sc
