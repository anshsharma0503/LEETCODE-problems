class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        int n = nums.size();

        vector<vector<long  long>> dp(n + 1 , vector<long long> (2 , 0));

        for(int i = n - 1; i >= 0 ; i--){
            long long notTake = dp[i + 1][1];
            long long take = nums[i] + dp[i + 1][0];
            dp[i][1] = max(take , notTake);

            notTake = dp[i  +1][0];
            take = dp[i + 1][1] - nums[i];

            dp[i][0] = max(take , notTake);
        }

        return dp[0][1];
    }
};