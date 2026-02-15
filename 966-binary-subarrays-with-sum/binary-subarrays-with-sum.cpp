class Solution {
public:
    int numSubarraysWithSum(vector<int>& nums, int goal) {
        int n = nums.size();
        
        vector<int> pre(n);
        pre[0] = nums[0];
        for(int i = 1 ; i < n;  i++){
            pre[i] = pre[i -1] + nums[i];
        }

        unordered_map<int , int> mp;
        mp[0]++;

        int res = 0;

        for(int i = 0 ;i < n; i++){
            int need = pre[i] - goal;

            if(mp.find(need) != mp.end()) res += mp[need];
            mp[pre[i]]++;
        }

        return res;
    }
};