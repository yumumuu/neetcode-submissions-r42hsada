class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> freq;

        // Step 1: frequency count
        for (int x : nums) {
            freq[x]++;
        }

        // Step 2: min heap of size k
        priority_queue<
            pair<int,int>,
            vector<pair<int,int>>,
            greater<pair<int,int>>
        > pq;

        for (const auto &[num, f] : freq) {
            pq.push({f, num});
            if (pq.size() > k) {
                pq.pop(); // remove smallest frequency
            }
        }

        // Step 3: extract elements
        vector<int> ans;
        ans.reserve(k);

        while (!pq.empty()) {
            ans.push_back(pq.top().second);
            pq.pop();
        }

        return ans;
    }
};