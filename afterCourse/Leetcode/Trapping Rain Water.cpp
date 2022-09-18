class Solution {
public:
    int trap(vector<int>& height) {
        int left = 0, right = height.size()-1, leftmax = 0, rightmax = 0, ans = 0;
        while (left <= right) {
            if (height[left] <= height[right]) {
                if (leftmax <= height[left]) {
                    leftmax = height[left];
                }
                else {//leftmax > height[left]
                    ans += leftmax - height[left];
                }
                left++;
            }
            else {//height[left] > height[right]
                if (rightmax <= height[right]) {
                    rightmax = height[right];
                }
                else {
                    ans += rightmax - height[right];
                }
                right--;
            }
        }
        return ans;
    }
};