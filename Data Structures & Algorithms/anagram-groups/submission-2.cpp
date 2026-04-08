class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>>ans;
        unordered_map<string, vector<string>>m;
        for(const string &s : strs){
            vector<int> count(26, 0);
            for(char c : s){
                count[c - 'a']++;
            }
            string key;
            for(int n : count){
                key += to_string(n) + "#";
            }
            m[key].push_back(s);
        }
        for(auto& [ _ , value ] : m){
            ans.push_back(move(value));
        }
        return ans;
    }
};
