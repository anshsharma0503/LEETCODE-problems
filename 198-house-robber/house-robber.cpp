class Solution {
public:

    vector<int> dp;

    int f(int i , vector<int>& nums){
        int n = nums.size();
        if(i == nums.size() - 2) return max(nums[n-2] , nums[n - 1]);
        if(dp[i] != -1) return dp[i];
        if(i == n - 1) return nums[n - 1];

        return dp[i] = max(f(i + 1, nums) , nums[i] + f(i + 2 , nums));
    }

    int rob(vector<int>& nums) {
        dp.resize(105 , -1);
        return f(0 , nums);
    }
};