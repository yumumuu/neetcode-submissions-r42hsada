class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int>m;
        for(int n : nums){
            m[n]++;
        }
        priority_queue<pair<int, int>> pq;
        for(const auto& [key, value] : m){
            pq.push({value, key});
        }
        vector<int> ans;
        ans.reserve(k);
        while(k--){
            ans.push_back(pq.top().second);
            pq.pop();
        }
        return ans;
    }
};
