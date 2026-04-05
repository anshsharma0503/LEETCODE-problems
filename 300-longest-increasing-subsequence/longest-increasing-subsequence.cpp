class Solution {
public:

    vector<vector<int>> dp;

    int f(int i  , int prev, vector<int>& nums){
        if(i == nums.size()) return 0;

        if(prev != -1){
            if(dp[i][prev] != -1) return dp[i][prev];
        }

        int notTake = f(i + 1  , prev, nums);
        
        int take = -1e9;
        if(prev == -1 || nums[i] > nums[prev]){
            take = 1 + f(i + 1 , i, nums);
        }

        if(prev != -1){
            return dp[i][prev] = max(take , notTake);
        }
        return max(take , notTake);
        
    }

    int lengthOfLIS(vector<int>& nums) {
        dp.resize(nums.size() , vector<int> (nums.size() ,-1));
        return f(0 , -1 , nums);
    }
};