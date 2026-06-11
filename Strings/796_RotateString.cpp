class Solution {
public:
    bool rotateString(string s, string goal) {
        if (s.size() != goal.size())    return false;
        string doubled = s+s;
        if (doubled.find(goal) != string::npos){
            return true;
        }
        else    
            return false;
    }
};


//or in one line:

return s.size() == goal.size() &&
               (s + s).find(goal) != string::npos;
