class Solution {
public:

    int atmost(vector<int>& nums, int k){
        if(k < 0) return 0;
        int l =0,r=0;
        int oneCnt=0;
        int res =0;
        while(r < nums.size()){
            if(nums[r] == 1) oneCnt++;

            while(oneCnt > k){
                if(nums[l] == 1) oneCnt--;
                l++;
            }
            res = res + (r - l + 1);
            r++;
        }

        return res;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        return atmost(nums , goal) - atmost(nums , goal -1);  
    }
};