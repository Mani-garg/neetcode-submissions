class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int,int> mp;

        for(int x : nums) {
            mp[x]++;
        }

        vector<pair<int,int>> freq;

        for(auto it : mp) {
            freq.push_back({it.second, it.first});
        }

        sort(freq.begin(), freq.end(), greater<pair<int,int>>());

        vector<int> ans;

        for(int i = 0; i < k; i++) {
            ans.push_back(freq[i].second);
        }

        return ans;
    }
};