class Solution {
public:
    int atMost(vector<int>& nums, int k){
        if(k < 0) return 0;
        int l=0 , oddcnt = 0;
        int res =0;
        for(int r = 0 ; r < nums.size() ; r++){
            if(nums[r] % 2 == 1) oddcnt++;

            while(oddcnt > k){
                if(nums[l] % 2 == 1) oddcnt--;
                l++;
            }
            res = res + (r - l + 1);

        }

        return res;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        return atMost(nums , k) - atMost(nums , k - 1);
    }
};