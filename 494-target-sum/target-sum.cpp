class Solution {
public:

    int findTargetSumWays(vector<int>& nums, int target) {

        int total = accumulate(nums.begin(), nums.end(), 0);

        if(abs(target) > total)
            return 0;

        if((target + total) % 2)
            return 0;

        int req = (target + total) / 2;

        int n = nums.size();

        vector<vector<int>> dp(n + 1,vector<int>(req + 1, 0));

        dp[n][0] = 1;

        for(int i = n - 1; i >= 0; i--) {

            for(int sum = 0; sum <= req; sum++) {

                int notTake = dp[i + 1][sum];

                int take = 0;

                if(nums[i] <= sum)
                    take = dp[i + 1][sum - nums[i]];

                dp[i][sum] = take + notTake;
            }
        }

        return dp[0][req];
    }
};