class Solution {
public:

    vector<vector<int>> dp;

    bool f(int i , int sum , vector<int>& nums){
        if(sum == 0) return true;
        if(i >= nums.size()) return false;   
        if(dp[i][sum] != -1) return dp[i][sum];

        bool take = false;
        if(nums[i] <= sum) take = f(i + 1 , sum - nums[i] , nums);
        bool notTake = f(i + 1 , sum , nums);

        return dp[i][sum] = take || notTake;
    }

    bool canPartition(vector<int>& nums) {
        int n = nums.size();

        int sum = 0;
        for(int i = 0 ; i < n ; i++) sum += nums[i];

        if(sum % 2 == 1) return 0;

        int tar = sum / 2;

        dp.resize(n , vector<int> (tar + 1 , -1));

        return f(0 , sum / 2, nums);
    }
};