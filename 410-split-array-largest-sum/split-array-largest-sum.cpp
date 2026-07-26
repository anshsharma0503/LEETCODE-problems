class Solution {
public:

    bool isPossible(int mid , vector<int>& nums, int k){
        int div = 1;

        int sum=0;
        for(int x : nums){
            sum += x;

            if(sum > mid){
                div++;
                sum = x;
            }
        }

        return div <= k;
    }

    int splitArray(vector<int>& nums, int k) {
        int n = nums.size();
        int lo = nums[0];
        int hi = 0;

        for (int x : nums) {
            lo = max(lo, x);
            hi += x;
        }

        while(lo < hi){
            long long mid = lo + (hi - lo) / 2;

            if(isPossible(mid , nums , k))
                    hi = mid;
                    
            else lo = mid + 1;
        } 

        return lo;
    }
};