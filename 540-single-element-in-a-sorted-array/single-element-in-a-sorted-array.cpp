class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int lo = 0 , hi = nums.size() - 1;
        while(lo < hi){
            int mid = lo + (hi - lo) / 2;

            if(mid > 0 && nums[mid - 1] == nums[mid]){
                if(mid % 2 == 1) lo = mid + 1;
                else hi = mid;
            } else{
                if(mid % 2 == 0) lo = mid;
                else hi = mid  - 1;
            }
        }

        return nums[lo];
    }
};