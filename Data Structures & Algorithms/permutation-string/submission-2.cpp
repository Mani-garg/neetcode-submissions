class Solution {
public:
    bool checkInclusion(string s1, string s2) {
        int n = s1.size(), m = s2.size();

        if (n > m) return false;

        vector<int> freq1(26, 0), freq2(26, 0);

        // Frequency of s1
        for (char c : s1) {
            freq1[c - 'a']++;
        }

        // First window of size n in s2
        for (int i = 0; i < n; i++) {
            freq2[s2[i] - 'a']++;
        }

        if (freq1 == freq2) return true;

        // Sliding window
        for (int i = n; i < m; i++) {
            // Add new character
            freq2[s2[i] - 'a']++;

            // Remove old character
            freq2[s2[i - n] - 'a']--;

            if (freq1 == freq2)
                return true;
        }

        return false;
    }
};