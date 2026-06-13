//using priority queue  tc = O(n + klogk)
class Solution {
public:
    string frequencySort(string s) {

        unordered_map<char, int> freq;

        for (int i = 0; i < s.size(); i++) {
            freq[s[i]]++;
        }

        priority_queue<pair<int, char>> pq;

        for (auto &it : freq) {
            pq.push({it.second, it.first});
        }

        string ans = "";

        while (!pq.empty()) {

            pair<int, char> curr = pq.top();
            pq.pop();

            ans += string(curr.first, curr.second);
        }

        return ans;
    }
};

//using bucket sort  tc = O(n)
class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char, int> freq;
        int n = s.size();
        for (int i =0; i <s.size(); i++){
            freq[s[i]]++;
        }
        vector<vector<char>> bucket(n+1);
        for (auto &it : freq){
            bucket[it.second].push_back(it.first);
        }
        string ans = "";
        for (int freq= n; freq >= 1; freq--){
            for (char ch :bucket[freq]){
                ans += string(freq, ch);
            }
        }
        return ans;
    }
};
