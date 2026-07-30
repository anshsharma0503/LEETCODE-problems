class Solution {
public:

vector<int> pre;
vector<vector<double>> dp;

    double f(int i , vector<int>& nums, int k){
        int n = nums.size();
        if(i == n && k== 0) return 0;

        if(i == n && k >0) return INT_MIN;
        if(i < n && k ==0) return INT_MIN;

        if(dp[i][k] != -1.0) return dp[i][k];

        double ans = INT_MIN;
        for(int j = i ; j <= n - k ; j++){
            int sum = pre[j + 1] - pre[i];
            int len = j - i + 1;
            double avg = (double)sum / len;
            
            ans = max(ans , avg+ f(j + 1 , nums , k - 1));
        }

        return dp[i][k] = ans;
    }

    double largestSumOfAverages(vector<int>& nums, int k) {
        double n = nums.size();
        pre.resize(nums.size() + 1 , -0);
        dp.resize(n, vector<double>(k + 1 , -1.0));

        for(int i = 1 ; i <= nums.size() ; i++){
            pre[i] = pre[i - 1] + nums[i - 1];
        }
        return f(0 , nums, k);
    }
};