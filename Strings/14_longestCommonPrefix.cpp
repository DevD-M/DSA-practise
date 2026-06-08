class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {


        for(int j =0; j< strs[0].size(); j++){
            for (int i =1; i < strs.size(); i++){
                if ( j >= strs[i].size()){
                    return strs[0].substr(0, j);
                }
                if (strs[i][j] != strs[0][j]){
                    return strs[0].substr(0, j);
                }
            }
        }
        return strs[0];
    }
};

//revise
