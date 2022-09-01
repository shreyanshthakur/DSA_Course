class Solution {
public:
    int minimumDeletions(vector<int>& nums) {
        //step 1: search min and max, store their index
        int n = nums.size();
        int mini = INT_MAX;
        int maxi = INT_MIN;
        int minIndex = 0;
        int maxIndex = 0;
        for (int i = 0; i < n; i++) {
            if (nums[i] < mini) {
                mini = nums[i];
                minIndex = i+1;
            }
            if (nums[i] > maxi) {
                maxi = nums[i];
                maxIndex = i+1;
            }
        }
        //cout << minIndex << " " << maxIndex<< endl; //debug
        //step 3: apply maths return answer
        int LL = max (abs(minIndex - 0), abs(maxIndex - 0));
        int RR = max (abs(n - minIndex+1), abs(n - maxIndex+1));
        int LR = abs (abs(minIndex - 0) + abs(n - maxIndex+1));
        int RL = abs (abs(n - minIndex+1) + abs(0 - maxIndex));
        
        int ans = min (LL, min(RR, min(LR, RL)));
        return ans;
                      
    }
};