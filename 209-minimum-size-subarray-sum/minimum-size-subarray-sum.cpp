class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int n = nums.size();
        int res = 1e9;

        int l = 0 , sum = 0;
        for(int r = 0; r < n ; r++){
            sum += nums[r];
            while(l <= r && sum >= target){
                sum -= nums[l];
                
                res = min(res , r - l + 1);
                l++;
            }
        }

        if(res != 1e9)
            return res;

        return 0;
    }
};