class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ans;
        int n = nums.size();
        if (n < 4) return ans;
        sort(nums.begin(), nums.end());
        
        for(int first = 0 ; first < n-3 ; first++) {
            
            long long int target_3 = (long long)target - (long long)nums[first];
            for (int second = first + 1; second < n-2; second++) {
                
                long long int target_2 = target_3 - (long long)nums[second];
                int third = second+1;
                int fourth = n-1; 
                while(third < fourth) {
                    
                    int curSum =  nums[third] + nums[fourth];
                    if(curSum > target_2) --fourth;
                    else if (curSum < target_2) ++third;
                    else {
                        vector<int> v = {nums[first], nums[second], nums[third], nums[fourth]};
                        ans.push_back(v);
                        while (third < fourth && nums[third] == v[2]) ++third;
                        while (third < fourth && nums[fourth] == v[3]) --fourth;
                    }
                }
                while (second < n-1 && nums[second] == nums[second+1]) ++second;
            }
            while (first < n-1 && nums[first] == nums[first+1]) ++first;
        }
        return ans;
    }
};