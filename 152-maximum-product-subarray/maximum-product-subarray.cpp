class Solution {
public:
    int maxProduct(vector<int>& nums) {
        int curr = nums[0];
        int maxi=nums[0] ,mini= nums[0];
        int ans =nums[0];

        for(int i = 1 ; i < nums.size() ; i++){
            if(nums[i] < 0) swap(maxi , mini);
             
            mini = min(nums[i] , mini*nums[i]);
            maxi = max(nums[i] , maxi*nums[i]);

            ans = max(ans , maxi);
        }   

        return ans;
    }
};