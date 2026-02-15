class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
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
            int need = pre[i] - k;

            if(mp.find(need) != mp.end()) res += mp[need];
            mp[pre[i]]++;
        }

        return res;
    }
};