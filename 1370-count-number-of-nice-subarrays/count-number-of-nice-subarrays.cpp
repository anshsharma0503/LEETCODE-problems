class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        int ans = 0;

        vector<int> arr(n);
        for(int i = 0; i < n ; i++){
            if(nums[i] % 2 == 1) arr[i] = 1;
            else arr[i] = 0;
        }

        vector<int> pre(n);
        pre[0]=arr[0];

        for(int i = 1; i < n ; i++) pre[i] = pre[i - 1] + arr[i];

        unordered_map<int , int> freq;
        freq[0] = 1;

        for(int i = 0 ; i< nums.size() ; i++){
            int need = pre[i] - k;
            if(freq.find(need) != freq.end()) ans += freq[need];
            freq[pre[i]]++;
        }

        return ans;
    }
};