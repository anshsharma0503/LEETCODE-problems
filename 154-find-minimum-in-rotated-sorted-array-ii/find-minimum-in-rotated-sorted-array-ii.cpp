class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        int lo = 0 , hi = n - 1;
        int mini = nums[0];

        while(lo <= hi){
            int mid = lo + (hi - lo) / 2;
            if(nums[lo] == nums[mid] && nums[mid] == nums[hi]){
                mini=min(mini,nums[lo]);
                lo++;
                hi--;
            }
            else if(nums[mid] >= nums[lo]){
                mini = min(mini , nums[lo]);
                lo = mid + 1;
            } else{
                mini = min(mini , nums[mid]);
                hi = mid - 1;
            }
        }

        return mini;
    }
};