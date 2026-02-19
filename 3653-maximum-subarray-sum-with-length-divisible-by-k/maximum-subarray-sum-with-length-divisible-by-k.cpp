class Solution {
public:
    long long maxSubarraySum(vector<int>& nums, int k) {
        long long n = nums.size();
        vector<long long> pre(n + 1);
        pre[0] = 0;
        for(int i = 1;  i<= n; i++) pre[i] = pre[i - 1] + nums[i - 1];

        vector<long long> rem(k , INT_MAX);
        rem[0]=0;

        unordered_map<long long , long long> mp;
        long long ans = LLONG_MIN;
        for(int i = 1; i <= n ; i++){
            long long r = i % k;

            if(rem[r] != INT_MAX){
                ans = max(ans , pre[i] - rem[r]);
            }
            rem[r] = min(rem[r] , pre[i]);
        }
        return ans;
    }
};