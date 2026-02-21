class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int lo = 0,hi = nums.size() - 1;

        int st = -1 , end = -1;

        while(lo <= hi){
            int mid = lo + (hi - lo) /2;

            if(nums[mid] == target){
                st = mid;
                hi = mid -1;
            } 
            else if(nums[mid] < target) lo = mid + 1;
            else hi = mid -1;
        }
        
        lo = 0 ; hi = nums.size() - 1;
        while(lo <= hi){
            int mid = lo + (hi - lo) /2;

            if(nums[mid] == target){
                end = mid;
                lo = mid + 1;
            } 
            else if(nums[mid] < target) lo = mid + 1;
            else hi = mid -1;
        }

        return {st , end};

    }
};