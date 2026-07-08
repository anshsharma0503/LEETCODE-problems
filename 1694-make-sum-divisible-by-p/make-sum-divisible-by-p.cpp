class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        int n = nums.size();
        int ans = n;

        long long sum=0;
        for(int x: nums) 
            sum += x;

        int tar = sum % p;
        if(tar == 0) return 0;

        unordered_map<int,int> mp;
        mp[0] = -1;

        long long pref = 0;

        for(int i = 0; i < n ; i++){
            pref+= nums[i];

            int curr = ((pref % p) + p) % p;

            int prev = (curr - tar + p) % p;

            if(mp.find(prev) != mp.end())
                ans = min(ans , i - mp[prev]);

            mp[curr] = i; 
        }

        if(ans == n) return -1;

        return ans;
    }
};