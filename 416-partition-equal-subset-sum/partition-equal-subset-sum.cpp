class Solution {
public:
     vector<vector<int>> dp;
    bool f(int i , int tar , vector<int>& nums){
        
        if(tar == 0) return true;
        if(tar < 0) return false;
        if(i >= nums.size()) return false;

        if(dp[i][tar] != -1) return dp[i][tar];

        bool take = f(i + 1 , tar - nums[i] , nums);
        bool nottake = f(i + 1 , tar , nums);

        return dp[i][tar] = take || nottake;
    }

    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(int x:nums) sum+= x;

        if(sum % 2 == 1) return false;

        dp.resize(nums.size() , vector<int> ((sum / 2 )+1 , -1));
        return f(0 , sum / 2 , nums);


    }
};