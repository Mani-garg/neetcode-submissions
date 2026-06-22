class Solution {
public:
    int trap(vector<int>& height) {
        int start = 0;
        int end = height.size() - 1;

        int leftMax = 0, rightMax = 0;
        int water = 0;

        while (start < end) {
            if (height[start] < height[end]) {
                if (height[start] >= leftMax)
                    leftMax = height[start];
                else
                    water += leftMax - height[start];

                start++;
            }
            else {
                if (height[end] >= rightMax)
                    rightMax = height[end];
                else
                    water += rightMax - height[end];

                end--;
            }
        }

        return water;
    }
};