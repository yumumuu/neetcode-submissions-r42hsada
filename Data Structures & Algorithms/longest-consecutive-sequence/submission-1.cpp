class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> s(nums.begin(), nums.end());
        int longest = 0;

        for (int x : s) {
            // 只從「起點」開始
            if (!s.count(x - 1)) {
                int curr = x;
                int length = 1;

                // 一路往上找
                while (s.count(curr + 1)) {
                    curr++;
                    length++;
                }

                longest = max(longest, length);
            }
        }

        return longest;
    }
};