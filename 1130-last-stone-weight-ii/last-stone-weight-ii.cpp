class Solution {
public:

    vector<vector<int>> dp;

    int f(int i , int sum , int tar , vector<int>& stones){
        if(i == stones.size()) return sum;

        if(dp[i][tar] != -1) return dp[i][sum];

        int take = 0;
        if(sum + stones[i] <= tar) take = f(i + 1 , sum + stones[i] , tar , stones);

        int nottake = f(i + 1 , sum , tar , stones);

        return dp[i][sum] = max(take , nottake);
    }

    int lastStoneWeightII(vector<int>& stones) {
        int totalsum= 0;
        for(int x : stones) totalsum += x;

        int tar = totalsum / 2;
        dp.resize(stones.size() , vector<int> (tar + 1 , -1) );

        int s1 = f(0 , 0 , tar , stones);

        return totalsum - 2*s1;
    }
};