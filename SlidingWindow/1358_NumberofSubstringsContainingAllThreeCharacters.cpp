int numberOfSubstrings(string s) {
    int left = 0, total = 0;
    vector<int> count(3, 0);  // count['a'-'a'], count['b'-'a'], count['c'-'a']
    
    for (int right = 0; right < s.size(); right++) {
        count[s[right] - 'a']++;
        
        while (count[0] > 0 && count[1] > 0 && count[2] > 0) {
            count[s[left] - 'a']--;
            left++;
        }
        
        // left ab "ek step zyada aage" chala gaya hai (invalid bana diya)
        // isliye valid substrings count = left (no +1, kyunki left already aage badh gaya)
        total += left;
    }
    
    return total;
}
