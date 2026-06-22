class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> mp;
        int start = 0;
        int maxi = 0;

        for (int end = 0; end < s.length(); end++) {

            while (mp[s[end]] > 0) {
                mp[s[start]]--;
                start++;
            }

            mp[s[end]]++;
            maxi = max(maxi, end - start + 1);
        }

        return maxi;
    }
};