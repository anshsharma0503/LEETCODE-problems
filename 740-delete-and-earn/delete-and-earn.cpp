class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int maxi = nums[0];
        for(int i = 1 ; i < nums.size(); i++){
            maxi = max(maxi , nums[i]);
        }

        vector<int> arr(maxi + 1 , 0);

        for(int x : nums){
            arr[x] += x;
        }

        vector<int> dp(maxi + 1 , 0);
        dp[1] = arr[1];

        for(int i = 2 ;i <= maxi ; i++){
            dp[i] = max(dp[i - 1] , arr[i] + dp[i - 2]);
        }

        return dp[maxi];
    }
};