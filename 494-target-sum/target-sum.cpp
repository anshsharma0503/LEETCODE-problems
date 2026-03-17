class Solution {
public:

    int ans;

    void f(int i , int s , int tar , vector<int>& nums){
        if (s > tar) return;
        if (i == nums.size()) {
            if (s == tar) ans++;
                return;
        }

        f(i + 1 , s , tar , nums);
        f(i + 1 , s + nums[i] , tar , nums);
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0;
        for(int x : nums) sum += x;

        int tar = (sum + target) / 2;

        if ((sum + target) % 2 != 0) return 0;
        ans =0;

        f(0 , 0 , tar ,nums);
        return ans;
    }
};