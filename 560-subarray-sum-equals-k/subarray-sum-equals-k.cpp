class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int currSum = 0;
        int res =0 ;

        unordered_map<int , int> freq;
        freq[0]++;

        for(int i =0; i < n ; i++){
            currSum += nums[i];

            if(freq.find(currSum - k) != freq.end()) 
                res += freq[currSum - k];

            freq[currSum]++;
        }

        return res;
    }
};