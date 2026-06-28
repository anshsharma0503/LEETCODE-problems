class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        int kk = 0;

        int l = 0; 
        for(int r = 0; r < n ; r++){
            if(nums[r] == 0) kk++;
            while(kk > k){
                if(nums[l] == 0) kk--;
                l++;
            }
            res = max(res , r - l + 1);
        }

        return res;
    }
};