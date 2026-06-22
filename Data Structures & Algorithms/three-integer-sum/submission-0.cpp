class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {

        vector<vector<int>> ans;
        int n = nums.size();

        sort(nums.begin(), nums.end());

        for (int i = 0; i < n; i++) {

            // Skip duplicate first elements
            if (i > 0 && nums[i] == nums[i - 1])
                continue;

            int start = i + 1;
            int end = n - 1;

            while (start < end) {

                int sum = nums[i] + nums[start] + nums[end];

                if (sum < 0) {
                    start++;
                }
                else if (sum > 0) {
                    end--;
                }
                else {
                    ans.push_back({nums[i], nums[start], nums[end]});

                    start++;
                    end--;

                    // Skip duplicates
                    while (start < end && nums[start] == nums[start - 1])
                        start++;

                    while (start < end && nums[end] == nums[end + 1])
                        end--;
                }
            }
        }

        return ans;
    }
};