class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n , 1);
       

        vector<int> pre(n) , suff(n);
        pre[0] = nums[0];
        suff[n - 1] = nums[n - 1];

        for(int i = 1 ; i < n ; i++){
            pre[i] = nums[i] * pre[i - 1];
        }
        for(int i = n - 2 ; i >= 0 ; i--){
            suff[i] = nums[i] * suff[i + 1];
        }

        for(int i = 0 ; i < n ; i++){

            int left = (i == 0) ? 1 : pre[i - 1];
            int right = (i == n - 1) ? 1 : suff[i + 1];

            ans[i] = left * right;
        }

        return ans;
    }
};