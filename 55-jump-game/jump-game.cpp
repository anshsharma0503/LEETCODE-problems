class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();

        if(n == 1) {
            if(nums[0] == 0) return true;
        }

        int curr = nums[0];

        for(int i = 0 ;i < n ; i++){
            curr--;
            if(curr < 0) return false;
            curr = max(curr , nums[i]);
        }


        return true;
    }
};