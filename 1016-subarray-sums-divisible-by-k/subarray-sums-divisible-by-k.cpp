class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int n = nums.size();
        int res= 0;
        int currSum = 0;

        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int i = 0 ;i < n ; i++){
            currSum += nums[i];
            int rem = ((currSum % k + k)) % k;

            if(mp.find(rem) != mp.end())
                res+= mp[rem];

            mp[rem]++;
        }

        return res;
    }
};