class Solution {
public:

    vector<int> dp;

    int f(int i , int n , vector<int>& arr, int k){
        if(i == arr.size())
            return 0;

        if(dp[i] != -1) return dp[i];

        int mx = 0 , ans= 0;
        for(int j = i ; j < min(n , i + k) ; j++){
            mx = max(mx, arr[j]);
            int len = j - i + 1;

            ans = max(ans , mx * len + f(j + 1 , n , arr , k));
        }

        return dp[i] = ans;
    }

    int maxSumAfterPartitioning(vector<int>& arr, int k) {
        dp.resize(arr.size() , -1);

        return f(0 , arr.size() ,  arr , k);
    }
};